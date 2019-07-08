#define _COFO_C_ 

#include <stdio.h>
#include <stdlib.h>
#include "cofo.h"

Cofo *cofCreate(int max){
  Cofo *c;
  if (max > 0){
    c = (Cofo*)malloc(sizeof(Cofo));
    if (c != NULL){
      c->elm = (void **)malloc(sizeof(void *)*max);
      if (c->elm != NULL){
        c->max = max;
        c->nelm = 0;
        printf("Cofo criado com sucesso!!!\n");
        return c;
      }
    }
  }
  return NULL;
}

int cofDestroy(Cofo *c){
  if (c != NULL){
    if (c->nelm == 0){
      free(c->elm);
      free(c);
      printf("Cofo destruido!!!\n");
      return TRUE;
    }
  }
  return FALSE;
}

int cofInsert(Cofo *c, void *item){
  if(c!=NULL){
    if(c->nelm < c->max){
        c->elm[c->nelm] = item;
        c->nelm++;
        printf("Inserido com sucesso!!!\n");
        return TRUE;
    }
    else {
      printf("Cofo cheio!!!, nao e possivel adicionar mais estruturas!!!\n");
      return FALSE;
    }  
  }
  return FALSE;
}

void *cofQuery(Cofo *c, void *key, int(*cmp)(void *, void *)){
  int i;
  void *aux;
  int stat;
  if (c != NULL){
    if (c->nelm > 0){
      for(i=0;i<c->nelm;i++){
          stat = cmp(key, c->elm[i]);
          if(stat == TRUE){
              aux = c->elm[i];
              return aux;
          }
      }
    }
  }
  return NULL;
}

void *cofRemove(Cofo *c, void *key, int(*cmp)(void *, void *)){
    if(c!=NULL){
      if(c->nelm>0){
        int i = 0, j;
        void *aux;
        int stat = cmp(key, c->elm[i]);
        while(i<c->nelm-1 && stat != TRUE){
          aux=c->elm[i];
          stat=cmp(aux, key);
          i++;
        }
        if(stat == TRUE){
          for(j=i;(j<c->nelm-1);j++){
            c->elm[j] = c->elm[j+1];
          }
          c->nelm--;
          return aux;
        }
      }
    }
    return NULL;
}