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

    //Testa Arquivo//
    if (arqMA == NULL) {
       printf("Erro: Nao foi possivel abrir o arquivo da matriz A!!!\n");
       fclose(arqMA);
    } 

    if (arqMB == NULL) {
       printf("Erro: Nao foi possivel abrir o arquivo da matriz B!!!\n");
       fclose(arqMB);
    } 
    /////////////// 

    //Lê primeira linha 0 do arquivo(MA) obtem o numero de linhas e colunas da matriz//
    fscanf(arqMA, "%d %d", &linhasA ,&colunasA);
    Vma = AlocVMat(linhasA, colunasA);
    //Lê matriz A completa//
    for (i = 0;i<linhasA;i++){
        for(j = 0;j<colunasA;j++){
            fscanf(arqMA,"%f ", &Vma[i*colunasA+j]);
        }
    }
    fclose(arqMA);

    //Lê primeira linha 0 do arquivo(MB) obtem o numero de linhas e colunas da matriz//
    fscanf(arqMB, "%d %d", &linhasB ,&colunasB);
    Vmb = AlocVMat(linhasB, colunasB);
    //Lê matriz B completa//
    for (i = 0;i<linhasB;i++){
        for(j = 0;j<colunasB;j++){
            fscanf(arqMB,"%f ", &Vmb[i*colunasB+j]);
        }
    }
    fclose(arqMB);

    //Menu principal recebendo os devidos parametros//
    menu(linhasA, colunasA, linhasB, colunasB, Vma, Vmb);

    //Liberar memória alocada//
    FreeMat(Vma);
    FreeMat(Vmb);
          
}

//FUNÇÃO MENU RECEBE LINHAS A/COLUNAS DE A, LINHAS DE B/COLUNAS DE B
//E AS MATRIZES A E B PARA SEREM PROCESSADAS NAS OUTRAS FUNÇÕES//
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

//FUNÇÃO PARA PRINTAR AS MATRIZES TODAS VEZ QUE ALGUMA OPERAÇÃO FOR FEITA COM ELAS//
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
    printf("===============Matriz A=================\n\n");
    //Print Matriz B//
    printf("===============Matriz B=================\n");
    for(i=0;i<q;i++){
        for(j=0;j<q;j++){
            printf("%.3f ", mb[i*m+j]);
        }
        putchar('\n');
    }
    printf("===============Matriz B=================\n");
    putchar('\n');    
}

//FUNÇÃO PARA ALOCAR UMA MATRIZ DINAMICAMENTE DENTRO DE UM VETOR//
//RETORNA UMA MATRIZ ALOCADA;
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

//FUNÇÃO QUE IMPRIME O PRODUTO DA MATRIZ A X B, TESTANDO SE AS COLUNAS DE A == LINHAS DE B//
//RETORNA 0 SE A OPERAÇÃO NÃO FOR POSSIVEL//
//RETORNA 1 SE A OPERAÇÃO FOI UM SUCESSO//
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
        printf("==========Matriz Produto AXB===========\n");
        putchar('\n');
        system("PAUSE");
        free(mc);
        return 0;
    }
    printf("A multiplicacao nao e possivel pois, colunas de A != linhas de B\n");
    system("PAUSE");
    return 0;
}

//FUNÇÃO QUE IMPRIME O PRODUTO DA MATRIZ A X B(TRANSPOSTA), TESTANDO SE AS COLUNAS DE A == LINHAS DE B E SE É POSSÍVEL TRANSPOR B//
//RETORNA 0 SE A OPERAÇÃO NÃO FOR POSSIVEL//
//RETORNA 1 SE A OPERAÇÃO FOI UM SUCESSO//
int ProdAxBT(int n, int m, int p, int q, float *ma, float *mb){
    int i, j, k;
    float *mbT = Transposta(p, q, mb);
    float *mc;
    int sum = 0;

    if(m==p){
        mc = AlocVMat(n, q);
        if(mc!=NULL){
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
            printf("==========Matriz Produto AXBT===========\n");
            system("PAUSE");
            putchar('\n');
            free(mbT);
            free(mc);
            return 1;
        }
        free(mc);
    }

    printf("\tA multiplicacao nao e possivel pois, colunas de A != linhas de B\n");
    system("PAUSE");
    free(mbT);
    return 0;
}

