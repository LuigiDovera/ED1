#include <stdlib.h>
#include "DLList.h"
#include <stdio.h>

typedef struct _DLNode_
{
    DLNode *next, *prev;
    void *data;
} DLNode;

typedef struct _DLList_
{
    DLNode *first;
    DLNode *cur;
} DLList;

DLList *dllCreate(void) /* 1 - Cria lista vazia */
{
    DLList *l;
    l = (DLList *)malloc(sizeof(DLList));

    if (l != NULL)
    {
        l->first = NULL;
        l->cur = NULL;
        return l;
    }
    return NULL;
}

int dllDestroy(DLList *l)
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

int dllInsertAsFirst(DLList *l, void *data)
{
    DLNode *newnode;
    if (l != NULL)
    {
        newnode = (DLNode *)malloc(sizeof(DLNode));
        if (newnode != NULL)
        {
            newnode->data = data;
            newnode->prev = NULL;
            newnode->next = l->first;
            if (l->first != NULL)
            {
                l->first->prev = newnode;
            }
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

int dllInsertBeforeSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *))
{

    DLNode *node, *nodeKey;
    DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));

    newnode->data = data;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            if (key != NULL)
            {
                node = l->first;
                if (cmp(node->data, key))
                {
                    newnode->next = l->first;
                    newnode->prev = NULL;

                    l->first->prev = newnode;
                    l->first = newnode;

                    return TRUE;
                }

                //Procurar o nó com dado igual a chave
                while (node->next != NULL && cmp(node->next->data, key) != TRUE)
                {
                    node = node->next;
                }

                if (cmp(node->next->data, key))
                {
                    nodeKey = node->next;
                    nodeKey->prev = newnode;

                    node->next = newnode;

                    newnode->prev = node;
                    newnode->next = nodeKey;

                    return TRUE;
                }
            }
        }
    }
    free(newnode);
    return FALSE;
}

int dllInsertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *))
{
    DLNode *node;
    DLNode *newnode = (DLNode *)malloc(sizeof(DLNode));

    newnode->data = data;
    if (l != NULL)
    {
        if (l->first != NULL)
        {
            if (key != NULL)
            {
                node = l->first;
                while (node != NULL && cmp(key, node->data) != TRUE)
                {
                    node = node->next;
                }
                if (cmp(key, node->data) == TRUE)
                {
                    if (node->next == NULL)
                    {
                        newnode->prev = node;
                        newnode->next = NULL;

                        node->next = newnode;
                    }
                    else
                    {
                        newnode->next = node->next;
                        newnode->prev = node;

                        node->next->prev = newnode;
                        node->next = newnode;
                    }
                    return TRUE;
                }
            }
        }
    }
    free(newnode);
    return FALSE;
}

void dllPrint(DLList *l, void (*print)(void *))
{
    DLNode *node;
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

int Comuns(DLList *l1, DLList *l2, int(cmp)(void *, void *))
{
    DLNode *cur1, *cur2;
    int n = 0;
    if (l1 != NULL && l2 != NULL)
    {
        if (l1->first != NULL & l2->first != NULL)
        {
            cur1 = l1->first;
            do 
            {
                cur2 = l2->first;
                do 
                {
                    if (cmp(cur1->data, cur2->data) == 0)
                    {
                        n++;
                    }
                    cur2 = cur2->next;
                }while (cur2 != l2->first);
                cur1 = cur1->next;
            }while (cur1 != l1->first);
            return n;
        }
        return 0;
    }
    return -1;
}
