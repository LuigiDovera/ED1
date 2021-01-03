#include <stdlib.h>
#include "sllist.h"

typedef struct _slnode_
{
  struct _slnode_ *next;
  void *data;
}SLNode; //No da lista

typedef struct _sllist_ 
{
  SLNode *first;
  SLNode *cur;
}SLList; //Lista

SLList *sllCreate()
{
  SLList *l;

  l = (SLList*)malloc(sizeof(SLList));
  if(l != NULL)
  {
    l->first = NULL;
    l->cur = NULL;
    return l;
  }
  return NULL;
} //Cria a lista

int sllInsertFirst(SLList *l, void *data)
{
  SLNode *newNode;

  if(l != NULL)
  {
    newNode = (SLNode*)malloc(sizeof(SLNode));
    if(newNode != NULL)
    {
      newNode->data = data;
      newNode->next = l->first;
      l->first = newNode;
      return TRUE;
    }
  }
  return FALSE;
} //Insere no inicio

int sllInsertLast(SLList *l, void *data)
{
  SLNode *newNode, *cur;

  if(l != NULL)
  {
    newNode = (SLNode*)malloc(sizeof(SLNode));
    if(newNode != NULL)
    {
      newNode->data = data;
      newNode->next = NULL;

      cur = l->first;
      if(cur != NULL)
      {
        while(cur->next != NULL)
        {
          cur = cur->next;
        }
        cur->next = newNode;
      }
      else
      {
        l->first = newNode;
      }
      return TRUE;
    }
  }
  return FALSE;
} //Insere no final

int sllInsertAtPos(SLList *l, int p, void *data)
{
  SLNode *newNode, *cur;
  int i=0;

  if(l != NULL)
  {
    if(l->first != NULL)
    {
      cur = l->first;
      while(i < p && cur != NULL)
      {
        cur = cur->next;
        i++;
      }
      newNode = (SLNode*)malloc(sizeof(SLNode));
      if(newNode != NULL)
      {
        newNode->data = data;
        newNode->next = l->first;
        l->first = newNode;
        return TRUE;
      }
    }
  }
  return FALSE;
} //Insere na p-esima posicao

int sllInsertAfterSpec(SLList *l, void *key, int(cmp)(void *, void *), void *data)
{
  SLNode *newNode, *spec;
  int i=0;

  if(l != NULL)
  {
    if(l->first != NULL)
    {
      spec = l->first;
      while(spec->next != NULL && !cmp(key, spec->data))
      {
        spec = spec->next;
      }
      if(cmp(key, spec->data))
      {
        newNode = (SLNode*)malloc(sizeof(SLNode));
        if(newNode != NULL)
        {
          newNode->data = data;
          newNode->next = spec->next;
          spec->next = newNode;
          return TRUE;
        }
      }
    }
  }
  return FALSE;
} //Insere apos certo elemento

int sllInsertBeforeSpec(SLList *l, void *key, int(cmp)(void *, void *), void *data)
{
  SLNode *newNode, *spec, *prev;
  int i=0;

  if(l != NULL)
  {
    if(l->first != NULL)
    {
      prev = NULL;
      spec = l->first;
      while(spec->next != NULL && !cmp(key, spec->data))
      {
        prev = spec;
        spec = spec->next;
      }
      if(cmp(key, spec->data))
      {
        newNode = (SLNode*)malloc(sizeof(SLNode));
        if(newNode != NULL)
        {
          newNode->data = data;
          newNode->next = spec;
          if(prev != NULL)
          {
            prev->next = newNode;
          }
          else
          {
            l->first = newNode;
          }
          return TRUE;
        }
      }
    }
  }
  return FALSE;
} //Insere antes de certo elemento

void *sllRemoveFirst(SLList *l)
{
  SLNode *temp;
  void *data;
  
  if(l != NULL)
  {
    if(l->first != NULL)
    {
      temp = l->first;
      data = temp->data;
      l->first = temp->next;
      free(temp);
      return data;
    }
  }
  return NULL;
} //Remove o primeiro elemento

void *sllRemoveLast(SLList *l)
{
  SLNode *temp;
  void *data;
  
  if(l != NULL)
  {
    if(l->first != NULL)
    {
      temp = l->first;
      while(temp->next != NULL)
      {
        temp = temp->next;
      }
      data = temp->data;
      if(temp == l->first)
      {
        l->first = temp->next;
      }
      free(temp);
      return data;
    }
  }
  return NULL;
} //Remove o ultimo elemento

