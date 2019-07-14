#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

typedef struct _treeTnode_{
    struct _treeTnode_ *left;
    struct _treeTnode_ *right;
    void *data;
}Tnode;

    #ifndef _TREE_C_
        Tnode* ABPCreate();
        int ABPDestroy(Tnode *root);
        Tnode *ABPInsert(Tnode *root, void *data, void* key, int(*cmp)(void*, void*));
        void *ABPQuery(Tnode* root, void* key, int(*cmp)(void*, void*));
        void *ABPBigger(Tnode *root);
        Tnode *ABPRemove(Tnode *root, void *key, int(*cmp)(void*, void*));
        void treePreOrdem(Tnode *root, void(*visit)(void*));
        void treePosOrdem(Tnode *root, void(*visit)(void*));
        void treeSimetria(Tnode *root, void(*visit)(void*));
        int ABPContaNo(Tnode *t);
        int ABPContaOneSon(Tnode *root);
    #else
        extern Tnode* ABPCreate();
        extern int ABPDestroy(Tnode *root);
        extern Tnode *ABPInsert(Tnode *root, void *data, void* key, int(*cmp)(void*, void*));
        extern void *ABPQuery(Tnode* root, void* key, int(*cmp)(void*, void*));
        extern void *ABPBigger(Tnode *root);
        extern Tnode *ABPRemove(Tnode *root, void *key, int(*cmp)(void*, void*));
        extern void treePreOrdem(Tnode *root, void(*visit)(void*));
        extern void treePosOrdem(Tnode *root, void(*visit)(void*));
        extern void treeSimetria(Tnode *root, void(*visit)(void*));
        extern int ABPContaNo(Tnode *t);
        extern int ABPContaOneSon(Tnode *root);
    #endif
#endif