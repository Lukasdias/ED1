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
        int insertPessoa(Sllist *l);
        int showAll(Sllist *l);
        int searchCpf(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int searchName(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int removeViaCpf(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int removeViaName(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int cmpNomePessoa(void *a, void *b); //RETORNA TRUE SE OS CPFS FOREM IGUAIS E FALSO EM CASO CONTRÁRIO
        int cmpCpfPessoa(void *a, void *b); //RETORNA TRUE SE OS NOMES FOREM IGUAIS E FALSE EM CASO CONTRÁRIO
        int insertPessoa(Sllist *l);
        int showAll(Sllist *l);
        int searchCpf(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int searchName(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int removeViaCpf(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int removeViaName(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        int freeAll(Sllist *l); //RETORNA TRUE SE O COFO FOI ESVAZIADO COM SUCESSO, FALSE EM CASO CONTRARIO, OU SE O COFO JÁ ESTAVA VAZIO
    #else 
        extern int cmpNomePessoa(void *a, void *b); //RETORNA TRUE SE OS CPFS FOREM IGUAIS E FALSO EM CASO CONTRÁRIO
        extern int cmpCpfPessoa(void *a, void *b); //RETORNA TRUE SE OS NOMES FOREM IGUAIS E FALSE EM CASO CONTRÁRIO
        extern int insertPessoa(Sllist *l);
        extern int showAll(Sllist *l);
        extern int searchCpf(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int searchName(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int removeViaCpf(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int removeViaName(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int cmpNomePessoa(void *a, void *b); //RETORNA TRUE SE OS CPFS FOREM IGUAIS E FALSO EM CASO CONTRÁRIO
        extern int cmpCpfPessoa(void *a, void *b); //RETORNA TRUE SE OS NOMES FOREM IGUAIS E FALSE EM CASO CONTRÁRIO
        extern int insertPessoa(Sllist *l);
        extern int showAll(Sllist *l);
        extern int searchCpf(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int searchName(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int removeViaCpf(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int removeViaName(Sllist *l); //RETORNA TRUE SE ENCONTROU E FALSE EM CASO CONTRARIO
        extern int freeAll(Sllist *l); //RETORNA TRUE SE O COFO FOI ESVAZIADO COM SUCESSO, FALSE EM CASO CONTRARIO, OU SE O COFO JÁ ESTAVA VAZIO
    #endif
#endif