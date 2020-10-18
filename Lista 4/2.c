#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"

int ehPalindromo(char str[]);

int main()
{
    char str1[] = "ABCBA";
    char str2[] = "ABBA";
    char str3[] = "ABB";
    char str4[] = "AB";

    printf("%d %d %d %d\n", ehPalindromo(str1), ehPalindromo(str2), ehPalindromo(str3), ehPalindromo(str4));

    printf("%d\n", 3/2);

    system("pause");
}

int ehPalindromo(char str[])
{

    Stack *s = NULL;
    char *pch = NULL;

    s = stkCreate(strlen(str)/2);

    int push = TRUE;
    int contPush = 0;
    int contPop = 0;

    for (int i = 0; i < strlen(str); i++)
    {      
        if (i == strlen(str)/2 && strlen(str)%2==0)
        {
            push = FALSE;
            
        }
        else if (i == strlen(str)/2 && strlen(str)%2==1)
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
            if (*(char *)pch == str[i])
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