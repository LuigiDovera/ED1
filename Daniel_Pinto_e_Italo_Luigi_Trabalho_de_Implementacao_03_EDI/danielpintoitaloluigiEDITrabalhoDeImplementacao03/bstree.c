#include <stdlib.h>
#include "bstree.h"

typedef struct _tnode_
{
  void *data;
  struct _tnode_ *left;
  struct _tnode_ *right;
}TNode;// Struct que compoe a arvore

typedef struct _tree_
{
  struct _tnode_ *root;
}Tree;

TNode *bstCreate(TNode *t, void *data)
{
  t = (TNode *) malloc(sizeof(TNode));
  if(t != NULL)
  {
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
  }
  return NULL;
}// bstCreateNode

void bstPreOrder(TNode *t, void (*visit)(void *))// printa raiz, arvore esquerda, arvore direita
{
  if(t != NULL)
  {
    visit(t->data);
    bstPreOrder(t->left, visit);
    bstPreOrder(t->right, visit);
  }
}// bstPreOrder

void bstInOrder(TNode *t, void (*visit)(void *))// printa arvore esquerda, raiz, arvore direita
{
  if(t != NULL)
  {
    bstInOrder(t->left, visit);
    visit(t->data);
    bstInOrder(t->right, visit);
  }
}// bstInOrder

void bstPostOrder(TNode *t, void (*visit)(void *))// printa arvore esquerda, arvore direita, raiz
{
  if(t != NULL)
  {
    bstPostOrder(t->left, visit);
    bstPostOrder(t->right, visit);
    visit(t->data);
  }
}// bstPostOrder

TNode *bstInsert(TNode *t, void *data, int (*cmp)(void*, void *))
{
  TNode *newNode;

  if(t != NULL)// Node nao pode ser posicionado aqui, deve seguir em frente
  {
    if(cmp(data, t->data) < 0)// Menor que o no atual, precisa ir para a esquerda
    {
      t->left = bstInsert(t->left, data, cmp);
    }
    else// Maior que o no atual, precisa ir para a direita
    {
      t->right = bstInsert(t->right, data, cmp);
    }
    return t;
  }
  else// Espaco disponivel para o node, ele e alocado e posicionado
  {
    newNode = bstCreate(newNode, data);
    if(newNode != NULL)
      return newNode;
    else
      return NULL;
  }
}// bstInsert

void *bstQuery(TNode *t, void *key, int (*cmp)(void *, void *))
{
  int stat;

  if(t != NULL)
  {
    stat = cmp(key, t->data);

    if(stat == 0)// Achou
    {
      return t->data;
    }
    else if(stat < 0)// Menor que o no atual, busca segue para a esquerda
    {
      return bstQuery(t->left, key, cmp);
    }
    else// Maior que o no atual, busca segue para a direita
    {
      return bstQuery(t->right, key, cmp);
    }
  }
  return NULL;
}// bstQuery

TNode *bstRemoveSmallest(TNode *t, void *key, int (*cmp)(void *, void *), void **data)
{
  TNode *temp;

  if(t != NULL)
  {
    if(t->left == NULL)// O primeiro node sem sub-arvore esquerda e o menor
    {
      *data = t->data;// Devolve o dado do node
      if(t->right != NULL)// Se o node possui sub-arvore direita, deve posiciona-la onde ele estava
      {
        temp = t->right;
        free(t);
        return temp;
      }
      else// Se o node e folha, so precisa ser deletado
      {
        free(t);
        return NULL;
      }
    }
    else// Havendo sub-arvore esquerda, segue-se para ela
    {
      t->left = bstRemoveSmallest(t->left, key, cmp, data);
      return t;
    }
  }
  return NULL;
}// bstRemoveSmallest

TNode *bstRemove(TNode *t, void *key, int (*cmp)(void *, void *), void **data)
{
  void *data2;
  TNode *temp;
  int stat;

  if(t != NULL)
  {
    stat = cmp(key, t->data);
    if(stat < 0)// Menor que o no atual, busca segue para a esquerda
    {
      t->left = bstRemove(t->left, key, cmp, &data2);
      *data = data2;// Data deve ser manipulado para que o valor desejado chegue na primeira chamada
      return t;
    }
    else if(stat > 0)// Maior que o no atual, busca segue para a direita
    {
      t->right = bstRemove(t->right, key, cmp, &data2);
      *data = data2;
      return t;
    }
    else// Achou
    {
      if(t->left == NULL)// Sem sub-arvore esquerda, a direita assume a posicao do node deletado
      {
        temp = t->right;
        *data = t->data;
        free(t);
        return temp;
      }
      else if(t->right == NULL)// Sem sub-arvore direita, a esquerda assume a posicao do node deletado
      {
        temp = t->left;
        *data = t->data; 
        free(t);
        return temp;
      }
      else
      {
        *data = t->data;
        // Com sub-arvores esquerda e direita, o menor node da direita precisa assumir a 
        // posicao do node deletado para manter a coerencia da arvore
        t->right = bstRemoveSmallest(t->right, key, cmp, &data2);
        t->data = data2;
        return t;
      }
    }
  }
  *data = NULL;// Retornando nulo para o data para indicar a nao deteccao do node desejado
  return NULL;
}// bstRemove

void *bstGreaterNode(TNode *t)
{
  if (t != NULL)
  {
    if (t->right != NULL)// Havendo sub-arvore direita, segue-se para ela
    {
      return bstGreaterNode(t->right);
    }
    return t->data;// O primeiro node a nao possuir sub-arvore direita e o maior
  }
  return NULL;
}// bstGreaterNode