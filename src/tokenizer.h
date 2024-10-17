#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  return( c == ' ' || c == '\t');
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  return !space_char(c);
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str)
{
  while (*str && space_char(*str)) {
    str++; // Move to the next character until we find a non-space character.
  }
  return (*str) ? str : NULL; // Return NULL if no tokens found.
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token)
{
  while (*token && non_space_char(*token)) {
    token++; // Move to the next character until we find a space or terminator.
  }
  return token; // Return the pointer to the terminator character.
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str)
{
  int count = 0;
  char *token = token_start(str);
  while (token) {
    count++; // Count this token.
    token = token_terminator(token); // Move to the end of this token.
    token = token_start(token); // Find the next token.
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *newStr = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the new string (+1 for null terminator).
  if (!newStr) {
    return NULL; // Handle memory allocation failure.
  }
  strncpy(newStr, inStr, len); // Copy <len> characters.
  newStr[len] = '\0'; // Null-terminate the new string.
  return newStr;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str)
{
  // First, we duplicate the input string so as not to modify the original
  char* str_copy = strdup(str);

  // Get the number of tokens
  int numTokens = count_tokens(str_copy);

  // Allocate memory for token pointers
  char** tokens = (char**)malloc((numTokens + 1) * sizeof(char*));
  if (!tokens) {
    free(str_copy); // Free memory in case of failure
    return NULL;
  }

  // Start tokenizing the string
  char* token = strtok(str, " "); // Get the first token
  int index = 0;
  while (token != NULL && index < numTokens) {
    tokens[index] = copy_str(token, strlen(token)); // Copy the token
    index++;
    token = strtok(NULL, " "); // Get the next token
  }
  tokens[index] = NULL; // Null-terminate the array of tokens

  // Clean up
  free(str_copy);
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  for(int i = 0; tokens[i] != NULL; i++)
    {
      printf("tokens[%d]: %s\n", i, tokens[i]);
    }
}
/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  for(int i = 0; tokens[i] != NULL; i++)
    {
      free(tokens[i]);
    }
  free(tokens);
}

#endif
