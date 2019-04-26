#define _PESSOA_C_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pessoa.h"

int cmpCpfPessoa(void *a, void *b){
  char *auxA;
  Pessoa *auxB;

  auxA = (char *)a;
  auxB = (Pessoa *)b;

  if (strcmp(auxA, auxB->cpf) == 0){
    return TRUE;
  } 
  else {
    return FALSE;
  }
}

int cmpNomePessoa(void *a, void *b){
  char *auxA;
  Pessoa *auxB;

  auxA = (char *)a;
  auxB = (Pessoa *)b;

  if (strcmp(auxA, auxB->nome) == 0){
    return TRUE;
  } 
  else {
    return FALSE;
  }
}

int searchCpf(Cofo *c){

    char aux_cpf[12];
    Pessoa *aux_P;
    if(c!=NULL && c->nelm>0){
        printf("Informe o CPF da pessoa a ser buscada: ");
        fflush(stdin);
        scanf("%[^\n]s", &aux_cpf);
        fflush(stdin);
        aux_P = (Pessoa *)cofQuery(c, (void *)aux_cpf, cmpCpfPessoa);
        if (aux_P != NULL){
            printf("=================================================================================\n");
            printf("Nome: %s\n", aux_P->nome);
            printf("CPF de %s: %s\n", aux_P->nome, aux_P->cpf);
            printf("Idade de %s: %d\n", aux_P->nome, aux_P->idade);
            printf("Numero de filhos de %s: %d\n", aux_P->nome, aux_P->numFilhos);
            printf("Salario de %s: %.2f\n", aux_P->nome, aux_P->salario);
            printf("================================================================================\n");
            system("PAUSE");
            return TRUE;
        }
        else {
            printf("Cpf = %s nao encontrado no cofo\n", aux_cpf);
            system("PAUSE");
            return FALSE;
        }
    }
    printf("COFO VAZIO!!!\n");
    system("PAUSE");
    return FALSE;
}

int searchName(Cofo *c){
    char aux_nome[30];
    Pessoa *aux_P;

    if(c!=NULL && c->nelm>0) {
        printf("Informe o nome da pessoa a ser buscada: ");
        fflush(stdin);
        scanf("%[^\n]s", &aux_nome);
        fflush(stdin);
        aux_P = (Pessoa *)cofQuery(c, (void *)aux_nome, cmpNomePessoa);
        if (aux_P != NULL){
            printf("================================================================================\n");
            printf("Nome: %s\n", aux_P->nome);
            printf("CPF de %s: %s\n", aux_P->nome, aux_P->cpf);
            printf("Idade de %s: %d\n", aux_P->nome, aux_P->idade);
            printf("Numero de filhos de %s: %d\n", aux_P->nome, aux_P->numFilhos);
            printf("Salario de %s: %.2f\n", aux_P->nome, aux_P->salario);
            printf("================================================================================\n");
            system("PAUSE");
            return TRUE;
        }
        else {
            printf("%s nao encontrado no cofo\n", aux_nome);
            system("PAUSE");
            return FALSE;
        } 
    }
    printf("COFO VAZIO!!!\n");
    system("PAUSE");
    return FALSE;
}

int removeViaCpf(Cofo *c){
    char aux_cpf[12];
    Pessoa *aux_P;
    if(c!=NULL && c->nelm>0){
        printf("Informe o CPF da pessoa a ser buscada: ");
        fflush(stdin);
        scanf("%[^\n]s", &(aux_cpf));
        fflush(stdin);
        aux_P = (Pessoa *)cofRemove(c, (void *)aux_cpf, cmpCpfPessoa);
        if (aux_P != NULL){
            printf("================================================================================\n");
            printf("Pessoa com o CPF = %s foi encontrada e removida do cofo!!!\n", aux_cpf);
            printf("================================================================================\n");
            system("PAUSE");
            return TRUE;
        }
        else {
            printf("Cpf = %s nao encontrado no cofo\n", aux_cpf);
            system("PAUSE");
            return FALSE;
        } 
    }
    printf("Cofo Vazio!!!\n");
    return FALSE;
}

int removeViaName(Cofo *c){
    char aux_nome[30];
    Pessoa *aux_P;
    if(c!=NULL && c->nelm>0){
        printf("Informe o nome da pessoa a ser buscada: ");
        fflush(stdin);
        scanf("%[^\n]s", &(aux_nome));
        fflush(stdin);
        aux_P = (Pessoa *)cofRemove(c, (void *)aux_nome, cmpNomePessoa);
        if (aux_P != NULL){
            printf("================================================================================\n");
            printf("Pessoa chamada %s foi removida do cofo!!!\n", aux_nome);
            printf("================================================================================\n");
            system("PAUSE");
            return TRUE;
        }
        else {
            printf("%s nao encontrado no cofo\n", aux_nome);
            system("PAUSE");
            return FALSE;
        } 
    }
    printf("Cofo Vazio!!!\n");
    return FALSE;
}

int insertPessoa(Cofo *c){        
    if(c!=NULL) {
        Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));
        if (p != NULL) {
            printf("Informe o nome da pessoa: ");
            fflush(stdin);
            scanf("%[^\n]s", (p->nome));
            fflush(stdin);
            printf("Informe o CPF da pessoa: ");
            fflush(stdin);
            scanf("%[^\n]s", (p->cpf));
            fflush(stdin);
            printf("Informe o salario de %s: ", p->nome);
            scanf("%lf", &(p->salario));
            printf("Informe o numero de filhos de %s: ", p->nome);
            scanf("%d", &(p->numFilhos));
            printf("Informe a idade de %s: ", p->nome);
            scanf("%d", &(p->idade));
            cofInsert(c, (void *)p);
            system("PAUSE");
            return TRUE;
        }
    }
    printf("O cofo nao existe!!!\n");
    system("PAUSE");
    return FALSE;
}

int showAll(Cofo *c){
    int i;
    if(c!=NULL) {
        if(c->nelm>0){
            printf("===============================\tPESSOAS NO COFO\t==================================\n");
            for(i=0;i<c->nelm; i++){
                Pessoa *aux = (Pessoa*)c->elm[i];
                printf("================================================================================\n");
                printf("Nome: %s\n", aux->nome);
                printf("CPF de %s: %s\n", aux->nome, aux->cpf);
                printf("Idade de %s: %d\n", aux->nome, aux->idade);
                printf("Numero de filhos de %s: %d\n", aux->nome, aux->numFilhos);
                printf("Salario de %s: %.2f\n", aux->nome, aux->salario);
                printf("================================================================================\n");

            }
            printf("===============================\tPESSOAS NO COFO\t==================================\n");
            system("PAUSE");
            return TRUE;
        }
        else {
            printf("================================================================================\n");
            printf("Cofo Vazio\n");
            printf("================================================================================\n");
            system("PAUSE");
        }
    }
    return FALSE;
}

int freeAll(Cofo *c){
    int i;
    if(c!=NULL) {
        if(c->nelm>0){
            for(i=0;i<c->nelm;i++){
                free(c->elm[i]);
            }
            c->nelm = 0;
            printf("Cofo esvaziado!!!\n");
            system("PAUSE");
            return TRUE;
        }
        printf("O cofo ja esta vazio!!!\n");
        system("PAUSE");
        return FALSE;
    }
    return FALSE;
}
