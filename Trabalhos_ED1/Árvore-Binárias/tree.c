#define _TREE_C_

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Tnode* ABPCreate(){
  Tnode *root;
  root = (Tnode*)malloc(sizeof(Tnode));
  if (root != NULL){
    root->left = NULL;
    root->right = NULL;
    root->data = NULL;
    return root;
  }
  return NULL;
}

int ABPDestroy(Tnode *root){
  if (root->left == NULL && root->right == NULL){
    free(root);
    return true;
  } else {
    return false;
  }
}

Tnode *ABPInsert(Tnode *root, void *data, void* key, int(*cmp)(void*, void*)){
  Tnode *newTnode;
  
  if (root != NULL){
    int stat = cmp(key, root->data);
    if (stat<0){
      root->left = ABPInsert(root->left, data, key, cmp);
    }else{
      root->right = ABPInsert(root->right, data, key, cmp);
    }
    return root;
  } else {
    newTnode = (Tnode*)malloc(sizeof(Tnode));
    if (newTnode != NULL){
      newTnode->data = data;
      newTnode->left = NULL;
      newTnode->right = NULL;
      return newTnode;
    }
    return NULL;
  }

}

void *ABPQuery(Tnode* root, void* key, int(*cmp)(void*, void*)){
  if (root != NULL){
    int stat = cmp(key, root->data); 
    if (stat == 0){
      return root->data;
    } else if (stat <= 0){
      return ABPQuery(root->left, key, cmp);
    } else {
      return ABPQuery(root->right, key, cmp);
    }
  }
  return NULL;
}

void *ABPBigger(Tnode *root){
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

Tnode *ABPRemove(Tnode *root, void *key, int(*cmp)(void*, void*)){
  Tnode *aux;
  void *data;

  if (root != NULL){
    if (cmp(key, root->data) == -1){
      root->left = ABPRemove(root->left, key, cmp);
      return root;
    } else if (cmp(key, root->data) == 1){
      root->right = ABPRemove(root->right, key, cmp);
      return root;
    } else {
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
        root->data = ABPBigger(root->left);
        ABPRemove(root->left, root->data, cmp);
        return root;
      }
    }
  }
  
  return NULL;
}

void treePreOrdem(Tnode *root, void(*visit)(void*)){

  if (root != NULL){

    visit(root->data);
    treePreOrdem(root->left, visit);
    treePreOrdem(root->right, visit);

  }

}

void treePosOrdem(Tnode *root, void(*visit)(void*)){
  if (root != NULL){
    treePosOrdem(root->left, visit);
    treePosOrdem(root->right, visit);
    visit(root->data);
  }

}

void treeSimetria(Tnode *root, void(*visit)(void*)){
  if (root != NULL){
    treeSimetria(root->left, visit);
    visit(root->data);
    treeSimetria(root->right, visit);
  }
}

int ABPContaNo(Tnode *root){
  int nL=0, nR=0;
  if(root!=NULL){
    nL = ABPContaNo(root->left);
    nR = ABPContaNo(root->right);
    return 1 + nL + nR;
  }
  return 0;
}

void TnodeLiberaNo(Tnode *t){
  if(t == NULL){
    return;
  }
  TnodeLiberaNo(t->left);
  TnodeLiberaNo(t->right);
  free(t);
  t = NULL;
}

void TnodeLiberaRaiz(Tnode *t){
  if(t == NULL){
    return;
  }
  TnodeLiberaNo(&(*t));
  free(t);
}

int TnodeAltura(Tnode *t){
  if(t!=NULL){
    
    if(t->left == NULL && t->right == NULL){
      return 0;
    }

    int alt_esq = TnodeAltura(t->left);
    int alt_dir = TnodeAltura(t->right);
    
    if(alt_esq > alt_dir){
      return(alt_esq);
    }else{
      return (alt_dir);
    }
  }

  return 0;
}

int numMaiores(Tnode *t, int n, void(*visit)(void*), int(*cmp)(void*, void*)){
  
  if(t!=NULL){
    
    // visit(root->data);
    int mEsq, mDir, comp = 0;
    mEsq = numMaiores(t->left, n, visit, cmp);
    mDir = numMaiores(t->right, n, visit, cmp);
    if(cmp( (void*)n, t->data ) == -1){
      comp = 1;
    }else{
      comp = 0;
    }
    return comp + mDir + mEsq;
  }
  return 0;
}
