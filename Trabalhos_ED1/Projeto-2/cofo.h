#ifndef _COFO_H_
#define _COFO_H_

#define TRUE 0
#define FALSE 1

  typedef struct _COFO_{
      int max;
      int nelm;
      void **elm;
  }Cofo;

  #ifdef _COFO_C_

    Cofo *cofCreate(int max); //Cria Cofo//
    int cofDestroy(Cofo *c); //Destroi Cofo//
    int cofInsert(Cofo *c, void *item); //Insere no Cofo//
    int cofCheck(Cofo *c); //Checa quantos itens tem no Cofo//
    void *cofQuery(Cofo *c, void *key, int(*cmp)(void*, void*)); //Procurar um item no Cofo//
    void *cofRemove(Cofo *c, void *key, int(*cmp)(void*, void*)); //Remove um item no Cofo//

  #else

    extern Cofo *cofCreate(int max); //Cria Cofo//
    extern int cofDestroy(Cofo *c); //Destroi Cofo//
    extern int cofInsert(Cofo *c, void* item); //Insere no Cofo//
    extern int cofCheck(Cofo *c); //Checa quantos itens tem no Cofo//
    extern void *cofQuery(Cofo *c, void *key, int(*cmp)(void*, void*)); //Procurar um item no Cofo//
    extern void *cofRemove(Cofo *c, void *key, int(*cmp)(void*, void*)); //Remove um item no Cofo//

  #endif

#endif

