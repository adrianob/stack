#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "stack.h"

void random_list(STACK_T **head_ref, int size);
bool produto_iterator(void *data);
void menu(void);
struct produto * le_produto(STACK_T **head);

struct produto{
  int codigo;
  float preco;
};

void random_list(STACK_T **head_ref, int size){
  int i;
  struct produto *prod;
  for (i = 0; i < size; i++) {
    prod = (struct produto *) malloc(sizeof(struct produto));
    prod->codigo = i;
    prod->preco = rand();
    push(head_ref, prod);
  }

}

bool produto_iterator(void *data){
  if (data) {
    printf("codigo: %d preco: %.2f\n", ((struct produto*)data)->codigo, ((struct produto *)data)->preco);
  }
  return TRUE;
}

void menu(void){
  printf("1. insere novo produto\n");
  printf("2. lista todos produtos\n");
  printf("3. destroi a lista\n");
  printf("4. imprimir tamanho da lista\n");
  printf("5. criar lista aleatoria\n");
  printf("6. pop\n");
  printf("7. top\n");
  printf("8. sair\n");
}

struct produto * le_produto(STACK_T **head){
  struct produto *prod;
  prod = (struct produto *)malloc(sizeof(struct produto));
  printf("Informe o codigo:\n");
  scanf("%d", &prod->codigo);
  printf("Informe o preco:\n");
  scanf("%f", &prod->preco);
  return prod;
}

int main(void)
{
  srand(time(NULL));
  int option, cod;
  struct produto * prod;
  iterator iterator;

  STACK_T *produtos = initialize();
  iterator = produto_iterator;
  menu();

  while(TRUE){
    scanf("%d", &option);
    switch (option) {
      case 1:
        prod = le_produto(&produtos);
        push(&produtos, prod);
        break;
      case 2:
        for_each(&produtos, iterator);
        break;
      case 3:
        destroy(&produtos);
        break;
      case 4:
        printf("%d elementos\n", list_size(produtos));
        break;
      case 5:
        printf("quantidade de elementos:\n");
        scanf("%d", &cod);
        random_list(&produtos, cod);
        break;
      case 6:
        produto_iterator(pop(&produtos));
        break;
      case 7:
        produto_iterator(top(produtos));
        break;
      case 8:
        exit(1);
      default:
        printf("opcao invalida\n");
    }
    printf("\n");
    menu();
  }

}
