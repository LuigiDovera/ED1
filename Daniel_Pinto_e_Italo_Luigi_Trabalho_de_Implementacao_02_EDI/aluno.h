#ifndef ALUNO_H
#define ALUNO_H

#define TRUE 1
#define FALSE 0

#define TAMANHONOME 30

typedef struct _aluno_ Aluno;

Aluno *criarAluno(char nome[], int idade, float media);
int compararAlunos(void *aluno1, void *aluno2);

char *pegarNome(Aluno *aluno);
int pegarIdade(Aluno *aluno);
float pegarMedia(Aluno *aluno);
int tamanhoNome();



#endif