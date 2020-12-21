#include <stdlib.h>
#include "BTree.h"

typedef struct _tnode_
{
    void *item;
    struct t_node *left;
    struct t_node *right;
} TNode;

typedef struct _tree_
{
    Node root;

} Tree;

void preOrdem(TNode *t, void (*visit)(void *))
{
    if (t != NULL)
    {
        visit(t->item);
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
        visit(t->item);
    }
}

void Simetrico(TNode *t, void (*visit)(void *))
{
    if (t != NULL)
    {
        Simetrico(t->left, visit);
        visit(t->item);
        Simetrico(t->right, visit);
    }
}