#include <stdlib.h>
#include "colecao.h"

typedef struct _colecao_ 
{
  int maxItens;
  int numItens;
  int itemAtual;
  void **itens;
} Colecao;

Colecao *colCriar(int maxItens)
{
  Colecao *c;

  if(maxItens > 0)
  {
    c = (Colecao*) malloc(sizeof(Colecao));
    if(c != NULL)
    {
      c->itens = (void**) malloc(sizeof(void*) * maxItens);
      if(c->itens != NULL)
      {
        c->maxItens = maxItens;
        c->numItens = 0;
        c->itemAtual = 0;
        return c;
      }
      free(c);
    }
  }
  return NULL;
}

int colInserir(Colecao *c, void *item)
{
  if(c != NULL)
  {
    if(c->numItens < c->maxItens)
    {
      c->itens[c->numItens] = item;
      c->numItens++;
      return TRUE;
    }
  }
  return FALSE;
}

void *colBuscar(Colecao *c, void *key, int (*cmp)(void*, void*))
{
  int i;

  if(c != NULL)
  {
    if(c->numItens > 0)
    {
      for(i=0; i < c->numItens; i++)
      {
        if(cmp(key, c->itens[i]) == TRUE)
        {
          return c->itens[i];
        }//nao encontrou
      }//for no vetor
    }//vetor vazio
  }//colecao nula
  return NULL;
}

void *colRemover(Colecao *c, void *key, int (*cmp)(void*, void*))
{
  int i, j;
  void *del;

  if(c != NULL)
  {
    if(c->numItens > 0)
    {
      for(i=0; i < c->numItens; i++)
      {
        if(cmp(key, c->itens[i]) == TRUE)
        {
          del = c->itens[i];
          for(j=i; j < c->numItens-1; j++)
          {
            c->itens[j] = c->itens[j+1];
          }
          c->numItens--;
          return del;
        }//nao encontrou
      }//for no vetor
    }//vetor vazio
  }//colecao nula
  return NULL;
}

int colDestruir(Colecao *c)
{
  if(c != NULL)
  {
    if(c->numItens == 0)
    {
      free(c->itens);
      free(c);
      return TRUE;
    }
  }
  return FALSE;
}

void *pegarPrim(Colecao *c)
{
  if(c != NULL)
  {
    if(c->numItens > 0)
    {
      c->itemAtual = 0;
      return c->itens[c->itemAtual];
    }
  }
  return NULL;
}

void *pegarProx(Colecao *c)
{
  if(c != NULL)
  {
    if(c->numItens > 0)
    {
      c->itemAtual++;
      if(c->itemAtual < c->numItens)
      {
        return c->itens[c->itemAtual];
      }//o iterador esta alem do limite
    }//vetor vazio
  }//colecao nula
  return NULL;
}