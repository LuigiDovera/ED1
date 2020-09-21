#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int comparaVetorMatriz (int n, int m, int p, float *v, float *ma){
    if (v!=NULL && m!=NULL){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<p; k++){
                    if (v[i]==ma[j*p+k]){
                        printf("Posicao %d do vetor e %d %d da matriz\n", i, j, k);
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
    int n=3, m=2, p=3;
    float *v = (float *) malloc(n*sizeof(float));
    float *ma = (float *) malloc(m*p*sizeof(float));
    
    for(int i=0; i<n; i++){
        v[i]=i+3;
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<p; j++){
            ma[i*p+j]=i*p+j;
        }
    }

    comparaVetorMatriz(n, m, p, v, ma); 
    printf("aaa");    
    return 0;
}
