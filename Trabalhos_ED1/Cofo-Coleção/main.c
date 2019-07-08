#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cofo.h"
#include "pessoa.h"

//FUNÇÃO DO MENU//
void myMenu();
//FUNÇÃO DO MENU//

//Declarações de funções relacionadas a Pessoa//


int main(){
    myMenu();
    return 0;
}

void myMenu() {
    //Variaveis auxiliares//
    Cofo *c = NULL;
    int condit;
    int tamCofo;
    int test;
    //Variaveis auxiliares//
    //Menu Principal//
    while (condit!=0) {
        //Estruturas//
        Pessoa *p;
        //Estruturas//
        // system("cls");
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
        if(c!=NULL) {
            printf("Itens inseridos no cofo %d\n", c->nelm);
            printf("Capacidade maxima: %d\n", c->max);
        }else {
        printf("Cofo inexistente\n");
        }
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
                test = cofDestroy(c);
                if(test == TRUE){
                    c = NULL;
                }          
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
