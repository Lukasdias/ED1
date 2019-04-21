#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int cmpCpfPessoa(void *a, void *b);

int cmpNomePessoa(void *a, void *b);

int listPessoas(Cofo *c);

void searchCpf(Cofo *c);

void searchName(Cofo *c);

void myMenu();

void showAll(Cofo *c);

int main(){
    myMenu();
    return 0;
}

void myMenu() {
    //Estruturas//
    Cofo *c;
    Pessoa *p;
    //Estruturas//

    //Variaveis auxiliares//
    int condit;
    //Variaveis auxiliares//

    //Menu Principal//
    while (condit!=0) {
         system("cls");
         printf("==================================MENU COFO====================================\n");
         printf("[1] *** Criar Cofo \n");
         printf("[2] *** Destruir Cofo\n");
         printf("[3] *** Inserir dados de uma Pessoa no Cofo\n");
         printf("[4] *** Pesquisar pessoa no Cofo via *CPF*\n");
         printf("[5] *** Pesquisar pessoa no Cofo via *Nome*\n");
         printf("[6] *** Listar pessoas no Cofo\n");
         printf("[7] *** Destruir Cofo\n");
         printf("[0] *** Sair\n");
         cofCheck(c);
         printf("================================================================================\n");
         printf("Sua Escolha: ");
         scanf("%d", &condit);
         fflush(stdin);

        //Escolhas//
        if (condit == 1) {
            printf("Digite o tamanho do cofo: ");
            int tamCofo;
            scanf("%d", &tamCofo);
            while(tamCofo <= 0){
                printf("Valor negativo, Digite o tamanho do cofo: ");
                scanf("%d", &tamCofo);
            }
            c = cofCreate(tamCofo);
            system("PAUSE");
        }
        else if(condit == 2){
            cofDestroy(c);
            system("PAUSE");
            break;
        }
        else if(condit == 3){
            p = (Pessoa *) malloc(sizeof(Pessoa));
            if (p != NULL) {
                printf("Informe o nome da pessoa: ");
                fflush(stdin);
                scanf("%[^\n]*c", (p->nome));
                fflush(stdin);
                printf("Informe o CPF da pessoa: ");
                scanf("%ld", &(p->cpf));
                printf("Informe o salario de %s: ", p->nome);
                scanf("%lf", &(p->salario));
                printf("Informe o numero de filhos de %s: ", p->nome);
                scanf("%d", &(p->numFilhos));
                printf("Informe a idade de %s: ", p->nome);
                scanf("%d", &(p->idade));
                cofInsert(c, (void *)p);
                system("PAUSE");
            }
        }
        else if(condit == 4){
            // searchCpf(c);
        }
        else if(condit == 5){
            searchName(c);
        }
        else if(condit == 6){

        }
        else {
            cofDestroy(c);
            condit = 0;
        }
    }
}

int cmpCpfPessoa(void *a, void *b){
  long int *cpf = a;
  Pessoa *pessoa = b;

  if (*cpf == pessoa->cpf) {
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

void searchCpf(Cofo *c){
    long int aux_cpf;
    Pessoa *aux_P;
    if(c!=NULL){
        printf("Informe o CPF da pessoa a ser buscada: ");
        scanf("%ld", &aux_cpf);
        fflush(stdin);
        aux_P = (Pessoa *)cofQuery(c, (void *)aux_cpf, cmpCpfPessoa);
        if (aux_P != NULL){
            printf("=================================================================================\n");
            printf("Nome: %s\n", aux_P->nome);
            printf("Idade de %s: %d\n", aux_P->nome, aux_P->idade);
            printf("Numero de filhos de %s: %d\n", aux_P->nome, aux_P->numFilhos);
            printf("Salario de %s: %.2f\n", aux_P->nome, aux_P->salario);
            printf("CPF de %s: %ld\n", aux_P->nome, aux_P->cpf);
            printf("================================================================================\n");
            system("PAUSE");
        }
        else {
            printf("Cpf = %ld nao encontrado no cofo\n", aux_cpf);
            system("PAUSE");
        } 
    }
}

void searchName(Cofo *c){
    char aux_nome[30];
    Pessoa *aux_P;
    if(c!=NULL){
        printf("Informe o nome da pessoa a ser buscada: ");
        scanf("%[^\n]*c", &aux_nome);
        fflush(stdin);
        aux_P = (Pessoa *)cofQuery(c, (void *)aux_nome, cmpNomePessoa);
        if (aux_P != NULL){
            printf("================================================================================\n");
            printf("Nome: %s\n", aux_P->nome);
            printf("Idade de %s: %d\n", aux_P->nome, aux_P->idade);
            printf("Numero de filhos de %s: %d\n", aux_P->nome, aux_P->numFilhos);
            printf("Salario de %s: %.2f\n", aux_P->nome, aux_P->salario);
            printf("CPF de %s: %ld\n", aux_P->nome, aux_P->cpf);
            printf("================================================================================\n");
            system("PAUSE");
        }
        else {
            printf("%s nao encontrado no cofo\n", aux_nome);
            system("PAUSE");
        } 
    }
}