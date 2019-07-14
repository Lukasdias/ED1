#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
#include "pessoa.h"

void visit(void *data){
  Pessoa *aux;
  if (data != NULL){
    aux = (Pessoa*)data;
    printf("%d ", aux->idade);
  }
}


int main(int argc, char const *argv[]) {

  int menuOption = 0;
  int data;

  void* query = NULL;
  void* aux = NULL;
  Tnode *remove = NULL;

  Tnode *root = NULL;

  
  while(menuOption!=8){
    // system("cls"); 
    printf("%s\n", "*************************");
    printf("%s\n", " [1] Criar Arvore Binaria ");
    printf("%s\n", " [2] Inserir Elemento");
    printf("%s\n", " [3] Procurar Elemento");
    printf("%s\n", " [4] Remover Elemento");
    printf("%s\n", " [5] Destruir Arvore");
    printf("%s\n", " [8] Sair");
    printf("%s\n", "*************************");
    
    if(root!=NULL){
      int size = ABPContaNo(root);
        printf("Arvore organizada de acordo com a idade dos elementos!\n");
        printf("Arvore em Pos-Ordem:\t");
        treePosOrdem(root, visit);
        putchar('\n');
        printf("Arvore em Pre-Ordem:\t");
        treePreOrdem(root, visit);
        putchar('\n');
        printf("Arvore em Simetria :\t");
        treeSimetria(root, visit);
        putchar('\n');
        int nos = ABPContaNo(root);
        printf("Numero de nos: %d", nos-1);
        putchar('\n');
    }

    printf("Sua escolha: ");
    scanf("%d", &menuOption);

    switch (menuOption) {
      case 1:
        if(root == NULL){
          root = ABPCreate();
        }
        if (root != NULL){
          printf("%s\n", "Arvore criada com sucesso");
          system("pause");
        } else {
          printf("%s\n", "Ops, Arvore n pode ser criada");
          system("pause");
        }
        break;
      case 2:
        insertPessoa(root);
        break;
      case 3:
        searchPessoa(root);
        break;
      case 4:
        removePessoa(root);        
        break;
      case 5:
        if (ABPDestroy(root) == true){
          printf("%s\n", "A arvore foi destruida");
        } else {
          printf("%s\n", "A arvore nao pode ser destruida ainda");
        }
        system("pause");
        break;
      case 6:
        system("pause");
        break;
      default:
        break;
    }
  }

  return 0;
}