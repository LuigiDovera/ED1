#ifndef BTREE_H
#define BTREE_H

#define TRUE 1
#define FALSE 0

typedef struct _tnode_ TNode;
typedef struct _tree_ Tree;

void preOrdem(TNode *t, void (*visit)(void *));
void posOrdem(TNode *t, void (*visit)(void *));
void Simetrico(TNode *t, void (*visit)(void *));

#endif