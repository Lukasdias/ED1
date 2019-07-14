#define _PESSOA_C_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pessoa.h"

int cmp(void *key, void* data){
  int *a;
  Pessoa *b;
  a = (int*)key;
  b = (Pessoa*)data;
  if ( a > &b->idade){
    return 1;
  } else if(a < &b->idade){
    return -1;
  } else {
    return 0;
  }
}


int searchPessoa(Tnode *t){
    int aux_idade;
    Pessoa *aux;
    if(t!=NULL) {
        printf("Informe a idade da pessoa a ser buscada: ");
        fflush(stdin);
        scanf("%d", (aux_idade));
        fflush(stdin);
        aux = (Pessoa *)ABPQuery(t, (void*)aux_idade, cmp);
        if (aux != NULL){
            printf("================================================================================\n");
            printf("Nome: %s\n", aux->nome);
            printf("CPF de %s: %s\n", aux->nome, aux->cpf);
            printf("Idade de %s: %d\n", aux->nome, aux->idade);
            printf("Numero de filhos de %s: %d\n", aux->nome, aux->numFilhos);
            printf("Salario de %s: %.2f\n", aux->nome, aux->salario);
            printf("================================================================================\n");
            system("PAUSE");
            return true;
        }
        else {
            printf("idade %s nao encontrado no Lista\n", aux_idade);
            system("PAUSE");
            return false;
        }
    }
    printf("Lista n existe!!\n");
    system("PAUSE");
    return false;
}

int insertPessoa(Tnode *t){
    if(t!=NULL) {
        Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));
        if (p != NULL) {
            printf("Informe o nome da pessoa: ");
            fflush(stdin);
            scanf("%s", (p->nome));
            fflush(stdin);
            printf("Informe o CPF da pessoa: ");
            fflush(stdin);
            scanf("%s", (p->cpf));
            fflush(stdin);
            printf("Informe o salario de %s: ", p->nome);
            scanf("%lf", &(p->salario));
            printf("Informe o numero de filhos de %s: ", p->nome);
            scanf("%d", &(p->numFilhos));
            printf("Informe a idade de %s: ", p->nome);
            scanf("%d", &(p->idade));
            ABPInsert(t, (void*)p, (void*)p, cmp);
            printf("Pessoa inserida com sucesso\n");
            system("PAUSE");
            return true;
        }
    }
    printf("O Lista nao existe!!!\n");
    system("PAUSE");
    return false;
}

int removePessoa(Tnode *t){
    int aux_idade;
    Tnode *aux;
    if(t!=NULL){
        printf("Informe o nome da pessoa a ser buscada: ");
        fflush(stdin);
        scanf("%d", aux_idade);
        fflush(stdin);
        
        aux = ABPRemove(t, (void*)aux_idade, cmp);
        if (aux != NULL){
            printf("================================================================================\n");
            printf("Pessoa chamada %s foi removida do Lista!!!\n", aux_idade);
            printf("===========================T=====================================================\n");
            system("PAUSE");
            return true;
        }
        else {
            printf("%s nao encontrado no Lista\n", aux_idade);
            system("PAUSE");
            return false;
        }
    }
    printf("Lista n existe!!!\n");
    system("pause");
    return false;
}