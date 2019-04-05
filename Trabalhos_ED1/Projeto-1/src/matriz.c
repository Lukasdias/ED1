#include "../header/matriz.h"

//FUNÇÃO PRINCIPAL ONDE TODAS AS FUNÇÕES SÃO CHAMADAS DENTRO DA FUNÇÃO MENU//
int LerMa() {
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

    if(linhasA < 0 || linhasB < 0 || colunasA < 0 || colunasB < 0){
        printf("\t FAVOR CHECAR ARQ, POIS NUMERO D LINHAS/COLUNAS CONSTA COMO NEGATIVO!!!\n");
        FreeMat(Vma);
        FreeMat(Vmb);
        return 0;
    }

    //Menu principal recebendo os devidos parametros//
    menu(linhasA, colunasA, linhasB, colunasB, Vma, Vmb);

    //Liberar memória alocada//
    FreeMat(Vma);
    FreeMat(Vmb);
    return 1;
}

//FUNÇÃO MENU RECEBE LINHAS A/COLUNAS DE A, LINHAS DE B/COLUNAS DE B E AS MATRIZES A E B PARA SEREM PROCESSADAS NAS OUTRAS FUNÇÕES//
//PARAMETROS ADQUIRIDOS NA FUNÇÃO LerMa//
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
                printf("\t Insira a linha de A a ser usada: ");
                scanf("%d", &k);
                fflush(stdin);
                RetornaLinha(n, m, vmA, k);
                break;
            case 7:
                printAB(n, m, p, q, vmA, vmB);
                printf("\t Insira a coluna de A a ser usada: ");
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
    printf("\t ===============Matriz A=================\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("\t %.2f ", ma[i*m+j]);
        }
        putchar('\n');
    }
    printf("\t ===============Matriz A=================\n\n");

    //Print Matriz B//
    printf("\t ===============Matriz B=================\n");
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            printf("\t %.2f ", mb[i*q+j]);
        }
        putchar('\n');
    }
    printf("\t ===============Matriz B=================\n");
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
    float aux = 0;
    
    if(m==p){
        mc = AlocVMat(n, q);
        for(i=0;i<n;i++){
            for(j=0;j<q;j++){
                for(k=0;k<m;k++){
                    aux += ma[i*m+k] * mb[k*q+j];
                } 
                 mc[i*q+j] = aux;
                 aux = 0;
            }
        }
        printf("\t ==========Matriz Produto AXB===========\n");
        for(i=0;i<n;i++){
            for(j=0;j<q;j++){
                printf("\t %.2f ", mc[i*q+j]);
            }
            putchar('\n');
        }
        printf("\t ==========Matriz Produto AXB===========\n");
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
    printf("\t ========Matriz TRANSPOSTA DE B=========\n");
    float *mbT = Transposta(p, q, mb);
    float *mc;
    float aux = 0;

    //TRANPOSTA -> P SERÁ TROCADO POR Q, JÁ QUE B FOI TRANSPOSTA//
    if(m==q){
        mc = AlocVMat(n, q);
        if(mc!=NULL){
            for(i=0;i<n;i++){
                for(j=0;j<p;j++){
                    for(k=0;k<p;k++){
                        aux += ma[i*m+k] * mbT[k*p+j];
                    }
                    mc[i*p+j] = aux;
                    aux = 0;
                }
            }
            printf("\t ==========Matriz Produto AXBT===========\n");
            for(i=0;i<n;i++){
                for(j=0;j<p;j++){
                    printf("\t %.2f ", mc[i*p+j]);
                }
                putchar('\n');
            }
            printf("\t ==========Matriz Produto AXBT===========\n");
            system("PAUSE");
            putchar('\n');
            free(mbT);
            free(mc);
            return 1;
        }
        free(mc);
    }

    printf("\t A multiplicacao nao e possivel pois, colunas de A != linhas de B(TRANSPOSTA)\n");
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
            for(i = 0;i<m;i++){
                for(j=0;j<n;j++){
                    maT[i*n+j] = ma[j*m+i];
                }
            }
            putchar('\n');

            printf("\t ==========Matriz Transposta===========\n");
            for(i = 0;i<m;i++){
                for(j=0;j<n;j++){
                    printf("\t %.2f ", maT[i*n+j]);
                }
                putchar('\n');
            }
            printf("\t ==========Matriz Transposta===========\n");
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

    if(n<0){
        printf("Numero de linhas/colunas = invalido\n");
        system("PAUSE");
        return 0;
    }

    if(vma!=NULL){
        printf("\t =======ELEMENTOS DA TRIANGULAR de A=======\n");
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(j>i){
                    printf("\t %.2f[%d][%d]\n", vma[i*n+j], i, j);
                }
            }
        }
        printf("\t =======ELEMENTOS DA TRIANGULAR de A=======\n");
        system("PAUSE");
        return 1;
    }
   return 0;
}

