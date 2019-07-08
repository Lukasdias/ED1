#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "pessoa.c"
#include "lista.c"

void menuLista();

int main(){
    menuLista();
    return 0;
}

void menuLista(){
    //Lista//
    Sllist *l = NULL;
    Pessoa *aux;
    //Lista//
    
    //Variaveis auxiliares//
    int condit;
    int test;
    //Variaveis auxiliares//

    //Menu Principal//
    while (condit!=0) {
        //Estruturas//
        Pessoa *p;
        int num;
        int num2;
        //Estruturas//
        system("cls");
        printf("==================================MENU LISTA====================================\n");
        printf("[1] *** Criar uma Lista \n");
        printf("[2] *** Destruir uma Lista\n");
        printf("[3] *** Inserir uma Pessoa na Lista\n");
        printf("[4] *** Pesquisar uma Pessoa na Lista\n");
        printf("[5] *** Remover uma pessoa da Lista\n");
        printf("[6] *** Listar todas as pessoas da Lista\n");
        if(l!=NULL){
            printf("Pessoas na lista = %d\n", sllNumNodes(l));
        }
        printf("[0] *** Sair\n");
        printf("================================================================================\n");
        printf("Sua Escolha: ");
        scanf("%d", &condit);
        fflush(stdin);

        //Mini menu//
        switch (condit){
            case 1:
                if(l==NULL){
                    l = sllCreate();
                    printf("Lista criada\n");
                }else {
                    printf("Lista n pode ser criada\n");
                }
                system("pause");
                break;
            case 2:
                if(l!=NULL){
                    test = sllDestroy(l);
                    if(test==true){
                        printf("Lista destruida com sucesso\n");
                        l = NULL;
                    }else{
                        printf("Lista nao foi destruida\n");
                    }
                }
                system("pause");
                break;
            case 3:
                printf("Deseja inserir no inicio ou no fim da lista?\n");
                printf("[1]->no inicio\t[2]->no fim:\t");
                scanf("%d", &test);
                switch (test){
                case 1:
                    insertPessoa(l, 1);
                    break;
                case 2:
                    insertPessoa(l, 2);
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }
                break;
            case 4:
                printf("Deseja pesquisar usando CPF ou Nome\n");
                printf("[1]->Nome\t[2]->CPF:\t");
                scanf("%d", &test);
                switch (test){
                case 1:
                    searchPessoa(l, 1);
                    break;
                case 2:
                    searchPessoa(l, 2);
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }
                break;
            case 5:
                printf("Deseja remover usando CPF ou Nome?\n");
                printf("[1]->Nome\t[2]->CPF\n");
                scanf("%d", &test);
                switch (test){
                case 1:
                    removePessoa(l, 1);
                    break;
                case 2:
                    removePessoa(l, 2);
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
                }
                break;
            case 6:
                showAll(l);
                break;
            case 0: 
                break;
            default:
                break;
        }
    }
}