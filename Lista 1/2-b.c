#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int multMatriz (int m, int n, int p, int q, float *ma, float *mb){
    int aux=0;

    //teste das matrizes parametro
    if (ma!=NULL && mb!=NULL){    

        //coluna de A precisa ser igual a linha de B
        if(n==p){
            //inicialização e teste da matriz resultado
            float *mc = (float *) malloc(m*q*sizeof(float));
            
            if (mc==NULL){       
                printf("Erro na alocação de matriz.\n");
                return FALSE;
                    
            }

            //multiplicação de matrizes
            for(int i=0; i<m; i++){
                for(int j=0; j<q; j++){
                    mc[i*q+j]=0;

                    for(int x=0; x<n; x++){
                        aux += ma[i*n+x] * mb[x*q+j];
                    }
                    mc[i*q+j]=aux;
                    aux=0;
                }
            }

            //print da matriz
            for(int i=0; i<m; i++){
                for(int j=0; j<q; j++){
                    printf("%0.f ", mc[i*q+j]);
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
    
    float *ma = (float *) malloc(m*n*sizeof(float));
    float *mb = (float *) malloc(p*q*sizeof(float));

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
    ma[0] = 2;
    ma[1] = 5;
    ma[2] = 9;
    ma[3] = 3;
    ma[4] = 6;
    ma[5] = 8;

    mb[0] = 2;
    mb[1] = 7;
    mb[2] = 4;
    mb[3] = 3;
    mb[4] = 5;
    mb[5] = 2;

    multMatriz(m, n, p, q, ma, mb);  
    return 0;
}