//IMPRIME NA TELA OS ELEMENTOS DA DIAGONAL PRINCIPAL DE A, OU SEJA, TODOS ELEM ONDE I == J//
int DiagonalP(int n, int m, float *ma){
    int i, j;
    if(n<0 || m<0){
        printf("Numero de linhas/colunas = invalido\n");
        system("PAUSE");
        return 0;
    }
    
    if(ma!=NULL && n==m){
        //Recebendo elementos da Diagonal  e armazenando num array de tamanho [m]//
        printf("\t =======ELEMENTOS DA DIAGONAL P. de A=======\n");
        for(i = 0; i<n;i++){
            for(j = 0; j<m;j++) {
                if(i==j) {
                    printf("\t %.2f[%d][%d]\n", ma[i*m+j], i, j);
                }
            }
        }
        printf("\t =======ELEMENTOS DA DIAGONAL P. de A=======\n");
        system("PAUSE");
        return 1;
    }
    printf("ERRO, function DiagonalP()\nMatriz N e QUADRADA!!!\n");
    system("PAUSE");
    return 0;
}

//IMPRIME NA TELA TODOS OS ELEMENTOS DA LINHA REQUISITADA PELO USER USANDO UMA ENTRADA DO TECLADO PASSA PARA A VARIAVEL K//
int RetornaLinha(int n, int m, float *vma, int k){
    int i, j;
    if(k > n){
        printf("K e maior que o numero de linhas, favor digitar novamente\n");
        system("PAUSE");
        return 0;
    }

    printf("\t =======ELEMENTOS DA LINHA K(%d) A=======\n", k);
    if(vma != NULL && n>0 && m>0 && n >= k){
        for(i = 0; i<n ;i++) {
            for(j = 0; j<m ;j++) {
                if (i == k) {
                    printf("\t %.2f[%d][%d]\n", vma[i*m+j], i, j);
                }
            }
        }
        printf("\t =======ELEMENTOS DA LINHA K(%d) A=======\n", k);
        system("PAUSE");
        return 1;
    }
    return 0;
}

//IMPRIME NA TELA TODOS OS ELEMENTOS DA COLUNA REQUISITADA PELO USER USANDO UMA ENTRADA DO TECLADO PASSA PARA A VARIAVEL K//
int RetornaColuna(int n, int m, float *vma, int k){
    int i, j;

    if(k > m){
        printf("K e maior que o numero de colunas, favor digitar novamente\n");
        system("PAUSE");
        return 0;
    }

    printf("\t =======ELEMENTOS DA COLUNA K(%d) A=======\n", k);
    if(vma != NULL && n>0 && m>0 && n >= k){
        for(i = 0; i<n ;i++){
            for(j = 0; j<m ;j++){
                if (j == k){
                    printf("\t %.2f[%d][%d]\n", vma[i*m+j], i, j);
                }
            }
        }
        printf("\t =======ELEMENTOS DA COLUNA K(%d) A=======\n", k);
        system("PAUSE");
        return 1;
    }

    return 0;
}

//LIBERA MEMORIA ALOCADA PELAS MATRIZES//
float *FreeMat(float *vmat) {
   if(vmat!=NULL){
       free(vmat);
       printf("\t Liberou\n");
       return NULL;
   }
   return NULL;   
}

