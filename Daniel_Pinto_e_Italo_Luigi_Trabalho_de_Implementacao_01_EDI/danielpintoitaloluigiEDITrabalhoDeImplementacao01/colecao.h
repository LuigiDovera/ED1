#ifndef COLECAO_H
#define COLECAO_H

#define TRUE 1
#define FALSE 0

typedef struct _colecao_ Colecao;

Colecao *colCriar(int maxItens);
int colInserir(Colecao *c, void *item);
void *colBuscar(Colecao *c, void *key, int (*cmp)(void*, void*));
void *colRemover(Colecao *c, void *key, int (*cmp)(void*, void*));
int colDestruir(Colecao *c);
void *pegarPrim(Colecao *c);
void *pegarProx(Colecao *c);

#endif