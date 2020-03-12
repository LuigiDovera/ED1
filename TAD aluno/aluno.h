#ifndef _ALUNO_H_
#define _ALUNO_H_
    #ifndef _ALUNO_C_

        typedef struct _aluno_{
            char nome[50];
            int cpf;
            float saldoBanco;
        } Aluno;

        typedef struct _cofoAluno_{
            int nElms;
            int maxElms;
            Aluno **elm;
        } CofoAluno;

        CofoAluno *cofoCreate(int n);
        int cofoInsert(CofoAluno *c, Aluno *a);
        int cofoRemove(CofoAluno *c, int cpf);
        Aluno *cofoQuerry(CofoAluno *c, int cpf);
        int cofoDestroy(CofoAluno *c);
    #else
        typedef struct _aluno_ Aluno;
        typedef struct _cofoAluno_ CofoAluno;

        extern CofoAluno *cofoCreate(int n);
        extern int cofoInsert(CofoAluno *c, Aluno *a);
        extern int cofoRemove(CofoAluno *c, int cpf);
        extern Aluno *cofoQuerry(CofoAluno *c, int cpf);
        extern int cofoDestroy(CofoAluno *c);
    #endif


#endif // ALUNO_H_INCLUDED
