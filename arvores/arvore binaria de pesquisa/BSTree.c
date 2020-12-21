#include <stdlib.h>
#include "BSTree.h"

typedef struct _tnode_
{
    void *data;
    TNode *left;
    TNode *right;
} TNode;

typedef struct _tree_
{
    TNode root;

} Tree;

void preOrdem(TNode *t, void (*visit)(void *))
{
    if (t != NULL)
    {
        visit(t->data);
        preOrdem(t->left, visit);
        preOrdem(t->right, visit);
    }
}

void posOrdem(TNode *t, void (*visit)(void *))
{
    if (t != NULL)
    {
        posOrdem(t->left, visit);
        posOrdem(t->right, visit);
        visit(t->data);
    }
}

void Simetrico(TNode *t, void (*visit)(void *))
{
    if (t != NULL)
    {
        Simetrico(t->left, visit);
        visit(t->data);
        Simetrico(t->right, visit);
    }
}

TNode *abpCreate(TNode *t, void *data){
    t = (TNode *)malloc(sizeof(TNode));
    if (t!=NULL){
        t->data = data;
        t->right = NULL;
        t->left = NULL;
        return t;
    }
    t = NULL;
    return NULL;
}

void *abpQuery(TNode *t, void *key, int (*cmp)(void *, void *))
{
    int stat;

    if (t != NULL)
    {
        stat = cmp(key, t->data);

        if (stat == 0)
        {
            return t->data;
        }
        else if (stat < 0)
        {
            return abpQuery(t->left, key, cmp);
        }
        else
        {
            return abpQuery(t->right, key, cmp);
        }
    }
    return NULL;
}

TNode *abpInsert(TNode *t, void *data, int (*cmp)(void *, void *))
{
    TNode *newnode;
    int stat;
    if (t != NULL)
    {
        stat = cmp(data, t->data);
        if (stat <= 0)
        {
            t->left = abpInsert(t, data, cmp);
        }
        else
        {
            t->right = abpInsert(t, data, cmp);
        }
        return t;
    }
    else
    {
        newnode = (TNode *)malloc(sizeof(TNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->left = NULL;
            newnode->right = NULL;
            return newnode;
        }
        else
        {
            return NULL;
        }
    }
}

TNode *abpRemove(TNode *t, void *key, int (*cmp)(void *, void *), void *data){
    void *data2;
    TNode *aux;
    int stat;
    if(t!=NULL){
        stat = cmp(data, t->data);
        if(stat<0){
            t->left = abpRemove(t->left, key, cmp, &data2);
            return t;
        }
        else if(stat>0){
            t->right = abpRemove(t->left, key, cmp, &data2);
            return t;
        }
        else{
            if(t->left==NULL){
                aux = t->right;
                data = t->data;
                free(t);
                return aux;
            }
            else if(t->right==NULL){
                aux = t->left;
                data = t->data;
                free(t);
                return aux;
            }
            else{
                data = t->data;
                t->right = abpRemoveMenor(t->right, key, cmp, data2);
                return t;
            }
        }
    }
    data = NULL;
    return NULL;
}

TNode *abpRemoveMenor(TNode *t, void *key, int (*cmp)(void *, void *), void *data){
    void *data2;
    if(t->left==NULL){
        data2 = t->data;
        free(t);
        return NULL;
    }
    else{
        return abpRemoveMenor(t->right, key, cmp, data);
    }
}
