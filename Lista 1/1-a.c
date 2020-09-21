#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int comparaVetorMatriz (int n, int m, int p, float *v, float **ma){
    if (v!=NULL && m!=NULL){
        for(int i=0; i<m; i++){
            if(ma[i]==NULL){
                printf("Vetor da matriz não existente.\n");
                return FALSE;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<p; k++){
                    if (v[i]==ma[j][k]){
                        printf("Posicao %d do vetor\n", i);
                    }
                }
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
    int n=3, m=3, p=3;
    float *v = (float *) malloc(n*sizeof(float));
    float **ma = (float **) malloc(m*sizeof(float*));
    for(int i=0; i<m; i++){
        ma[i] = (float *) malloc(p*sizeof(float));
    }
    for(int i=0; i<n; i++){
        v[i]=i;
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<p; j++){
            ma[i][j]=i+j;
        }
    }
    comparaVetorMatriz(n, m, p, v, ma); 
    printf("aaa");    
    return 0;
}
