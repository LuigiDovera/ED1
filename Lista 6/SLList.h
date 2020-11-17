#ifndef SLLIST_H
#define SLLIST_H

#define TRUE 1
#define FALSE 0

typedef struct _SLNode_ SLNode;
typedef struct _SLList_ SLList;

SLList *sllCreate();
int sllInsertFirst(SLList *l, void *elm);
void *sllRemoveFirst(SLList *l);
void *sllGetFirst(SLList *l);
int sllDestroy(SLList *l);
int sllInsertBeforeSpec(SLList *l, void *key, int (*cmp)(void *, void*), void *data);
void *sllRemoveAfterSpec(SLList *l, void *key, int (*cmp)(void *, void *), void *data);
void sllPrint(SLList *l, void (*print)(void *));


#endif