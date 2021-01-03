#ifndef BSTREE_H
#define BSTREE_H

#define TRUE 1
#define FALSE 0

typedef struct _tnode_ TNode;
typedef struct _tree_ Tree;

TNode *bstCreate(TNode *t, void *data);

void bstPreOrder(TNode *t, void (*visit)(void *));
void bstInOrder(TNode *t, void (*visit)(void *));
void bstPostOrder(TNode *t, void (*visit)(void *));

TNode *bstInsert(TNode *t, void *data, int (*cmp)(void*, void *));
void *bstQuery(TNode *t, void *key, int (*cmp)(void *, void *));
TNode *bstRemoveSmallest(TNode *t, void *key, int (*cmp)(void *, void *), void **data);
TNode *bstRemove(TNode *t, void *key, int (*cmp)(void *, void *), void **data);

void *bstGreaterNode(TNode *t);

#endif