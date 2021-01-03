#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"


typedef struct _aluno_
{
  char nome[TAMANHONOME]; //Definido em aluno.h 
  int idade;
  float media;
} Aluno;

Aluno *criarAluno(char nome[], int idade, float media)
{
  //Aloca um Aluno para insercao no campo data dos nodes do TAD
  Aluno *aluno = (Aluno *) malloc(sizeof(Aluno));
  if(aluno != NULL)
  {
    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->media = media;
    return aluno;
  }
  return NULL;
}

int compararAlunos(void *aluno1, void *aluno2)
{
  if(aluno1 == NULL)
  {
    return -1; 
    //Pelo modo como strcmp funciona, TRUE e FALSE nao sao suficientes para verificar erro
  }
  else if(aluno2 == NULL)
  {
    return 1;
  }
  else
  {
    //strcmp retorna 0 se strings forem iguais, e 1 ou -1 se forem diferentes
    return strcmp(((Aluno *)aluno1)->nome, ((Aluno *)aluno2)->nome);
  }//Ao menos um Aluno nao existente
}

void imprimeAluno(void *aluno){
  printf("Nome: %sIdade: %d\nMedia: %.2f\n\n", pegarNome(aluno), pegarIdade(aluno), pegarMedia(aluno));
}


/* Funcoes de coleta dos campos do Aluno para evitar acessar diretamente
do programa usuario (possibilidade de erro) */

char *pegarNome(Aluno *aluno)
{
  if(aluno != NULL){
    return aluno->nome;
  }
  return NULL;
}

int pegarIdade(Aluno *aluno)
{
  if(aluno != NULL){
    return aluno->idade;
  }
  return -1;
}

float pegarMedia(Aluno *aluno)
{
  if(aluno != NULL){
    return aluno->media;
  }
  return -1;
}

int tamanhoNome()
{
  return TAMANHONOME;
}