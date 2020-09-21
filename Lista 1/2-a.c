#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int multMatriz (int m, int n, int p, int q, float **ma, float **mb){
    int aux=0;

    //teste das matrizes parametro
    if (ma!=NULL && mb!=NULL){
        for(int i=0; i<m; i++){
            if(ma[i]==NULL){
                printf("Vetor da matriz não existente.\n");
                return FALSE;
            }
        }
        for(int i=0; i<p; i++){
            if(mb[i]==NULL){
                printf("Vetor da matriz não existente.\n");
                return FALSE;
            }
        }

        //coluna de A precisa ser igual a linha de B
        if(n==p){
            //inicialização e teste da matriz resultado
            float **mc = (float **) malloc(m*sizeof(float*));
            for(int i=0; i<m; i++){
                mc[i] = (float *) malloc(q*sizeof(float));
            }
            if (mc!=NULL){
                for(int i=0; i<m; i++){
                    if(mc[i]==NULL){
                        printf("Erro na alocação de matriz.\n");
                        return FALSE;
                    }
                }
            }

            //multiplicação de matrizes
            for(int i=0; i<m; i++){
                for(int j=0; j<q; j++){
                    mc[i][j] = 0;

                    for(int x=0; x<n; x++){
                        aux += ma[i][x] * mb[x][j];
                    }
                    mc[i][j]=aux;
                    aux=0;
                }
            }

            //print da matriz
            for(int i=0; i<m; i++){
                for(int j=0; j<q; j++){
                    printf("%0.f ", mc[i][j]);
                }
                printf("\n");
            }
        }
        return TRUE;
    }
    else {
        printf("Vetor ou Matriz não existentes.\n");
        return FALSE;
    }
}

int main()
{
    int m=2, n=3, p=3, q=2;
    
    float **ma = (float **) malloc(m*sizeof(float*));
    float **mb = (float **) malloc(p*sizeof(float*));

    for(int i=0; i<m; i++){
        ma[i] = (float *) malloc(n*sizeof(float));
    }
    for(int i=0; i<n; i++){
        mb[i] = (float *) malloc(q*sizeof(float));
    }

    /*for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            ma[i][j]=i*n+j;
        }
    }
    for(int i=0; i<p; i++){
        for(int j=0; j<q; j++){
            mb[i][j]=i*q+j;
        }
    }
    */
    ma[0][0] = 2;
    ma[0][1] = 5;
    ma[0][2] = 9;
    ma[1][0] = 3;
    ma[1][1] = 6;
    ma[1][2] = 8;

    mb[0][0] = 2;
    mb[0][1] = 7;
    mb[1][0] = 4;
    mb[1][1] = 3;
    mb[2][0] = 5;
    mb[2][1] = 2;

    multMatriz(m, n, p, q, ma, mb);  
    return 0;
}
