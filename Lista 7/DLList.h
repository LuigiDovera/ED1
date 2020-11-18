#ifndef DLLIST_H
#define DLLIST_H

#define TRUE 1
#define FALSE 0

typedef struct _DLNode_ DLNode;
typedef struct _DLList_ DLList;

DLList *dllCreate(void);
int dllDestroy(DLList *l);
int dllInsertAsFirst(DLList *l, void *data);
int dllInsertBeforeSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *));
int dllInsertAfterSpec(DLList *l, void *key, void *data, int (*cmp)(void *, void *));
void dllPrint(DLList *l, void (*print)(void *));



#endif