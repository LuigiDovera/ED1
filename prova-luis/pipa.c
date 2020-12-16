#include <stdlib.h>
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int i, asteriscos = 2;
    for (i=0; i<n; i++){
        int j;
        for(j=0; j<n-i-1; j++){
            printf(" ");
        }
        int k;
        for(k=0; k<asteriscos; k++){
            printf("*");
        }
        printf("\n");
        asteriscos+=4;
    }
    asteriscos-=8;
    for (i=0; i<n; i++){
        int j;
        for(j=0; j<i+1; j++){
            printf(" ");
        }
        int k;
        for(k=0; k<asteriscos; k++){
            printf("*");
        }
        printf("\n");
        asteriscos-=4;
    }
    return 0;
}
