#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"
#include "aluno.h"

#define TRUE 1
#define FALSE 0

//Declarando globalmente para facilitar modularizacao do codigo
SLList *alunos = NULL;
Aluno *aluno = NULL;

//Testa se um ponteiro e NULL
int testa(void *arg);
//Opcoes do menu implementadas em funcoes para modularizacao do codigo
void opcInserirAluno();
void opcRemoverAluno();
void opcBuscarAluno();
void opcListarAlunos();
void opcContarAlunos();

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
    printf("5 - Contar alunos\n");
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

      case 5: //Contar alunos
        opcContarAlunos();
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
  if(!testa(alunos))
  {
    //Se a lista nao esta alocada deve-se alocar  
    alunos = sllCreate();
    if(!testa(alunos)) 
    {
      printf("Erro de memoria! Tente novamente...\n");
      return;
    }
  }
  
  printf("-----Inserindo aluno -----\n");
  //Variaveis de suporte a entrada
  char nome[TAMANHONOME];
  int idade;
  float media;

  //Entrada do usuário e alocacao de um Aluno para ser o data da sllInsertLast()
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
    if(sllInsertLast(alunos, aluno))
    {
      printf("Aluno inserido!\n");
    }
    else
    {
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
    int idade;
    float media;

    //Entrada do usuario e alocacao de um Aluno para ser a key da sllRemoveSpec()
    getchar();
    fflush(stdin);
    printf("Insira o nome: ");
    fgets(nome, TAMANHONOME, stdin);
    printf("Insira a idade: ");
    scanf("%d", &idade);
    printf("Insira a media: ");
    scanf("%f", &media);
    printf("\n");
    aluno = criarAluno(nome, idade, media);
    
    if(testa(aluno))
    {
      //Tentativa de remocao
      if(sllRemoveSpec(alunos, aluno, compararAlunos) != NULL)
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

    if(!testa(sllGetFirst(alunos))) 
    {
      //Se nao houver elementos na Colecao esta deve ser destruida
      if(sllDestroy(alunos))
      {
        printf("Sem mais registros, colecao destruida.\n");
        alunos = NULL;
      }
      else
      {
        /* A destruicao e chamada sempre que houver 0 alunos e por 
        isso o seguinte se aplica */
        printf("Colecao nao pode ser destruida! Por seguranca, ative a opcao de remocao novamente com valores aleatorios.\n");
      }
    }
    return;
  }
  //Se nao havia Colecao criada (sem alunos)
  printf("Nao existe colecao...\n"); 
} //Remover aluno

void opcBuscarAluno()
{
  if(testa(alunos))
  {
    char nome[TAMANHONOME];
    int idade;
    float media;
    
    //Entrada do usuario e alocacao de um Aluno para ser a key da sllQuery()
    getchar();
    fflush(stdin);
    printf("Insira o nome: ");
    fgets(nome, TAMANHONOME, stdin);
    printf("Insira a idade: ");
    scanf("%d", &idade);
    printf("Insira a media: ");
    scanf("%f", &media);
    printf("\n");
    aluno = criarAluno(nome, idade, media);
    
    if(testa(aluno))
    {
      if(sllQuery(alunos, aluno, compararAlunos))
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
  printf("Nao existe colecao...\n"); 
} //Buscar aluno

void opcListarAlunos()
{
  if(testa(alunos))
  {
    /* Recebendo o primeiro no e seu dado para exibir e percorrendo a
    lista repetindo a operacao */
    sllGetFirst(alunos);
    aluno = sllGetCurData(alunos);
    while(testa(aluno))
    {
      printf("<<<<--ALUNO-->>>>\n");
      printf("Nome: %sIdade: %d\nMedia: %.2f\n\n", pegarNome(aluno), pegarIdade(aluno), pegarMedia(aluno));
      //O %s esta pulando a linha automaticamente
      sllGetNext(alunos);
      aluno = sllGetCurData(alunos);
    }
  }
  else
  {
    printf("Nao existe colecao...\n"); 
  }
} //Listar alunos

void opcContarAlunos()
{
  if(testa(alunos))
  {
    int cont;
    cont = sllGetNumElms(alunos);
    if(cont == 0)
    {
      /* Caso impossivel enquanto o programa destruir a colecao ao 
      remover todos os elementos */
      printf("Nao existem alunos na colecao.\n");
    }
    else if(cont == 1) 
    {
      printf("Existe %d aluno na colecao.", cont);
    } 
    else if(cont > 1)
    {
      printf("Existem %d alunos na colecao.", cont);
    }
    else
    {
      printf("Erro! Tente novamente...");
    }
  }
  else{
    printf("Nao existe colecao...\n");
  }
} // Contar alunos