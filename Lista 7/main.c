#include <stdlib.h>
#include <stdio.h>
#include "DLList.h"

int comparaInt(void *arg1, void *arg2);
void printInt(void *arg);

int main(){
    DLList *l = dllCreate();

    for(int i = 0; i<4; i++){
        void *data = (void *) malloc(sizeof(int));
        *(int*)data = i;
        dllInsertAsFirst(l, data);
    }
    dllPrint(l, printInt);
    printf("\n");

    int num2 = 10;
    void *data2 = &num2;

    int dkey2 = 1;
    void *key2 = &dkey2;

    dllInsertBeforeSpec(l, key2, data2, comparaInt);

    dllPrint(l, printInt);
    printf("\n");

    int num3 = 20;
    void *data3 = &num3;

    int dkey3 = 2;
    void *key3 = &dkey3;

    dllInsertAfterSpec(l, key3, data3, comparaInt);

    dllPrint(l, printInt);
    printf("\n");

    system("pause");
}

int comparaInt(void *arg1, void *arg2){
    if( *((int*)arg1) == *((int*)arg2) ){
            return TRUE;
    }else{
        return FALSE;
    }
}

void printInt(void *arg){
    printf("%d\n", *((int*)arg));
}

