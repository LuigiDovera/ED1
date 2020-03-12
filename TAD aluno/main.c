#include <stdio.h>
#include <stdlib.h>
#include "aluno.c"

int main()
{
    CofoAluno *c = cofoCreate(3);
    Aluno *a1 = (Aluno *) malloc(sizeof(Aluno));
    Aluno *a2 = (Aluno *) malloc(sizeof(Aluno));
    Aluno *a3 = (Aluno *) malloc(sizeof(Aluno));

    a1->cpf = 1;
    strcpy(a1->nome, "Luigi");
    a1->saldoBanco = 40;

    a2->cpf = 2;
    strcpy(a2->nome, "Arthur");
    a2->saldoBanco = 0;

    printf("%d %d ",cofoInsert(c, a1), cofoInsert(c, a2));
    printf("%s\n", cofoQuerry(c, 2)->nome);
    printf("%d %d %d", cofoRemove(c, 1), cofoRemove(c, 2), cofoDestroy(c));

    return 0;
}
