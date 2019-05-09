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
        void *sllRemoveFirst(Sllist *l);
        int sllDestroy(Sllist *l);
    #else
        extern Sllist *sllCreate();
        extern int sllInsertFirst(Sllist *l, void *);
        extern void *sllRemoveFirst(Sllist *l);
        extern int sllDestroy(Sllist *l);
    #endif

#endif

