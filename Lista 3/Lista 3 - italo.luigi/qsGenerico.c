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
    if (*arg1==NULL){
        exit(1);
    }
}

void alocaFloat(void **arg1){
    *arg1 = (float *) malloc(sizeof(float *));
    if (*arg1==NULL){
        exit(1);
    }
}

void freeDupla(void **arg1){
    free(*arg1);
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

    freeDupla(&x);
    free(x);
    freeDupla(&y);
    free(y);

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
    if (v==NULL){
        exit(1);
    }
    
    for(int i=0; i<n; i++){
        aloc(&v[i]);
        if (v[i]==NULL){
            exit(1);
        }
        void *rando;
        aloc(&rando);
        if (rando==NULL){
            exit(1);
        }
        if(tipo==1){
            *((int*)rando) = (int) (rand() % 100);
        }else{
            *((float*)rando) = (float) (rand()/10);
        }
        
        rec(v[i], rando);

        free(rando);
        printf("%d ", *((int*)v[i]));
    }
    printf("\n");

    quicksort(v, 0, n-1, comp, rec, aloc);

    for(int i=0; i<n; i++){
        printf("%d ", *((int*)v[i]));
    }
    printf("\n");

    system("Pause");

    for(int i=0; i<n; i++){
        free(v[i]);
    }
    free(v);

    return 0;
}