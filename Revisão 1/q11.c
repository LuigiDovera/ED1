#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "stack.h"

int marcacao(char str[])
{
    int tamStr = strlen(str);

    Stack *stk = NULL;
    char *pch = NULL;

    stk = stkCreate(tamStr);

    int push = TRUE;

    for (int i = 0; i < tamStr; i++)
    {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            pch = (char*) malloc(sizeof(char));
            if (pch != NULL)
            {
                *pch = str[i];
                stkPush(stk, pch);
            }
        }

        if(str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            pch = stkPop(stk);
            if(*pch != str[i])
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

int ehPalindromo(char str[])
{

    Stack *s = NULL;
    char *pch = NULL;

    s = stkCreate(strlen(str) / 2);

    int push = TRUE;
    int contPush = 0;
    int contPop = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (i == strlen(str) / 2 && strlen(str) % 2 == 0)
        {
            push = FALSE;
        }
        else if (i == strlen(str) / 2 && strlen(str) % 2 == 1)
        {
            push = FALSE;
            i++;
        }

        if (push)
        {
            pch = (char *)malloc(sizeof(char));
            if (pch != NULL)
            {
                *pch = str[i];
                stkPush(s, pch);
                contPush++;
            }
        }
        else
        {

            pch = stkPop(s);
            if (*pch == str[i])
            {
                contPop++;
            }
            else
            {
                return FALSE;
            }
            free(pch);
        }
    }

    stkDestroy(s);

    if (contPush == contPop)
    {
        return TRUE;
    }

    return FALSE;
}

int main()
{   
    printf("%d\n", marcacao("aaa{}aa"));
    system("pause");
    return 0;
}