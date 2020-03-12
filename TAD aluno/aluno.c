#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

#define TRUE 1;
#define FALSE 0;
CofoAluno *cofoCreate(int n){
    CofoAluno *c;
    if (n>0){
        c=(CofoAluno *)malloc(sizeof(CofoAluno));
        if(c!=NULL){
            c->elm=(Aluno *)malloc(sizeof(Aluno)*n);
            if(c->elm!=NULL){
                c->nElms = 0;
                c->maxElms = n;
                return c;
            }
        }
    }
    return NULL;
}

int cofoInsert(CofoAluno *c, Aluno *a){
    if(c!=NULL){
        if(c->nElms<c->maxElms){
            c->elm[c->nElms]=a;
            c->nElms++;
            return TRUE;
        }
    }
    return FALSE;
}

int cofoRemove(CofoAluno *c, int cpf){
    int i, j;
    Aluno *a;
    if (c!=NULL){
        i=0;
        while(c->elm[i]->cpf==cpf&&i<c->nElms){
            i++;
        }
        if(c->elm[i]->cpf==cpf){
            a = c->elm[i];
            for(j=i; j<c->nElms-2; j++){
                c->elm[j]==c->elm[j+1];
            }
            c->nElms--;
            free(a);
            return TRUE;
        }
    }
    return FALSE;
}

Aluno *cofoQuerry(CofoAluno *c, int cpf){
    int i;
    if(c!=NULL){
        if(c->nElms>0){
            i=0;
            while(c->elm[i]->cpf!=cpf&&i<c->nElms){
                i++;
            }
            if(c->elm[i]->cpf==cpf){
                return c->elm[i];
            }
        }
    }
    return NULL;
}

int cofoDestroy(CofoAluno *c){
    if(c!=NULL){
        if(c->nElms==0){
            free(c->elm);
            free(c);
            return TRUE;
        }
    }
    return FALSE;
}
