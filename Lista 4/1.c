#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"

int inversivel(Stack *s, char str[]);

int main()
{
    Stack *s1 = NULL, *s2 = NULL, *s3 = NULL;

    char str1[] = "ABCBA";
    char str2[] = "ACAB";
    char str3[] = "ABCA";
    
    s1 = stkCreate(strlen(str1));
    s2 = stkCreate(strlen(str2));
    s3 = stkCreate(strlen(str3));

    printf("%d %d %d\n", inversivel(s1, str1), inversivel(s2, str2), inversivel(s3, str3));

    system("pause");
}

int inversivel(Stack *s, char str[])
{
    char *pch = NULL;

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
                printf("%d\n", contPush);
            }
        }
        else
        {
            if (*(char *)stkPop(s) == str[i] && !stkIsEmpty(s))
            {
                contPop++;
                printf("%d\n", contPop);
            }
        }
    }

    if (contPush == contPop)
    {
        return TRUE;
    }

    return FALSE;
}