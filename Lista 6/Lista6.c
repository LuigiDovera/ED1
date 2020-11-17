#include <stdlib.h>
#include <stdio.h>
#include "SLList.h"

int comparaInt(void *arg1, void *arg2);
void printInt(void *arg);

int main(){
    SLList *l = sllCreate();

    for(int i = 0; i<1; i++){
        int num = i;
        void *data = &num;
        sllInsertFirst(l, data);
    }
    sllPrint(l, printInt);
    printf("\n");

    int num2 = 0;
    void *data2 = &num2;

    sllInsertBeforeSpec(l, data2, comparaInt, data2);

    sllPrint(l, printInt);
    printf("\n");

    sllRemoveAfterSpec(l, data2, comparaInt, data2);

    sllPrint(l, printInt);
    printf("\n");

    system("pause");
}

int comparaInt(void *arg1, void *arg2){
    if( *((int*)arg1) <  *((int*)arg2) ){
            return 0;
        }else if( *((int*)arg1) == *((int*)arg2) ){
            return 1;
        }else{
            return 2;
        }
}

void printInt(void *arg){
    printf("%d\n", *((int*)arg));
}

