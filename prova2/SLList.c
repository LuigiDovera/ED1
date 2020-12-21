#include <stdlib.h>
#include "SLList.h"

typedef struct _SLNode_
{
    SLNode *next;
    void *data;
} SLNode;

typedef struct _SLList_
{
    SLNode *first;
} SLList;

SLList *sllCreate()
{
    SLList *l;
    l = (SLList *)malloc(sizeof(SLList));
    if (l != NULL)
    {
        l->first = NULL;
        return l;
    }
    return NULL;
}

int sllInsertFirst(SLList *l, void *elm) //slstkPush
{
    SLNode *newnode, *aux;
    if (l != NULL)
    {
        newnode = (SLNode *)malloc(sizeof(SLNode));
        if (newnode != NULL)
        {
            newnode->data = elm;
            if (l->first == NULL)
            {
                newnode->next = NULL;
                l->first = newnode;
            }
            else
            {
                aux = l->first;
                l->first = newnode;
                newnode->next = aux;
            }

            return TRUE;
        }
    }
    return FALSE;
}

void *sllRemoveFirst(SLList *l) // slstkPop
{
    SLNode *aux;
    void *data;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            aux = l->first;
            data = aux->data;
            l->first = aux->next;
            free(aux);
            return data;
        }
    }
    return NULL;
}

void *sllGetFirst(SLList *l)
{
    SLNode *aux;
    void *data;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            aux = l->first;
            data = aux->data;
            return data;
        }
    }
    return NULL;
}

int sllDestroy(SLList *l)
{
    if (l != NULL)
    {
        if (l->first == NULL)
        {
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertBeforeSpec(SLList *l, void *key, int (*cmp)(void *, void *), void *data)
{
    SLNode *node, *aux;
    SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
    newnode->data = data;
    if (l != NULL)
    {
        if (key != NULL)
        {
            node = l->first;
            if (cmp(l->first->data, key))
            {
                aux = l->first;
                l->first = newnode;
                newnode->next = aux;

                return TRUE;
            }

            //Procurar o nó com dado igual a chave
            while (node->next != NULL && cmp(node->next->data, key) != TRUE)
            {
                node = node->next;
            }

            if (cmp(node->next->data, key))
            {
                aux = node->next;
                node->next = newnode;
                newnode->next = aux;

                return TRUE;
            }
        }
    }
    free(newnode);
    return FALSE;
}

int sllInsertAfterSpec(SLList *l, void *key, int (*cmp)(void *, void *), void *data)
{
    SLNode *newnode, *spec;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            spec = l->first;
            while (spec > next != NULL && cmp(key, spec > data) != TRUE)
            {
                spec = spec > next;
            }
            if (cmp(key, spec > data) == TRUE)
            {
                newnode = (SLNode *)malloc(sizeof(SLNode));
                if (newnode != NULL)
                {
                    newnode->data = data;
                    newnode->next = spec->next;
                    spec->next = newnode;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void *sllRemoveAfterSpec(SLList *l, void *key, int (*cmp)(void *, void *), void *data)
{
    SLNode *node, *nodeAux;
    void *dataAux;

    if (l != NULL)
    {
        if (key != NULL)
        {
            node = l->first;

            //Procurar o nó com dado igual a chave
            while (node != NULL && cmp(node->data, key) != TRUE)
            {
                node = node->next;
            }

            if (cmp(node->data, key) && node->next != NULL)
            {
                nodeAux = node->next;
                node->next = node->next->next;

                dataAux = nodeAux->data;
                free(nodeAux);
                return dataAux;
            }
        }
    }
    return NULL;
}

void sllPrint(SLList *l, void (*print)(void *))
{
    SLNode *node;
    if (l != NULL)
    {
        node = l->first;
        while (node != NULL)
        {
            print(node->data);
            node = node->next;
        }
    }
}