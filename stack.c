#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

LIST_NODE * initialize(void){
  return NULL;
}

bool is_empty(LIST_NODE *head){
  return head == NULL;
}

void * top(LIST_NODE *head){
  return head->data;
}

void * pop(LIST_NODE **head_ref){
  LIST_NODE *node = *head_ref;
  if (!is_empty(node)) {
    *head_ref = node->next;
  }
  return (node) ? node->data : NULL;
}

void push(LIST_NODE **head_ref, void *element){
  LIST_NODE *node = (LIST_NODE *) malloc(sizeof(LIST_NODE));
  node->data = element;
  node->next = *head_ref;

  *head_ref = node;
}

void for_each(LIST_NODE **head_ref, iterator iterator){
  LIST_NODE **node = head_ref;
  while(!is_empty(*node)){
    iterator((*node)->data);
    pop(node);
  }
}

void destroy(LIST_NODE **head_ref){
  LIST_NODE *current = *head_ref;
  LIST_NODE *next;

  while(current){
    next = current->next;
    free(current->data);
    free(current);
    current = next;
  }
  *head_ref = NULL;
}

int list_size(LIST_NODE *head){
  unsigned int i = 0;
  LIST_NODE *node = head;
  while(node){
    i++;
    node = node->next;
  }
  return i;
}
