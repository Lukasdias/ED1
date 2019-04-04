#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void menu(int, int, int ,int ,float *, float *);
void LerMa();
void printAB(int , int , int , int , float *, float *);
float *AlocVMat(int, int);
float *FreeMat(float *);
int ProdAxB(int , int , int , int , float *, float *);
int ProdAxBT(int , int , int , int , float *, float *);
float *Transposta(int , int , float *);
int TriangularSup(int, float *);
int DiagonalP(int , int , float *);
int RetornaLinha(int , int , float *, int k);
int RetornaColuna(int , int , float *, int );
float *FullVmat(int, int, float *,FILE *);