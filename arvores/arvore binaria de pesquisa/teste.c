#include <stdlib.h>
#include <stdio.h>
#include "BSTree.h"

int comparaInt(void *num1, void *num2){
    return *((int*)num1) - *((int*)num2);
}

void printInt(void *arg){
    printf("%d ", *((int*)arg));
}

int main (){
    
    TNode *t;
    void *indice = (void *)malloc(sizeof(int));
    *((int*)indice) = 3;
    t = abpCreate(t, indice);
    
    int i;
    for (i=0; i<6; i++){
        void *data = (void *)malloc(sizeof(int));
        *((int*)data) = i;
        //printf("%d", *((int*)data));
        abpInsert(t, data, comparaInt);
        //printf("A");
    }

    preOrdem(t, printInt);
    printf("\n");

    posOrdem(t, printInt);
    printf("\n");

    Simetrico(t, printInt);
    printf("\n");

    printInt(abpMaiorNo(t));

    system("pause");
}
