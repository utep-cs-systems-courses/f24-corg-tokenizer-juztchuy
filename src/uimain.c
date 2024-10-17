#include <stdio.h>
#include <string.h>
#include "history.c"  
#include "tokenizer.h" 


#define MAX_INPUT_SIZE 256

int main() {
  char input[MAX_INPUT_SIZE];  // Buffer to store the user input
  List *history = init_history();  

  //  initial prompt
  printf("$ ");

  // Read input from the user
  while (fgets(input, sizeof(input), stdin)) {
    // Remove newline character from input, if any
    input[strcspn(input, "\n")] = '\0';

    // Check if the input is "exit" to terminate the program
    if (strcmp(input, "exit") == 0) {
      printf("Exiting the program\n");
      break; 
    }

    // Check if the input is "history" to print the history list
    if (strcmp(input, "history") == 0) {
      printf("History:\n");
      print_history(history); // Display  history items
      printf("$ ");
      continue; // Skip the rest of the loop to prompt again
    }

    // Check if input is a history recall command (e.g., !3)
    if (input[0] == '!' && strlen(input) > 1) {
      int id = atoi(&input[1]);  // Extract the history ID from the input
      char *historyItem = get_history(history, id);  // Get the history item by ID

      if (historyItem) {
	printf("Recalled from history: %s\n", historyItem);
	strcpy(input, historyItem);  // Use the recalled history item as the new input
      } else {
	printf("No history item found with ID %d.\n", id);
	printf("$ ");
	continue;
      }
    }

    // Add the valid input to the history
    
    if (strlen(input) > 0) {
      add_history(history, input);
      
    }
    

    // Tokenize the input
    char **tokens = tokenize(input);
    
    // Echo the tokens back to the user
    printf("Tokens:\n");
    print_tokens(tokens);

    // Free the tokenized strings
    free_tokens(tokens);

    // Display the prompt again
    printf("$ ");
  }

  // Free the history list at the end
  free_history(history);

  return 0;
}
