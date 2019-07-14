#ifndef _PESSOA_H_
#define _PESSOA_H_

#include "tree.h"

typedef struct _PESSOA_{
        char cpf[12];
        char nome[30];
        int numFilhos;
        double salario;
        int idade;
}Pessoa;

    #ifndef _PESSOA_C_
        int insertPessoa(Tnode *t); // RETORNA TRUE SE A PESSOA FOI ENCONTRADO E FALSE EM CASO CONTRÁRIO
        int removePessoa(Tnode *t); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int searchPessoa(Tnode *t); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int showAll(Tnode *t); // RETORNA TRUE SE PERCORREU A LISTA SEM PROBLEMAS E FALSE EM CASO CONTRÁRIO
    #else 
        extern int insertPessoa(Tnode *t); // RETORNA TRUE SE A PESSOA FOI ENCONTRADO E FALSE EM CASO CONTRÁRIO
        extern int removePessoa(Tnode *t); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int searchPessoa(Tnode *t); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int showAll(Tnode *t); // RETORNA TRUE SE PERCORREU A LISTA SEM PROBLEMAS E FALSE EM CASO CONTRÁRIO
    #endif
#endif