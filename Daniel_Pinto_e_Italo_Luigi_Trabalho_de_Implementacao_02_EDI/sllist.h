#ifndef SLList_H
#define SLList_H

#define TRUE 1
#define FALSE 0

typedef struct _slnode_ SLNode;
typedef struct _sllist_ SLList;

SLList *sllCreate(); //Cria a lista

int sllInsertFirst(SLList *l, void *data); //Insere no inicio
int sllInsertLast(SLList *l, void *data); //Insere no final
int sllInsertAtPos(SLList *l, int p, void *data); //Insere na p-esima posicao
int sllInsertAfterSpec(SLList *l, void *key, int(cmp)(void *, void *), void *data); //Insere apos certo elemento
int sllInsertBeforeSpec(SLList *l, void *key, int(cmp)(void *, void *), void *data); //Insere antes de certo elemento

void *sllRemoveFirst(SLList *l); //Remove o primeiro elemento
void *sllRemoveLast(SLList *l); //Remove o ultimo elemento
void *sllRemoveSpec(SLList *l, void *key, int(cmp)(void *, void *)); //Remove atraves de chave
void *sllRemoveAfterSpec(SLList *l, void *key, int(cmp)(void *, void *)); //Remove apos certo elemento
void *sllRemoveBeforeSpec(SLList *l, void *key,  int(cmp)(void *, void *)); //Remove antes de certo elemento

void *sllGetFirst(SLList *l); //Retorna o primeiro elemento
void *sllGetNext(SLList *l); //Permite a iteracao pela lista
void *sllGetLast(SLList *l); //Retorna o ultimo elemento
void *sllQuery(SLList *l, void *key,  int(cmp)(void *, void *)); //Retorna o elemento se estiver na lista
void *sllGetCurData(SLList *l); //Retorna o campo data do current da lista

int sllGetNumElms(SLList *l); //Retorna o tamanho da lista

int sllDestroy(SLList *l); //Destroi a lista

#endif