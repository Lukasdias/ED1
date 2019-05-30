#define _PESSOA_C_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pessoa.h"

int cmpCpfPessoa(void *key, void *data){
  char *cpf;
  Pessoa *aux;

  cpf = (char*)key;
  aux = (Pessoa*)data;

  if (strcmp(cpf, aux->cpf) == 0){
    return true;
  }else{
    return false;
  }
}

int cmpNomePessoa(void *key, void *data){
  char *nome;
  Pessoa *aux;

  nome = (char*)key;
  aux = (Pessoa*)data;

  if (strcmp(nome, aux->nome) == 0){
    return true;
  }else{
    return false;
  }
}

int searchPessoa(Sllist *l, int type){
    if(type == 1){
        char aux_nome[30];
        Pessoa *aux;
        if(l!=NULL && l->first != NULL) {
            printf("Informe o nome da pessoa a ser buscada: ");
            fflush(stdin);
            scanf("%s", (aux_nome));
            fflush(stdin);
            aux = (Pessoa *)sllQuery(l, (void *)aux_nome, cmpNomePessoa);
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
                printf("%s nao encontrado no Lista\n", aux_nome);
                system("PAUSE");
                return false;
            }
        }
        printf("Lista VAZIA!!!\n");
        system("PAUSE");
        return false;
    }else if(type == 2){
        char aux_cpf[12];
        Pessoa *aux;
        if(l!=NULL){
            if(l->first!=NULL){
                printf("Informe o CPF da pessoa a ser buscada: ");
                fflush(stdin);
                scanf("%s", aux_cpf);
                fflush(stdin);
                aux = (Pessoa *)sllQuery(l, (void *)aux_cpf, cmpCpfPessoa);
                if (aux != NULL){
                    printf("=================================================================================\n");
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
                    printf("Cpf = %s nao encontrado no Lista\n", aux_cpf);
                    system("PAUSE");
                    return false;
                }
            }
            printf("Lista VAZIO!!!\n");
            system("PAUSE");
            return false;
        }
    }
}

int removePessoa(Sllist *l, int type){
    if(type == 1){
        char aux_nome[30];
        Pessoa *aux;
        if(l!=NULL && l->first!=NULL){
            printf("Informe o nome da pessoa a ser buscada: ");
            fflush(stdin);
            scanf("%s", (aux_nome));
            fflush(stdin);
            aux = (Pessoa *)sllRemove(l, (void *)aux_nome, cmpNomePessoa);
            if (aux != NULL){
                printf("================================================================================\n");
                printf("Pessoa chamada %s foi removida do Lista!!!\n", aux_nome);
                printf("================================================================================\n");
                system("PAUSE");
                return true;
            }
            else {
                printf("%s nao encontrado no Lista\n", aux_nome);
                system("PAUSE");
                return false;
            } 
        }
        printf("Lista Vazio!!!\n");
        return false;
    }else if(type == 2){
        char aux_cpf[12];
        Pessoa *aux_P;
        if(l!=NULL && l->first!=NULL){
            printf("Informe o CPF da pessoa a ser buscada: ");
            fflush(stdin);
            scanf("%s", (aux_cpf));
            fflush(stdin);
            aux_P = (Pessoa *)sllRemove(l, (void *)aux_cpf, cmpCpfPessoa);
            if (aux_P != NULL){
                printf("================================================================================\n");
                printf("Pessoa com o CPF = %s foi encontrada e removida do Lista!!!\n", aux_cpf);
                printf("================================================================================\n");
                system("PAUSE");
                return true;
            }
            else {
                printf("Cpf = %s nao encontrado no Lista\n", aux_cpf);
                system("PAUSE");
                return false;
            } 
        }
        printf("Lista Vazio!!!\n");
        return false;
    }
}

int insertPessoa(Sllist *l, int type){        
    if(l!=NULL) {
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
            if(type == 1){
                sllInsertFirst(l, (void *)p);
            }else if(type == 2){
                sllInsertLast(l, (void *)p);
            }
            printf("Pessoa inserida com sucesso\n");
            system("PAUSE");
            return true;
        }
    }
    printf("O Lista nao existe!!!\n");
    system("PAUSE");
    return false;
}

int showAll(Sllist *l){
    int i;
    Sllnode *current;
    Pessoa *aux;
    if(l!=NULL) {
        if(l->first!=NULL){
            current = l->first;
            aux = (Pessoa*)malloc(sizeof(Pessoa));
            printf("===============================\tPessoas Na Lista\t==================================\n");
            while (current!=NULL){
                aux = (Pessoa*)current->data;
                printf("================================================================================\n");
                printf("Nome: %s\n", (&aux->nome));
                printf("CPF de %s: %s\n", aux->nome, aux->cpf);
                printf("Idade de %s: %d\n", aux->nome, aux->idade);
                printf("Numero de filhos de %s: %d\n", aux->nome, aux->numFilhos);
                printf("Salario de %s: %.2f\n", aux->nome, aux->salario);
                printf("================================================================================\n");
                current = current->next;
            }
            printf("===============================\tPessoas Na Lista\t==================================\n");
            system("PAUSE");
            return true;
        }
        else {
            printf("================================================================================\n");
            printf("===============================\tLista Vazia\t==================================\n");
            printf("================================================================================\n");
            system("PAUSE");
        }
    }
    return false;
}

int freeAll(Sllist *l){
    int i;
    Sllnode *current;
    Sllnode *previous;
    if(l!=NULL) {
        if(l->first!=NULL){
            current = l->first;
            previous = NULL;
            while(current!=NULL){
                previous = current;
                current = current->next;
                if (previous != NULL){
                    previous->next = current->next;
                }else {
                    l->first = current->next;
                }
            }
            printf("Lista esvaziada!!!\n");
            system("PAUSE");
            return true;
        }
        printf("O Lista ja esta vazia!!!\n");
        system("PAUSE");
        return false;
    }
    return false;
}