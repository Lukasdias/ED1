#include "../header/matriz.h"

void LerMa() {
    FILE *arqMA;
    FILE *arqMB;

    int i, j;
    int linhasA, colunasA;
    int linhasB, colunasB;
    float *Vma, *Vmb;

    //Abre ARQUIVO///
    arqMA = fopen("docs/matriz_a.txt","r");
    arqMB = fopen("docs/matriz_b.txt","r");

    if (arqMA == NULL) {
       printf("Erro: Nao foi possivel abrir o arquivo da matriz A!!!\n");
       fclose(arqMA);
    } 

    if (arqMB == NULL) {
       printf("Erro: Nao foi possivel abrir o arquivo da matriz B!!!\n");
       fclose(arqMB);
    } 

    //Lê primeira linha do arquivo(MA) obtem o numero de linhas e colunas da matriz//
    fscanf(arqMA, "%d %d", &linhasA ,&colunasA);
    Vma = AlocVMat(linhasA, colunasA);
    for (i = 0;i<linhasA;i++){
        for(j = 0;j<colunasA;j++){
            fscanf(arqMA,"%f ", &Vma[i*colunasA+j]);
        }
    }
    fclose(arqMA);

    //Lê primeira linha do arquivo(MB) obtem o numero de linhas e colunas da matriz//
    fscanf(arqMB, "%d %d", &linhasB ,&colunasB);
    Vmb = AlocVMat(linhasB, colunasB);
    for (i = 0;i<linhasB;i++){
        for(j = 0;j<colunasB;j++){
            fscanf(arqMB,"%f ", &Vmb[i*colunasB+j]);
        }
    }
    fclose(arqMB);

    menu(linhasA, colunasA, linhasB, colunasB, Vma, Vmb);

    FreeMat(Vma);
    FreeMat(Vmb);
          
}

void menu(int n, int m, int p, int q, float *vmA, float *vmB) {
    int condit = 1, k;
    while (condit!=0) {
         system("cls");
         printf("==================================MENU MATRIZ===================================\n");
         printf("\t [1] *** A x B\n");
         printf("\t [2] *** A x B(transposta)\n");
         printf("\t [3] *** A(transposta)\n");
         printf("\t [4] *** Triangular Superior de A\n");
         printf("\t [5] *** Diagonal de A\n");
         printf("\t [6] *** Linha K de A\n");
         printf("\t [7] *** Coluna K de A\n");
         printf("\t [0] *** Sair\n");
         printf("================================================================================\n");
         printf("\t Sua Escolha: ");
         scanf("%d", &condit);
         fflush(stdin);

        switch (condit) {
            case 1:
                printAB(n, m, p, q, vmA, vmB);
                ProdAxB(n, m, p, q, vmA, vmB);
                break;
            case 2:
                printAB(n, m, p, q, vmA, vmB);
                ProdAxBT(n, m, p, q, vmA, vmB);
                break;
            case 3:
                printAB(n, m, p, q, vmA, vmB);
                float *mat = AlocVMat(n, m);
                mat = Transposta(n, m, vmA);
                FreeMat(mat);
                break;
            case 4:
                printAB(n, m, p, q, vmA, vmB);
                TriangularSup(n, vmA);
                break;
            case 5:
                printAB(n, m, p, q, vmA, vmB);
                DiagonalP(n, m, vmA);
                break;
            case 6:
                printAB(n, m, p, q, vmA, vmB);
                printf("Insira a linha de A a ser usada: ");
                scanf("%d", &k);
                fflush(stdin);
                RetornaLinha(n, m, vmA, k);
                break;
            case 7:
                printAB(n, m, p, q, vmA, vmB);
                printf("Insira a coluna de A a ser usada: ");
                scanf("%d", &k);
                fflush(stdin);
                RetornaColuna(n, m, vmA, k);
                break;
            case 0:
                condit = 0;
                break;
            default:
                break;
        }
    }
}

void printAB(int n, int m, int p, int q, float *ma, float *mb){
    int i, j;
    
    //Print Matriz A//
    printf("===============Matriz A=================\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%.3f ", ma[i*m+j]);
        }
        putchar('\n');
    }

    //Print Matriz B//
    printf("===============Matriz B=================\n");
    for(i=0;i<q;i++){
        for(j=0;j<q;j++){
            printf("%.3f ", mb[i*m+j]);
        }
        putchar('\n');
    }

    system("PAUSE");
}

float *AlocVMat(int linhas, int colunas) {
   float *vmat;
   if ((linhas < 1) || (colunas < 1)) return NULL;
   vmat = (float *) malloc(linhas*colunas * sizeof(float));
   if (vmat == NULL) {
      printf("\nFatal Error! (function: AlocMat)\n");
      exit(1);
   }
   return vmat;
}

