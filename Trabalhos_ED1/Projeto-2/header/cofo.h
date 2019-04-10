#ifndef cofo_h
#define cofo_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _cofo_{
    int max;
    int nElms;
    void **elms;
}Cofo;

    #ifndef cofo_c
        Cofo *novoCofo(int max);
    #else    
    #endif
    
#endif


