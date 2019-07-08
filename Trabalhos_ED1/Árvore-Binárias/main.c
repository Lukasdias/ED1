#include <stdio.h>
#include "tree.h"
#include <stdlib.h>

int cmp(void *key, void* data){
  int *a;
  int *b;
  a = (int*)key;
  b = (int*)data;
  if (b < a){
    return -1;
  } else if(b > a){
    return 1;
  } else {
    return 0;
  }
}

void visit(void *data){
  int aux;
  if (data != NULL){
    aux = (int)data;
    printf("%d ", aux);
  }
}


int main(int argc, char const *argv[]) {

  int menuOption;
  int data;

  void* query = NULL;
  void* aux = NULL;

  Node *root = NULL;

  do{
    system("cls");
    printf("%s\n", "*************************");
    printf("%s\n", " [1] Criar Arvore Binaria ");
    printf("%s\n", " [2] Inserir Elemento");
    printf("%s\n", " [3] Procurar Elemento");
    printf("%s\n", " [4] Remover Elemento");
    printf("%s\n", " [5] Destruir Arvore");
    printf("%s\n", " [6] Sair");
    printf("%s\n", "*************************");
    if(root!=NULL){
      int size = BSTreeContaNo(root);
      if(size>1){
        printf("Arvore em Pos-Ordem:\t");
        treePosOrdem(root, visit);
        putchar('\n');
        printf("Arvore em Pre-Ordem:\t");
        treePreOrdem(root, visit);
        putchar('\n');
        printf("Arvore em Simetria :\t");
        treeSimetria(root, visit);
        putchar('\n');
      }
    }
    printf("%s\n", "Sua escolha: ");
    scanf("%d", &menuOption);

    switch (menuOption) {

      case 1:
        root = BSTreeCreate();
        if (root != NULL){
          printf("%s\n", "Arvore criada com sucesso");
          system("pause");
        } else {
          printf("%s\n", "Ops, Arvore n pode ser criada");
          system("pause");
        }

        break;
      case 2:
        printf("%s\n", "Insira um inteiro para ser adicionado");
        scanf("%d", &data);
        root = BSTreeInsert(root, (void*)data, (void*)data, cmp);
        if (root != NULL){
          printf("%s\n", "Elemento inserido com sucesso");
          system("pause");
        } else {
          printf("%s\n", "Ops, Elemento n foi inserido");
          system("pause");
        }
        break;
      case 3:
        printf("%s\n", "Insira o elemento que voce deseja procurar: ");
        scanf("%d", &data);
        query = BSTreeQuery(root, (void*)data, cmp);
        if (query!=NULL){
          printf("%d foi removido", data);
          system("pause");
        } else {
          system("pause");
          printf("%s\n", "Nao foi encontrado");

        }
        break;
      case 4:
        printf("%s\n", "Insira o elemnto que deseja deletar: ");
        scanf("%d", &data);
        root = BSTreeRemove(root, (void*)data, cmp);
        if(root!=NULL){
          printf("Numero %d encontrado e removido\n", data);
        }else{
          printf("o numero buscado n pode ser achado\n");
        }
        system("pause");
        break;
      case 5:
        if (BSTreeDestroy(root) == true){
          printf("%s\n", "A arvore foi destruida");
        } else {
          printf("%s\n", "A arvore nao pode ser destruida ainda");
        }
        system("pause");
        break;
      default:
        break;
    }

  }while(menuOption != 6);

  return 0;
}