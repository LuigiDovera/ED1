#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comparaInt(void *arg1, void *arg2){
    if( *((int*)arg1) <  *((int*)arg2) ){
            return 0;
        }else if( *((int*)arg1) == *((int*)arg2) ){
            return 1;
        }else{
            return 2;
        }
}

int comparaFloat(void *arg1, void *arg2){
    
    if( *((float*)arg1) <  *((float*)arg2) ){
            return 0;
        }else if( *((float*)arg1) == *((float*)arg2) ){
            return 1;
        }else{
            return 2;
        }
}

void recebeInt(void *arg1, void*arg2){
    *((int*)arg1) = *((int*)arg2);
}

void recebeFloat(void *arg1, void*arg2){
    *((float*)arg1) = *((float*)arg2);
}

void alocaInt(void **arg1){
    *arg1 = (int *) malloc(sizeof(int *));
}

void alocaFloat(void **arg1){
    *arg1 = (float *) malloc(sizeof(float *));
}


void quicksort (void **vetor, int esq, int dir,
        int (*compara)(void*, void*), void (*recebe)(void*, void*),
        void (*aloca)(void *)){
    int i, j, z;
    void *x, *y;
    aloca(&x);
    aloca(&y);

    
    i = esq;
    j = dir;
    z = (int) floor((esq + dir)/2);
    
    recebe(x, vetor[z]);
    

    while(i<=j){
        
        while (compara(vetor[i], x) == 0 && i < dir){
            i++;
            
        }
        while (compara(vetor[j], x) == 2 && j > esq){
            j--;
            
        }
        
        if(i<=j){
            recebe(y, vetor[i]);
            recebe(vetor[i], vetor[j]);
            recebe(vetor[j], y);
            i++;
            j--;
        }
    }

    if (j>esq){
        quicksort(vetor, esq, j, compara, recebe, aloca);
    }
    if (i<dir){
        quicksort(vetor, i, dir, compara, recebe, aloca);
    }


}



int main(){

    
    int tipo, n;
    void **v;
    int (*comp)(void *, void  *);
    void (*rec)(void *, void  *);
    void (*aloc)(void *);

    
    printf("1-Inteiro 2-Real\n");
    scanf("%d", &tipo);

    if(tipo==1){
        comp = comparaInt;
        rec = recebeInt;
        aloc = alocaInt;
    }else{
        comp = comparaFloat;
        rec = recebeFloat;
        aloc = alocaFloat;
    }

    printf("Tamanho de n?\n");
    scanf("%d", &n);
    

    v = (void **) malloc(n*sizeof(void *));
    
    for(int i=0; i<n; i++){
        aloc(&v[i]);
        void *rando;
        aloc(&rando);
        (*(int*)rando) = (int*) (rand() % 100);
        
        rec(v[i], rando);
        printf("%d ", *((int*)v[i]));
    }
    printf("\n");

    /*
    *((int*)v[0]) = 3;
    *((int*)v[1]) = 1;
    *((int*)v[2]) = 0;
    *((int*)v[3]) = 2;
    */

    quicksort(v, 0, n-1, comp, rec, aloc);
    
    for(int i=0; i<n; i++){
        printf("%d ", *((int*)v[i]));
    }
    printf("\n");
    

    //int a=1, b=2;
    //void *pa=&a, *pb=&b;
    
    //int (*compar)(int, void*, void*) = &compara;
    //printf("%d", a(compara));

    return 0;
}