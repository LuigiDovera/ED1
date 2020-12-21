#ifndef BSTREE_H
#define BSTREE_H

#define TRUE 1
#define FALSE 0

typedef struct _tnode_ TNode;
typedef struct _tree_ Tree;


void preOrdem(TNode *t, void (*visit)(void *));
void posOrdem(TNode *t, void (*visit)(void *));
void Simetrico(TNode *t, void (*visit)(void *));

TNode *abpCreate(TNode *t, void *data);
void *abpQuery(TNode *t, void *key, int (*cmp)(void *, void *));
TNode *abpInsert(TNode *t, void *data, int(*cmp)(void *, void *));
TNode *abpRemove(TNode *t, void *key, int (*cmp)(void *, void *), void *data);
TNode *abpRemoveMenor(TNode *t, void *key, int (*cmp)(void *, void *), void *data);

#endif
