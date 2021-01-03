#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"
#include "aluno.h"

#define TRUE 1
#define FALSE 0

//Declarando globalmente para facilitar modularizacao do codigo
TNode *alunos = NULL;
Aluno *aluno = NULL;

//Testa se um ponteiro e NULL
int testa(void *arg);
//Opcoes do menu implementadas em funcoes para modularizacao do codigo
void opcInserirAluno();
void opcRemoverAluno();
void opcBuscarAluno();
void opcListarAlunos();

int main(void) 
{
  int opcao = 0;
  
  do
  {  
    //Menu
    printf("====================================================\n");
    printf("Bem-vindo ao registro de alunos! O que deseja fazer?\n\n");
    printf("1 - Inserir aluno\n");
    printf("2 - Remover aluno\n");
    printf("3 - Buscar aluno\n");
    printf("4 - Listar alunos\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);
    printf("\n");
    switch(opcao)
    {
      case 1: //Inserir aluno
        opcInserirAluno();
      break;

      case 2: //Remover aluno
        opcRemoverAluno();
      break;

      case 3: //Buscar aluno
        opcBuscarAluno();
        break;

      case 4: //Listar alunos
        opcListarAlunos();
      break;

      case 0: //Sair
        printf("Programa encerrado.\n");
      break;

      default: //Opcao invalida
        printf("Opcao invalida, escolha novamente...\n");
      break;
    }//switch
    printf("\n");
  } while(opcao != 0); 
  return 0;
}//Fim da main

//Funcao que testa um ponteiro qualquer para checar se e nulo
int testa(void *arg)
{
  if(arg == NULL)
  {
    return FALSE;
  }
  return TRUE;
} 

/* Funcoes criadas para garantir modularizacao */

void opcInserirAluno()
{
  printf("-----Inserindo aluno -----\n");
  //Variaveis de suporte a entrada
  char nome[TAMANHONOME];
  int idade;
  float media;

  //Entrada do usuario e alocacao de um Aluno para ser o data da bstInsert()
  printf("Insira o nome: ");
  getchar(); //No repl.it o fflush() nao esta funcionando
  fflush(stdin);
  fgets(nome, TAMANHONOME, stdin);
  fflush(stdin);
  printf("Insira a idade: ");
  scanf("%d", &idade);
  printf("Insira a media: ");
  scanf("%f", &media);
  printf("\n");
  aluno = criarAluno(nome, idade, media);

  if(testa(aluno))
  { 
    //Tentativa de insercao
    alunos = bstInsert(alunos, aluno, compararAlunos);
    if(alunos != NULL)
    {
      printf("Inserindo aluno!\n");
    }
    else
    {
      //So e valido para a insercao da raiz, apos disso nao detecta mais erro
      printf("Erro de insercao, tente novamente.\n");
    }
  } 
  else 
  {
    //Se deu erro ao alocar o Aluno para manipulacao
    printf("Erro de memoria! Tente novamente...\n");
  }
} //Inserir aluno

void opcRemoverAluno()
{
  if(testa(alunos))
  {
    char nome[TAMANHONOME];
    int idade=0;
    float media=0;

    //Entrada do usuario e alocacao de um Aluno para ser a key da bstRemove()
    getchar();
    fflush(stdin);
    printf("Insira o nome: ");
    fgets(nome, TAMANHONOME, stdin);
    printf("\n");
    aluno = criarAluno(nome, idade, media);
    
    if(testa(aluno))
    { 
      Aluno *data;
      //Tentativa de remocao
      alunos = bstRemove(alunos, aluno, compararAlunos, (void **)&data);

      //Se o aluno desejado tiver sido "retornado" no data, deu tudo certo
      if(compararAlunos(data, aluno) == 0)
      {
        printf("Aluno removido.\n");
      }
      else
      {
        printf("Aluno nao encontrado ou erro de remocao, tente novamente.\n");
      }
      free(aluno);
    } 
    else 
    {
      printf("Erro de memoria! Tente novamente...\n");
    }
    return;
  }
  //Se a colecao esta sem alunos
  printf("Colecao vazia...\n"); 
} //Remover aluno

void opcBuscarAluno()
{
  if(testa(alunos))
  {
    char nome[TAMANHONOME];
    int idade=0;
    float media=0;
    
    //Entrada do usuario e alocacao de um Aluno para ser a key da bstQuery()
    getchar();
    fflush(stdin);
    printf("Insira o nome: ");
    fgets(nome, TAMANHONOME, stdin);
    aluno = criarAluno(nome, idade, media);
    
    if(testa(aluno))
    {
      if(bstQuery(alunos, aluno, compararAlunos) != NULL)
      {
        printf("Aluno existente na colecao.\n");
      }
      else
      {
        printf("Aluno nao existente na colecao.\n");
      }
      free(aluno);
    } 
    else 
    {
      printf("Erro de memoria! Tente novamente...\n");
    }
    return;
  }
  printf("Colecao vazia...\n"); 
} //Buscar aluno

void opcListarAlunos()
{
  if(testa(alunos))
  { 
    bstInOrder(alunos, imprimeAluno); //Com bstInOrder (simetrica), imprime em ordem alfabetica
  }
  else
  {
    printf("Nao existe colecao...\n"); 
  }
} //Listar alunos