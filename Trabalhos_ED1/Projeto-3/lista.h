#ifndef _LISTA_H_
#define _LISTA_H_
#include <stdbool.h>

typedef struct _sllem_{
    struct _sllem_ *next;
    void *data;
}Sllnode;

typedef struct _sllist_{
    Sllnode *first;
}Sllist;

    #ifndef _LISTA_C_
        Sllist *sllCreate();
        int sllInsertFirst(Sllist *l, void *);
        int sllInsertLast(Sllist *l, void *);
        void *sllRemoveFirst(Sllist *l);
        void *sllQuery(Sllist *l, void *key, int(*cmp)(void*, void*));
        void *sllRemove(Sllist *list, void *key, int(*cmp)(void*, void*));
        int sllDestroy(Sllist *l);
        int sllNumNodes(Sllist *l);
    #else
        extern Sllist *sllCreate();
        extern int sllInsertFirst(Sllist *l, void *);
        extern int sllInsertLast(Sllist *l, void *);
        extern void *sllRemoveFirst(Sllist *l);
        extern int sllDestroy(Sllist *l);
        extern int sllNumNodes(Sllist *l);
        extern void *sllQuery(Sllist *l, void *key, int(*cmp)(void*, void*));
        extern void *sllRemove(Sllist *list, void *key, int(*cmp)(void*, void*));
    #endif

#endif

