#ifndef _PESSOA_H_
#define _PESSOA_H_

#include "lista.h"

typedef struct _PESSOA_{
        char cpf[12];
        char nome[30];
        int numFilhos;
        double salario;
        int idade;
}Pessoa;

    #ifdef _PESSOA_C_
        int cmpNomePessoa(void *a, void *b); //RETORNA TRUE SE OS CPFS FOREM IGUAIS E FALSO EM CASO CONTRÁRIO
        int cmpCpfPessoa(void *a, void *b); //RETORNA TRUE SE OS NOMES FOREM IGUAIS E FALSE EM CASO CONTRÁRIO
        int insertPessoa(Sllist *l, int type); // RETORNA TRUE SE A PESSOA FOI ENCONTRADO E FALSE EM CASO CONTRÁRIO
        int removePessoa(Sllist *l, int type); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int searchPessoa(Sllist *l, int type); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int showAll(Sllist *l); // RETORNA TRUE SE PERCORREU A LISTA SEM PROBLEMAS E FALSE EM CASO CONTRÁRIO
    #else 
        extern int cmpNomePessoa(void *a, void *b); //RETORNA TRUE SE OS CPFS FOREM IGUAIS E FALSO EM CASO CONTRÁRIO
        extern int cmpCpfPessoa(void *a, void *b); //RETORNA TRUE SE OS NOMES FOREM IGUAIS E FALSE EM CASO CONTRÁRIO
        extern int insertPessoa(Sllist *l, int type); // RETORNA TRUE SE A PESSOA FOI ENCONTRADO E FALSE EM CASO CONTRÁRIO
        extern int removePessoa(Sllist *l, int type); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int searchPessoa(Sllist *l, int type); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int showAll(Sllist *l); // RETORNA TRUE SE PERCORREU A LISTA SEM PROBLEMAS E FALSE EM CASO CONTRÁRIO
    #endif
#endif