void *sllRemoveSpec(SLList *l, void *key, int(cmp)(void *, void *))
{
  SLNode *spec, *prev;
  void *data;
  
  if(l != NULL)
  {
    if(l->first != NULL)
    {
      prev = NULL;
      spec = l->first;
      while(spec->next != NULL && !cmp(key, spec->data))
      {
        prev = spec;
        spec = spec->next;
      }
      if(cmp(key, spec->data))
      {
        data = spec->data;
        if(prev == NULL)
        {
          l->first = spec->next;
        }
        else
        {
          prev->next = spec->next;
        }
        free(spec);
        return data;
      }
    }
  }
  return NULL;
} //Remove atraves de chave

void *sllRemoveAfterSpec(SLList *l, void *key, int(cmp)(void *, void *))
{
  SLNode *spec, *next;
  void *data;
  
  if(l != NULL)
  {
    if(l->first != NULL)
    {
      spec = l->first;
      while(spec->next != NULL && !cmp(key, spec->data))
      {
        spec = spec->next;
      }
      if(cmp(key, spec->data))
      {
        next = spec->next;
        if(next != NULL){
          data = next->data;
          spec->next = next->next;
          free(next);
          return data;
        }
      }
    }
  }
  return NULL;
} //Remove apos certo elemento

void *sllRemoveBeforeSpec(SLList *l, void *key,  int(cmp)(void *, void *))
{
  SLNode *prev, *befPrev;
  void *data;
  
  if(l != NULL)
  {
    if(l->first != NULL)
    {
      befPrev = NULL;
      prev = l->first;
      while(prev->next != NULL && !cmp(key, prev->next->data))
      {
        befPrev = prev;
        prev = prev->next;
      }
      if(cmp(key, prev->next->data))
      {
        data = prev->data;
        if(befPrev != NULL)
        {
          befPrev->next = prev->next;
        }
        else
        {
          l->first = prev->next;
        }
        free(prev);
        return data;
      }
    }
  }
  return NULL;
} //Remove antes de certo elemento

void *sllGetFirst(SLList *l)
{
  if(l != NULL)
  {
    l->cur = l->first;
    return l->first;
  }
  return NULL;
} //Retorna o primeiro elemento

void *sllGetNext(SLList *l)
{
  if(l != NULL)
  {
    if(l->cur != NULL)
    {
      l->cur = l->cur->next;
      return l->cur;
    }
  }
  return NULL;
} //Permite a iteracao pela lista

void *sllGetLast(SLList *l)
{
  SLNode *cur;

  if(l != NULL)
  {
    if(l->first != NULL)
    {
      cur = l->first;
      while(cur->next != NULL)
      {
        cur = cur->next;
      }
      return cur;
    }
  }
  return NULL;
} //Retorna o ultimo elemento

void *sllQuery(SLList *l, void *key,  int(cmp)(void *, void *))
{
  SLNode *cur;

  if(l != NULL)
  {
    if(l->first != NULL)
    {
      cur = l->first;
      while(cur->next != NULL && !cmp(key, cur->data))
      {
        cur = cur->next;
      }
      if(cmp(key, cur->data))
      {
        return cur;
      }
    }
  }
  return NULL;
} //Retorna o elemento se estiver na lista

void *sllGetCurData(SLList *l)
{
  if(l != NULL)
  {
    if(l->cur != NULL)
    {
      return l->cur->data;
    }
  }
  return NULL;
} //Retorna o campo data do current da lista

int sllGetNumElms(SLList *l)
{
  SLNode *cur;
  int i;

  if(l != NULL)
  {
    i = 0;
    if(l->first != NULL)
    {
      i = 1;
      cur = l->first;
      while(cur->next != NULL)
      {
        cur = cur->next;
        i++;
      }
    }
    return i;
  }
  return -1;
} //Retorna o tamanho da lista

int sllDestroy(SLList *l)
{
  if(l != NULL)
  {
    if(l->first == NULL)
    {
      free(l);
      return TRUE;
    }
  }
  return FALSE;
} //Destroi a lista