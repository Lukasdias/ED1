#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"
#include "lista.h"

void menuLista();

int main(){
    menuLista();
    return 0;
}

void menuLista(){
    //Lista//
    Sllist *l = NULL;
    //Lista//
    
    //Variaveis auxiliares//
    int condit;
    int test;
    //Variaveis auxiliares//

    //Menu Principal//
    while (condit!=0) {
        //Estruturas//
        Pessoa *p;
        //Estruturas//
        // system("cls");
        printf("==================================MENU LISTA====================================\n");
        printf("[1] *** Criar uma Lista \n");
        printf("[2] *** Destruir uma Lista\n");
        printf("[3] *** Inserir uma Pessoa na Lista\n");
        printf("[4] *** Pesquisar uma Pessoa na Lista\n");
        printf("[5] *** Remover uma pessoa da Lista\n");
        printf("[6] *** Listar todas as pessoas da Lista\n");
        printf("[7] *** Limpar a Lista\n");
        printf("[0] *** Sair\n");
        printf("================================================================================\n");
        printf("Sua Escolha: ");
        scanf("%d", &condit);
        fflush(stdin);

        //Escolhas//
        switch (condit){
            case 1:
                if(l==NULL){
                    l = sllCreate();
                }else{
                    printf("Ainda existe uma lista, destrua ela para poder criar outra");
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case  5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 0: 
                break;
            default:
                break;
        }
    }
}