#include <stdlib.h>
#include <string.h>
#include "aluno.h"


typedef struct _aluno_
{
  char nome[TAMANHONOME];
  int idade;
  float media;
} Aluno;

int compararAlunos(void *aluno1, void *aluno2)
{
  if(aluno1 != NULL && aluno2 != NULL)
  {
    char *nome1 = ((Aluno *)aluno1)->nome;
    int idade1 = ((Aluno *)aluno1)->idade;
    float media1 = ((Aluno *)aluno1)->media;

    char *nome2 = ((Aluno *)aluno2)->nome;
    int idade2 = ((Aluno *)aluno2)->idade;
    float media2 = ((Aluno *)aluno2)->media;

    if(strcmp(nome1, nome2) == 0 //Se a comparação for verdadeira
    && idade1 == idade2 && media1 == media2) 
    {
      return TRUE;
    }
  }//Alunos não existentes
  return FALSE;
}

Aluno *criarAluno(char nome[], int idade, float media)
{
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

int tamanhoNome(){
  return TAMANHONOME;
}
