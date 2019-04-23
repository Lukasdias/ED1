#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//Declarações de funções relacionadas a Pessoa//
// int cmpCpfPessoa(void *a, void *b);

int cmpNomePessoa(void *a, void *b);

int insertPessoa(Cofo *c);

int listPessoas(Cofo *c);

int searchCpf(Cofo *c);

int searchName(Cofo *c);

int removeViaCpf(Cofo *c);

int removeViaName(Cofo *c);

void myMenu();

int showAll(Cofo *c);

int freeAll(Cofo *c);

int isDestroyed(Cofo *c);

//Declarações de funções relacionadas a Pessoa//
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
    int tamCofo;
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
         printf("[6] *** Remover pessoa do Cofo via *CPF*\n");
         printf("[7] *** Remover pessoa do Cofo via *Nome*\n");
         printf("[8] *** Listar todas as pessoas do Cofo\n");
         printf("[9] *** Esvaziar o Cofo\n");
         printf("[0] *** Sair\n");
         cofCheck(c);
         printf("================================================================================\n");
         printf("Sua Escolha: ");
         scanf("%d", &condit);
         fflush(stdin);

        //Escolhas//
        switch (condit){
            case 1:
                printf("Digite o tamanho do cofo: ");
                scanf("%d", &tamCofo);
                while(tamCofo <= 0){
                    printf("Valor negativo, Digite o tamanho do cofo: ");
                    scanf("%d", &tamCofo);
                }
                c = cofCreate(tamCofo);
                system("PAUSE");
                break;
            case 2:
                cofDestroy(c);
                system("PAUSE");
                break;
            case 3:
                insertPessoa(c);
                break;
            case 4:
                searchCpf(c);
                break;
            case  5:
                searchName(c);
                break;
            case 6:
                removeViaCpf(c);
                break;
            case 7:
                removeViaName(c);
                break;
            case 8:
                showAll(c);
                break;
            case 9:
                freeAll(c);
                break;
            case 0: 
                break;
            default:
                break;
        }
    }
}


// int cmpCpfPessoa(void *a, void *b){
//   char *auxA;
//   Pessoa *auxB;

//   auxA = (char *)a;
//   auxB = (Pessoa *)b;

//   if (strcmp(auxA, auxB->nome) == 0){
//     return TRUE;
//   } 
//   else {
//     return FALSE;
//   }
// }

int cmpPessoa(void *a, void *b){
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

    char aux_cpf[11];
    Pessoa *aux_P;
    if(c!=NULL){
        printf("Informe o CPF da pessoa a ser buscada: ");
        fflush(stdin);
        scanf("%[^\n]*c", &aux_cpf);
        fflush(stdin);
        aux_P = (Pessoa *)cofQuery(c, (void *)aux_cpf, cmpPessoa);
        if (aux_P != NULL){
            printf("=================================================================================\n");
            printf("Nome: %s\n", aux_P->nome);
            printf("Idade de %s: %d\n", aux_P->nome, aux_P->idade);
            printf("Numero de filhos de %s: %d\n", aux_P->nome, aux_P->numFilhos);
            printf("Salario de %s: %.2f\n", aux_P->nome, aux_P->salario);
            printf("CPF de %s: %s\n", aux_P->nome, aux_P->cpf);
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
    return FALSE;
}

int searchName(Cofo *c){
    char aux_nome[30];
    Pessoa *aux_P;

    if(c!=NULL) {
        printf("Informe o nome da pessoa a ser buscada: ");
        fflush(stdin);
        scanf("%[^\n]*c", &aux_nome);
        fflush(stdin);
        aux_P = (Pessoa *)cofQuery(c, (void *)aux_nome, cmpPessoa);
        if (aux_P != NULL){
            printf("================================================================================\n");
            printf("Nome: %s\n", aux_P->nome);
            printf("Idade de %s: %d\n", aux_P->nome, aux_P->idade);
            printf("Numero de filhos de %s: %d\n", aux_P->nome, aux_P->numFilhos);
            printf("Salario de %s: %.2f\n", aux_P->nome, aux_P->salario);
            printf("CPF de %s: %s\n", aux_P->nome, aux_P->cpf);
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
    return FALSE;
}

int removeViaCpf(Cofo *c){
    long int aux_cpf;
    Pessoa *aux_P;
    if(c->nelm > 0){
        printf("Informe o CPF da pessoa a ser buscada: ");
        scanf("%ld", &aux_cpf);
        aux_P = (Pessoa *)cofRemove(c, (void *)aux_cpf, cmpPessoa);
        if (aux_P != NULL){
            printf("================================================================================\n");
            printf("Pessoa %s foi encontrada e removida do cofo!!!\n");
            printf("================================================================================\n");
            system("PAUSE");
            return TRUE;
        }
        else {
            printf("Cpf = %ld nao encontrado no cofo\n", aux_cpf);
            system("PAUSE");
            return FALSE;
        } 
    }
    return FALSE;
}

int removeViaName(Cofo *c){
    char aux_nome[30];
    Pessoa *aux_P;
    if(c!=NULL){
        printf("Informe o nome da pessoa a ser buscada: ");
        fflush(stdin);
        scanf("%[^\n]s", &aux_nome);
        fflush(stdin);
        aux_P = (Pessoa *)cofRemove(c, (void *)aux_nome, cmpPessoa);
        if (aux_P != NULL){
            printf("================================================================================\n");
            printf("Pessoa chamada %s foi removida do cofo!!!\n", aux_P->nome);
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
    return FALSE;
}

int insertPessoa(Cofo *c){
    Pessoa *p = (Pessoa *) malloc(sizeof(Pessoa));    
    if (p != NULL) {
        printf("Informe o nome da pessoa: ");
        fflush(stdin);
        scanf("%[^\n]*c", (p->nome));
        fflush(stdin);
        printf("Informe o CPF da pessoa: ");
        fflush(stdin);
        scanf("%[^\n]*c", (p->cpf));
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
    return FALSE;
}

int showAll(Cofo *c){
    int i;
    if(c!=NULL){
        if(c->nelm>0){
            for(i=0;i<c->nelm; i++){
                Pessoa *aux = (Pessoa*)c->elm[i];
                printf("================================================================================\n");
                printf("Nome: %s\n", aux->nome);
                printf("Idade de %s: %d\n", aux->nome, aux->idade);
                printf("Numero de filhos de %s: %d\n", aux->nome, aux->numFilhos);
                printf("Salario de %s: %.2f\n", aux->nome, aux->salario);
                printf("CPF de %s: %s\n", aux->nome, aux->cpf);
                printf("================================================================================\n");
            }
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
    if(c!=NULL){
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