//TRANSPÕE E RETORNA A MATRIZ RECEBIDA COMO PARAMETRO(float *ma)//
float *Transposta(int n, int m, float *ma){
   float *maT;
   int i, j;
   if (ma!=NULL){
      maT = (float *) malloc(n*m * sizeof(float));
        if (maT!=NULL) {
            for(i = 0;i<n;i++){
                for(j=0;j<m;j++){
                    maT[i*m+j] = ma[j*m+i];
                }
            }
            putchar('\n');

            printf("==========Matriz Transposta===========\n");
            for(i = 0;i<n;i++){
                for(j=0;j<m;j++){
                    printf("%.2f ", maT[i*m+j]);
                }
                putchar('\n');
            }
            putchar('\n');
            system("PAUSE");
            putchar('\n');
            return maT;
        }
   }

   printf("Nao foi possivel transpor a matriz, pois o numero de linhas != colunas!!!\n");
   return NULL;
   
}

//IMPRIME NA TELA OS ELEMENTOS DA TRIANGULAR SUP DE A, OU SEJA, TODOS ELEM ONDE J>I//
int TriangularSup(int n, float *vma){
   int i, j;
    if(vma!=NULL){
        printf("=======ELEMENTOS DA TRIANGULAR de A=======\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(j>i){
                    printf("%.2f[%d][%d]\n", vma[i*n+j], i, j);
                }
            }
        }
        system("PAUSE");
        return 1;
    }
   return 0;
}

//IMPRIME NA TELA OS ELEMENTOS DA DIAGONAL PRINCIPAL DE A, OU SEJA, TODOS ELEM ONDE I == J//
int DiagonalP(int n, int m, float *ma){
    int i, j;
    if(ma!=NULL && n==m){
        //Recebendo elementos da Diagonal  e armazenando num array de tamanho [m]//
        printf("=======ELEMENTOS DA DIAGONAL P. de A=======\n");
        for(i = 0; i<n;i++){
            for(j = 0; j<m;j++) {
                if(i==j) {
                    printf("%.2f[%d][%d]\n", ma[i*m+j], i, j);
                }
            }
        }
        system("PAUSE");
        return 1;
    }
    printf("ERRO, function DiagonalP()\nMatriz N e QUADRADA!!!\n");
    return 0;

}

//IMPRIME NA TELA TODOS OS ELEMENTOS DA LINHA REQUISITADA PELO USER USANDO UMA ENTRADA DO TECLADO PASSA PARA A VARIAVEL K//
int RetornaLinha(int n, int m, float *vma, int k){
    int i, j;
    if(vma != NULL && n>0 && m>0 && n >= k){
        for(i = 0; i<n ;i++) {
            for(j = 0; j<m ;j++) {
                if (i == k) {
                    printf("%.2f[%d][%d]\n", vma[i*m+j], i, j);
                }
            }
        }
        system("PAUSE");
        return 1;
    }
    return 0;
}

//IMPRIME NA TELA TODOS OS ELEMENTOS DA COLUNA REQUISITADA PELO USER USANDO UMA ENTRADA DO TECLADO PASSA PARA A VARIAVEL K//
int RetornaColuna(int n, int m, float *vma, int k){
    int i, j;
    if(vma != NULL && n>0 && m>0 && n >= k){
        for(i = 0; i<n ;i++){
            for(j = 0; j<m ;j++){
                if (j == k){
                    printf("%.2f[%d][%d]\n", vma[i*m+j], i, j);
                }
            }
        }
        system("PAUSE");
        return 1;
    }

    return 0;
}

//LIBERA MEMORIA ALOCADA PELAS MATRIZES//
float *FreeMat(float *vmat) {
   free(vmat);
   printf("Liberou\n");
   return NULL;   
}

