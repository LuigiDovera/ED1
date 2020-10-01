#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int tipoDeMatriz(int *va int m, int n){
    int aux=0;
    if(m==n){
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(va[i*m+j]==va[j*n+i]){
                    aux++;
                }
            }
        }
        if(aux==m*n){
            aux=0;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(va[i*m+i]!=0 || (i!=j && va[i*m+j]==0) ) {
                        aux++;
                    }
                }
            }
            if(aux==m*n){
                return 2;
            }
            return 1;
        }
        return 0;
    }
    return 3;
    
}

int main()
{

    return 0;
}