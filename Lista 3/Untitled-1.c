#include <stdio.h>
#include <stdlib.h>

int compara(int tipo, void *arg1, void *arg2){
    if(tipo==1){
        if( *((int*)arg1) <  *((int*)arg2) ){
            return 0;
        }else if( *((int*)arg1) == *((int*)arg2) ){
            return 1;
        }else{
            return 2;
        }
    }else if(tipo==2){
        if( *((float*)arg1) <  *((float*)arg2) ){
            return 0;
        }else if( *((float*)arg1) == *((float*)arg2) ){
            return 1;
        }else{
            return 2;
        }
    }
}




void recebe(int tipo, void* arg1, void *arg2){
    if (tipo==1){
        *((int*)arg1) = *((int*)arg2);
    }else if(tipo==2){
        *((float*)arg1) = *((float*)arg1)
    }
}



void quicksort (void **vetor, int esq, int dir, int tipo, int (*compara)(void*, void*)){
    int i, j;
    void *x, *y;


    i = esq;
    j = dir;
    recebe(x = vetor[(esq + dir)/2];

    while(i<=j){
        while (compara(tipo, vetor[i], &x) == 0 && i < dir){
            i++;
        }
        while (compara(tipo, vetor[j], &x) == 2 && j > esq){
            j++;
        }
        
        if(i<=j){
            y = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = y;
            i++;
            j--;
        }
    }

    if (j>esq){
        quicksort(vetor, esq, j, tipo, compara);
    }
    if (i<dir){
        quicksort(vetor, i, dir, tipo, compara);
    }


}


int a(int (*compara)(int, void*, void*)){
    int a=2, b=2;
    void *pa=&a, *pb=&b;
    return compara(1, pa, pb);
}

int main(){

    
    int tipo, n;
    void **v;

    
    printf("1-Inteiro 2-Real\n");
    scanf("%d", &tipo);
    printf("Tamanho de n?\n");
    scanf("%d", &n);
    


    
    n=4;
    v = (void **) malloc(n*sizeof(void *));
    
    for(int i=0; i<n; i++){
        v[i] = (int *) malloc(sizeof(int *));
        //*((int*)v[i]) = i;
    }
    *((int*)v[0]) = 3;
    *((int*)v[1]) = 1;
    *((int*)v[2]) = 0;
    *((int*)v[3]) = 2;

    quicksort(v, 0, n, tipo, compara);

    /*
    for(int i=0; i<n; i++){
        printf("%d", *((int*)v[i]));
    }
    */

    //int a=1, b=2;
    //void *pa=&a, *pb=&b;
    
    //int (*compar)(int, void*, void*) = &compara;
    //printf("%d", a(compara));

    return 0;
}