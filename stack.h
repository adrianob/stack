#ifndef STACK
#define STACK

typedef enum _bool {FALSE, TRUE} bool;
typedef bool (*iterator)(void *);

typedef struct _list_node {
  void *data;
  struct _list_node *next;
} LIST_NODE;

LIST_NODE * initialize(void);
bool is_empty(LIST_NODE *head);
void push(LIST_NODE **head_ref, void *element);
void * pop(LIST_NODE **head_ref);
void * top(LIST_NODE *head);
void for_each(LIST_NODE **head_ref, iterator iterator);
void destroy(LIST_NODE **head_ref);
int list_size(LIST_NODE *head);

#endif
