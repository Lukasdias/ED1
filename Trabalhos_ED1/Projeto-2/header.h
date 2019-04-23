#ifndef _COFO_H_
#define _COFO_H_

#define TRUE 0
#define FALSE 1

  typedef struct _COFO_{
      int max;
      int nelm;
      void **elm;
  }Cofo;

  typedef struct _PESSOA_{
    char cpf[11];
    char nome[30];
    int numFilhos;
    double salario;
    int idade;
  }Pessoa;

  #ifdef _COFO_C_

    Cofo *cofCreate(int max);
    int cofDestroy(Cofo *c);
    int cofInsert(Cofo *c, void *item);
    void cofCheck(Cofo *c);
    void *cofQuery(Cofo *c, void *key, int(*cmp)(void*, void*));
    void *cofRemove(Cofo *c, void *key, int(*cmp)(void*, void*));

  #else

    extern Cofo *cofCreate(int max);
    extern int cofDestroy(Cofo *c);
    extern int cofInsert(Cofo *c, void* item);
    extern int cofCheck(Cofo *c);
    extern void *cofQuery(Cofo *c, void *key, int(*cmp)(void*, void*));
    extern void *cofRemove(Cofo *c, void *key, int(*cmp)(void*, void*));

  #endif

#endif

