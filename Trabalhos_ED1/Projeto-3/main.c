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
        printf("[7] *** Esvaziar a Lista\n");
        printf("[0] *** Sair\n");
        printf("================================================================================\n");
        printf("Sua Escolha: ");
        scanf("%d", &condit);
        fflush(stdin);

        //Escolhas//
        switch (condit){
            case 1:
                l = sllCreate();
                if(l!=NULL){
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
                        printf("Lista destruida com sucesso");
                    }else{
                        printf("Lista nao foi destruida\n");
                    }
                }
                system("pause");
                break;
            case 3:
                printf("deseja inserir no inicio ou no fim?[1]inicio[0]fim: ");
                scanf("%d", &num2);
                if(num2==1){
                    printf("insere: ");
                    scanf("%d", &num);
                    sllInsertFirst(l, (void*)num);
                    system("pause");
                }else if(num2==0){
                    printf("insere: ");
                    scanf("%d", &num);
                    sllInsertLast(l, (void*)num);
                    system("pause");
                }
                break;
            case 4:
                break;
            case 5:
                printf("removeu: ");
                num = (int*)sllRemoveFirst(l);
                if(num!=NULL){
                    printf("%d\n", num);
                }
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