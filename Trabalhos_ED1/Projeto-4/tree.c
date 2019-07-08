#define _TREE_C_

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node* BSTreeCreate(){
  Node *root;
  root = (Node*)malloc(sizeof(Node));
  if (root != NULL){
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  return NULL;
}

int BSTreeDestroy(Node *root){
  if (root->left == NULL && root->right == NULL){
    free(root);
    return true;
  } else {
    return false;
  }
}

Node *BSTreeInsert(Node *root, void *data, void* key, int(*cmp)(void*, void*)){
  Node *newnode;
  
  if (root != NULL){
    if (cmp(key, root->data) < 0){
      root->left = BSTreeInsert(root->left, data, key, cmp);
    } else {
      root->right = BSTreeInsert(root->right, data, key, cmp);
    }
    return root;
  } else {
    newnode = (Node*)malloc(sizeof(Node));
    if (newnode != NULL){
      newnode->left = NULL;
      newnode->right = NULL;
      newnode->data = data;
      return newnode;
    }
    return NULL;
  }

}

void *BSTreeQuery(Node* root, void* key, int(*cmp)(void*, void*)){
  if (root != NULL){
    if (cmp(key, root->data) == 0){
      return root->data;
    } else if (cmp(key, root->data) < 0){
      return BSTreeQuery(root->left, key, cmp);
    } else {
      return BSTreeQuery(root->right, key, cmp);
    }
  }
  return NULL;
}

void *BSTreeBigger(Node *root){
  void *data;
  if (root != NULL){
    while (root->right != NULL){
      data = root->data;
      root = root->right;
    }
    return data;
  }
  return NULL;
}

Node *BSTreeRemove(Node *root, void *key, int(*cmp)(void*, void*)){
  Node *aux;
  void *data;
  if (root != NULL){
    if (cmp(key, root->data) == -1){
      root->left = BSTreeRemove(root->left, key, cmp);
      return root;
    }else if (cmp(key, root->data) == 1){
      root->right = BSTreeRemove(root->right, key, cmp);
      return root;
    }else {
      data = root->data;
      if (root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
      } else if (root->left != NULL && root->right == NULL){
        aux = root->left;
        free(root);
        return aux;
      } else if (root->left == NULL && root->right != NULL){
        aux = root->right;
        free(root);
        return aux;
      } else {
        root->data = BSTreeBigger(root->left);
        BSTreeRemove(root->left, root->data, cmp);
        return root;
      }
    }
  }

  return NULL;
}

void treePreOrdem(Node *root, void(*visit)(void*)){

  if (root != NULL){

    visit(root->data);
    treePreOrdem(root->left, visit);
    treePreOrdem(root->right, visit);

  }

}

void treePosOrdem(Node *root, void(*visit)(void*)){
  if (root != NULL){
    treePosOrdem(root->left, visit);
    treePosOrdem(root->right, visit);
    visit(root->data);
  }

}

void treeSimetria(Node *root, void(*visit)(void*)){
  if (root != NULL){
    treePosOrdem(root->left, visit);
    visit(root->data);
    treePosOrdem(root->right, visit);
  }
}

int BSTreeContaNo(Node *root){
  int nL, nR;
  if(root!=NULL){
    nL = BSTreeContaNo(root->left);
    nR = BSTreeContaNo(root->right);
    return 1 + nL + nR;
  }
  return 0;
}
