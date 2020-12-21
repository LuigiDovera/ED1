#include <stdlib.h>
#include <stdio.h>
#include "BSTree.h"

int comparaInt(void *num1, void *num2){
    return *((int*)num2) - *((int*)num1);
}

void printInt(void *arg){
    printf("%d ", *((int*)arg));
}

int main (){
    
    TNode *t;
    void *indice = (void *)malloc(sizeof(int));
    *((int*)indice) = 10;
    t = abpCreate(t, indice);
    
    int i;
    for (i=-10; i<10; i++){
        void *data = (void *)malloc(sizeof(int));
        *((int*)data) = i;
        printf("%d", *((int*)data));
        abpInsert(t, data, comparaInt);
        printf("A");
    }

    preOrdem(t, printInt);

    system("pause");
}
