#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"

int inversivel(char str[]);

int main()
{
    char str1[] = "ABCBA";
    char str2[] = "ACAB";
    char str3[] = "ABCA";
    char str4[] = "ABCAA";

    printf("%d %d %d %d\n", inversivel(str1), inversivel(str2), inversivel(str3), inversivel(str4));

    system("pause");
}

int inversivel(char str[])
{

    Stack *s = NULL;
    char *pch = NULL;

    s = stkCreate(strlen(str)/2);

    int push = TRUE;
    int contPush = 0;
    int contPop = 0;

    for (int i = 0; i < strlen(str); i++)
    {      
        
        if (str[i] == 'C')
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
            contPop++;  
            pch = stkPop(s) ;
            if (!stkIsEmpty(s) && *(char *)pch != str[i])
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