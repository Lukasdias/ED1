#define _LISTA_C_

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Sllist *sllCreate(){
    Sllist *l;

    l = (Sllist*)malloc(sizeof(Sllist));
    if(l!=NULL){
        l->first = NULL;
        return l;
    }
    return NULL;
}

int sllInsertFirst(Sllist *l, void *elm){
    Sllnode *newnode;
    if(l!=NULL){
        newnode = (Sllnode*)malloc(sizeof(Sllnode));
        if(newnode!=NULL){
            newnode->data = elm;
            newnode->next = l->first;
            l->first = newnode;
            return  true;
        }

    }
    return false;
}

void *sllRemoveFirst(Sllist *l){
    Sllnode *aux;
    void *data;
    if(l!=NULL){
        if(l->first!=NULL){
            aux = l->first;
            l->first = aux->next;
            data=aux->data;
            free(aux);
            return data;
        }
    }
    return NULL;
}