int ProdAxB(int n, int m, int p, int q, float *ma, float *mb){
    int i, j, k;
    float *mc;
    int sum = 0;
    if(m==p){
        mc = AlocVMat(n, q);
        for(i=0;i<n;i++){
            for(j=0;j<q;j++){
                for(k=0;k<n;k++){
                    sum += ma[i*q+k] * mb[k*q+j];
                }
                 mc[i*q+j] = sum;
                 sum = 0;
            }
        }
        printf("==========Matriz Produto AXB===========\n");
        for(i=0;i<n;i++){
            for(j=0;j<q;j++){
                printf("%.2f ", mc[i*m+j]);
            }
            putchar('\n');
        }
        system("PAUSE");
        free(mc);
        return 0;
    }
    printf("\tA multiplicacao nao e possivel pois, colunas de A != linhas de B\n");
    system("PAUSE");
    return 0;
}

int ProdAxBT(int n, int m, int p, int q, float *ma, float *mb){
    int i, j, k;
    float *mbT = Transposta(p, q, mb);
    float *mc;
    int sum = 0;

    if(m==p){
        mc = AlocVMat(n, q);
        for(i=0;i<n;i++){
            for(j=0;j<q;j++){
                for(k=0;k<n;k++){
                    sum += ma[i*q+k] * mbT[k*q+j];
                }
                 mc[i*q+j] = sum;
                 sum = 0;
            }
        }
        printf("==========Matriz Produto AXBT===========\n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                printf("%.2f ", mc[i*m+j]);
            }
            putchar('\n');
        }

        system("PAUSE");
        free(mbT);
        free(mc);
        return 0;
    }
    printf("\tA multiplicacao nao e possivel pois, colunas de A != linhas de B\n");
    system("PAUSE");
    free(mbT);
    return 0;
}

float *Transposta(int n, int m, float *ma){
   float *maT;
   int i, j;
   if (ma!=NULL && n == m){
      maT = (float *) malloc(n*m * sizeof(float));
      if (maT!=NULL){
         for(i = 0;i<n;i++){
            for(j=0;j<m;j++){
               maT[i*m+j] = ma[j*m+i];
            }
         }
         printf("==========Matriz Transposta===========\n");
         for(i = 0;i<n;i++){
            for(j=0;j<m;j++){
               printf("%.2f ", maT[i*m+j]);
            }
            putchar('\n');
         }
         putchar('\n');
         system("PAUSE");
         return maT;
      }
   }
   printf("Nao foi possivel transpor a matriz, pois o numero de linhas != colunas!!!\n");
   return NULL;
   
}

int TriangularSup(int n, float *vma){
   int i, j, k = 0, cont = 0;
   float *vT;
   if(vma!=NULL){
      for(i=0;i<n;i++){
         for(j=0;j<n;j++){
            if(j > i){
               cont++;
            }
         }
      }
      vT = (float *) malloc (cont*sizeof(float));
      for(i=0;k<cont;i++){
         for(j=0;j<n;j++){
            if(j>i){
               vT[k] = vma[i*n+j];
               k++;
            }
         }
      }
      for(i=0;i<cont;i++){
         printf("%.2f[%d]\n", vT[i], i);
      }
      system("PAUSE");
      FreeMat(vT);
      return 1;
   }
   return 0;
}

int DiagonalP(int n, int m, float *ma){
    int i, j;
   if((ma == NULL)){
      return 0;
   }

   float *v;
   v = (float *) malloc(m*sizeof(float));
   if(v != NULL){
      for(i = 0; i<n;i++){
        for(j = 0; j<m;j++) {
            if(i==j) {
                v[i] = ma[i*m+j];
            }
        }
      }

      for(i=0;i<m;i++){
          printf("%.2f[%d]\n", v[i], i);
      }
      system("PAUSE");
      FreeMat(v);
      return 1;
   }
   return 0;

}

int RetornaLinha(int n, int m, float *vma, int k){
    int i, j;
   if(vma != NULL && n>0 && m>0 && n >= k){
        for(i = 0; i<n ;i++){
            for(j = 0; j<m ;j++){
                if (i == k){
                    printf("%.2f\n", vma[i*m+j]);
                }
            }
        }
        system("PAUSE");
        return 1;
   }
    return 0;
}

int RetornaColuna(int n, int m, float *vma, int k){
    int i, j;
   if(vma != NULL && n>0 && m>0 && n >= k){
        for(i = 0; i<n ;i++){
            for(j = 0; j<m ;j++){
                if (j == k){
                    printf("%.2f\n", vma[i*m+j]);
                }
            }
        }
        system("PAUSE");
        return 1;
   }
    return 0;
}

float *FreeMat(float *vmat) {
   free(vmat);
   printf("Liberou\n");
   return NULL;   
}

