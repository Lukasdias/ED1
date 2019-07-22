#include <stdio.h>
#include "tree.h"
#include <stdlib.h>
#include "pessoa.h"

Tnode *ABPRemoveUmFilho(Tnode *root, void *key, int(*cmp)(void*, void*));
int CheckBin(Tnode *t);
int CheckSearchTree(Tnode *t, int(*cmp)(void*, void*));

void visit(void *data){
  int *aux;
  if (data != NULL){
    aux = (int*)data;
    printf("%d ", aux);
  }
}

int compare(void *key, void* data){
  int *a;
  int *b;
  a = (int*)key;
  b = (int*)data;
  if ( a > b){
    return 1;
  } else if(a < b){
    return -1;
  } else {
    return 0;
  }
}

int main(int argc, char const *argv[]) {

  int menuOption = 0;
  int data;

  void* query = NULL;
  void* aux = NULL;
  Tnode *remove = NULL;
  Tnode *root = NULL;
  int check, check2;
  
  do{
    system("cls"); 
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
        printf("Numero de nos: %d\n", nos-1);
        printf("Numero de nos maiores que 10: %d\n", numMaiores(root, 10, visit, compare));
        printf("Altura da arvore: %d\n", TnodeAltura(root));
        check = CheckBin(root);
        // check2 = CheckSearchTree(root, compare);

        if(check == true){
          printf("E uma arvore binaria completa\n");
        }else{
          printf("Nao e uma arvore binaria completa\n");
        }

        // if(check2 == true){
        //   printf("E uma arvore binaria de pesquisa\n");
        // }else{
        //   printf("Nao e uma arvore binaria de pesquisa\n");
        // }

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
        // insertPessoa(root);
        ABPInsert(root, (void *)40, (void*)40, compare);
        ABPInsert(root, (void *)5, (void*)5, compare);
        ABPInsert(root, (void *)100, (void*)100, compare);
        ABPInsert(root, (void *)1, (void*)1, compare);
        ABPInsert(root, (void *)6, (void*)6, compare);
        system("pause");
        break;
      case 3:
        // searchPessoa(root);
        break;
      case 4:
        ABPRemoveUmFilho(root, (void*)5, compare);        
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
  }while(menuOption!=8);

  return 0;
}

Tnode *ABPRemoveUmFilho(Tnode *root, void *key, int(*cmp)(void*, void*)){
  Tnode *aux;
  void *data;
  if(root!=NULL){
    int stat;
    stat = cmp(key, root->data);
    if(stat == 1){
      root->right = ABPRemoveUmFilho(root->right, key, cmp);
    }else if(stat == -1){
      root->left = ABPRemoveUmFilho(root->left, key, cmp);
    }else{
      if(root->left != NULL && root->right == NULL){
        aux = root->left;
        free(root);
        return aux;
      }else{
        printf("tem mais ou nao tem nenhum filho\n");
        return NULL;
      }
    }
  }
  return NULL;
}

int CheckBin(Tnode *t){
  int l, r;
  if(t!=NULL){
    if(t->right!=NULL && t->left != NULL){
      l = CheckBin(t->left);
      r = CheckBin(t->right);
    }else if(t->right == NULL && t->left == NULL){
      return true;
    }else{
      return false;
    }
  }
}

int CheckSearchTree(Tnode *t, int(*cmp)(void*, void*) ){
  int l, r;
  int cmpL, cmpR;
  int statL, statR;
  if(t!=NULL){
    statL = cmp(t->left->data, t->data);
    statR = cmp(t->right->data, t->data);
    if(statR == 1 && statL == -1){
      cmpL = CheckSearchTree(t->left, cmp);
      cmpR = CheckSearchTree(t->right, cmp);
    }else{
      return false;
    }
    
  }
  return false;

}