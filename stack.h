#ifndef STACK
#define STACK

typedef enum _bool {FALSE, TRUE} bool;
typedef bool (*iterator)(void *);

typedef struct _stack {
  void *data;
  struct _stack *next;
} STACK_T;

STACK_T * initialize(void);
bool is_empty(STACK_T *head);
void push(STACK_T **head_ref, void *element);
void * pop(STACK_T **head_ref);
void * top(STACK_T *head);
void for_each(STACK_T **head_ref, iterator iterator);
void destroy(STACK_T **head_ref);
int list_size(STACK_T *head);

#endif
