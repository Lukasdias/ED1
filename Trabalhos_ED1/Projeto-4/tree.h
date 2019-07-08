#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

typedef struct _treenode_{
    struct _treenode_ *left;
    struct _treenode_ *right;
    void *data;
}Node;

    #ifndef _TREE_C_
        Node* BSTreeCreate();
        int BSTreeDestroy(Node *root);
        Node *BSTreeInsert(Node *root, void *data, void* key, int(*cmp)(void*, void*));
        void *BSTreeQuery(Node* root, void* key, int(*cmp)(void*, void*));
        void *BSTreeBigger(Node *root);
        Node *BSTreeRemove(Node *root, void *key, int(*cmp)(void*, void*));
        void treePreOrdem(Node *root, void(*visit)(void*));
        void treePosOrdem(Node *root, void(*visit)(void*));
        void treeSimetria(Node *root, void(*visit)(void*));
        int BSTreeContaNo(Node *t);
    #else
        extern Node* BSTreeCreate();
        extern int BSTreeDestroy(Node *root);
        extern Node *BSTreeInsert(Node *root, void *data, void* key, int(*cmp)(void*, void*));
        extern void *BSTreeQuery(Node* root, void* key, int(*cmp)(void*, void*));
        extern void *BSTreeBigger(Node *root);
        extern Node *BSTreeRemove(Node *root, void *key, int(*cmp)(void*, void*));
        extern void treePreOrdem(Node *root, void(*visit)(void*));
        extern void treePosOrdem(Node *root, void(*visit)(void*));
        extern void treeSimetria(Node *root, void(*visit)(void*));
        extern int BSTreeContaNo(Node *t);
    #endif
#endif