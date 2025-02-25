#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
//____qcodep____

char* checkSubstr(char s1[],char s2[])
{
    int len1=strlen(s1);
    int len2=strlen(s2);
    int ex[26]={0};
    for(int i=0;i<len1;i++)
    {
        ex[(int)(s1[i]-'a')]++;
    }
    for(int i=0;i<len2;i++)
    {
        int ex2[26]={0};
        for(int j=0;j<len1;j++)
        {
            ex2[(int)(s2[i+j]-'a')]++;
        }
        int flag=1;
        for(int j=0;j<26;j++)
        {
            if(ex[j]!=ex2[j])
            {
                flag=0;
            }
        }
        if(flag==1)
        {
            return &s2[i];
        }
    }
    return NULL;
}


int main()
{
    char s1[220], s2[220];
    char *pRes = NULL;

    scanf("%s%s", s1, s2);
    pRes = checkSubstr(s1, s2);

    if ( pRes == NULL )
        printf("false\n");
    else{
        pRes[ strlen(s1) ] = '\0';
        printf("%s", pRes);
    }
    return 0;
}