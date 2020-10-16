#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"
#include "aluno.h"

#define TRUE 1
#define FALSE 0

Colecao *alunos = NULL;
Aluno *aluno = NULL;

int testa(void *arg);
void opcInserirAluno();
void opcRemoverAluno();
void opcBuscarAluno();
void opcListarAlunos();


int main(void) 
{
  int opcao = 0;
  
  do
  {
    printf("====================================================\n");
    printf("Bem-vindo ao registro de alunos! O que deseja fazer?\n\n");
    printf("1 - Inserir aluno\n");
    printf("2 - Remover aluno\n");
    printf("3 - Buscar aluno\n");
    printf("4 - Listar alunos\n");
    printf("5 - Sair\n");
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

      case 5: //Sair
        printf("Programa encerrado.\n");
      break;

      default: //Opcao invalida
        printf("Opcao invalida, escolha novamente...\n");
      break;
    }//switch
    printf("\n");
  } while(opcao != 5);

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

/* Funcoes criadas para seguranca contra dupla declaracao */

void opcInserirAluno()
{
  if(!testa(alunos))
  {
    int tamanho;

    printf("A Colecao de alunos ainda não foi criada. Por favor, insira o tamanho da Colecao:\n");
    scanf("%d", &tamanho);
    
    alunos = colCriar(tamanho);
    if(!testa(alunos)) //Se nao alocado
    {
      printf("Erro de memoria! Tente novamente...\n");
      return;
    }
  }
  
  printf("-----Inserindo aluno -----\n");
  char nome[TAMANHONOME];
  int idade;
  float media;

  
  printf("Insira o nome: ");
  getchar();
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
    if(colInserir(alunos, aluno))
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
}

void opcRemoverAluno()
{
  if(testa(alunos))
  {
    char nome[TAMANHONOME];
    int idade;
    float media;

    getchar();//No repl.it o fflush() nao esta funcionando
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
      if(colRemover(alunos, aluno, compararAlunos) != NULL)
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

    if(!testa(pegarPrim(alunos))) //Se nao houver elementos na Colecao
    {
      if(colDestruir(alunos))
      {
        printf("Sem mais registros, colecao destruida.\n");
        alunos = NULL;
      }
      else
      {
        printf("Colecao nao pode ser destruida! Por seguranca, ative a opcao de remocao novamente com valores aleatorios.\n");
      }
    }
    return;
  }
  //Se nao havia Colecao criada (sem alunos)
  printf("Nao ha alunos registrados...\n"); 
}

void opcBuscarAluno()
{
  if(testa(alunos))
  {
    char nome[TAMANHONOME];
    int idade;
    float media;
    
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
      if(colBuscar(alunos, aluno, compararAlunos))
      {
        printf("Aluno existente na colecao\n");
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
  printf("Nao ha alunos registrados...\n"); 
}

void opcListarAlunos()
{
  if(testa(alunos))
  {
    aluno = pegarPrim(alunos);
    while(testa(aluno))
    {
      printf("<<<<--ALUNO-->>>>\n");
      printf("Nome: %s\nIdade: %d\nMedia: %.2f\n\n", pegarNome(aluno), pegarIdade(aluno), pegarMedia(aluno));
      //O %s esta pulando a linha automaticamente
      aluno = pegarProx(alunos);
    }
  }
  else
  {
    printf("Nao ha alunos registrados...\n"); 
  }
}