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

int sllDestroy(Sllist *l){
    if(l->first==NULL){
        free(l);
        return true;
    }
    return false;
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

int sllInsertLast(Sllist *l, void *elm){
    Sllnode *newnode;
    Sllnode *last;

    if(l!=NULL){
        newnode = (Sllnode*)malloc(sizeof(Sllnode));
        if(newnode!=NULL){
            newnode->next = NULL;
            newnode->data = elm;
            if(l->first == NULL){
                l->first = newnode;
            }else{
                last = l->first;
                while(last->next!=NULL){
                    last = last->next;
                }
                last->next = newnode;
            }
            return true;
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
            data = aux->data;
            free(aux);
            return data;
        }
    }
    return NULL;
}

int sllNumNodes(Sllist *l){

  Sllnode *aux;
  int size = 0;

  if (l != NULL){
    if (l->first != NULL){
      aux = l->first;
      size = 1;
      while (aux->next != NULL){
        size++;
        aux = aux->next;
      }
      return size;
    }
  }
  return false;

}

void *sllQuery(Sllist *l, void *key, int(*cmp)(void*, void*)){

  Sllnode *current;
  int stat;
  int n = 0;
  if (l != NULL){
    current = l->first;
    stat = cmp(key, current->data);
    while (stat != true && current != NULL){
       printf("%d \n", n);
       n++;
       current = current->next;
    }

    if (stat == true){
      return current->data;
    }

  }
  return NULL;
}

void *sllRemove(Sllist *list, void *key, int(*cmp)(void*, void*)){

  Sllnode *current;
  Sllnode *previous;
  void *data;
  int stat;

  if (list != NULL){
    if (list->first != NULL){
      current = list->first;
      previous = NULL;
      stat = cmp(key, current->data);    
      while ( stat != true && current!= NULL){
        previous = current;
        current = current->next;
        stat = cmp(key, current->data);
      }

      if (stat == true){
        if (previous != NULL){
          previous->next = current->next;
        } else {
          list->first = current->next;
        }

        data = current->data;
        free(current);
        return data;
      }
    }
  }

  return NULL;

}


