#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"


// Initialize the linked list to keep the history.
List* init_history() {
  List *list = (List *)malloc(sizeof(List)); // Allocate memory for the list
  if (list != NULL) {
    list->root = NULL; // Initialize the root to NULL (empty list)
  }
  return list;
}
// Add a history item to the end of the list.
void add_history(List *list, char *str) {
  Item *newItem = (Item *)malloc(sizeof(Item)); // Allocate memory for the new node
  if (newItem == NULL) {
    printf("Memory allocation failed.\n");
    return;
  }

  newItem->str = strdup(str); // Copy the input string to store in the new node
  newItem->next = NULL; // The new node will be added at the end, so next is NULL

  // Determine the ID for the new item
  int id = 1;
  Item *current = list->root;
  if (current == NULL) {
    list->root = newItem; // If the list is empty, set newItem as the root
  } else {
    while (current->next != NULL) {
      current = current->next;
      id++;
    }
    current->next = newItem; // Add the new item to the end of the list
    id++;
  }
  newItem->id = id; // Assign the ID to the new item
}
// Retrieve the string stored in the node where Item->id == id.
char *get_history(List *list, int id) {
  Item *current = list->root;
  while (current != NULL) {
    if (current->id == id) {
      return current->str; // Return the string if the id matches
    }
    current = current->next;
  }
  return NULL; // Return NULL if no matching id is found
}

// Print the entire contents of the list.
void print_history(List *list) {
  Item *current = list->root;
  if (current == NULL) {
    printf("No history available.\n");
  } else {
    while (current != NULL) {
      printf("%d: %s\n", current->id, current->str); // Print the id and the string
      current = current->next;
    }
  }
}

// Free the history list and the strings it references.
void free_history(List *list) {
  Item *current = list->root;
  while (current != NULL) {
    Item *temp = current;
    current = current->next;
    free(temp->str); // Free the string inside each node
    free(temp); // Free the node itself
  }
  free(list); // Free the list structure itself
}
