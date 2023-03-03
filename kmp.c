/* KMP Pattern matching */

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int f[20];
void failurefn(char pat[],int f[])
{
    int i=0,k=1;
    f[0]=0;
    while(k<strlen(pat))
    {
        if(pat[i]==pat[k])
        {
            f[k]=i+1;
            i++;
            k++;
        }
        else 
        {
            if(i==0)
            {
                f[k]=i;
                k++;
            }
            else
                i=f[i-1];
        }
    }
}
int kmp(char test[],char pat[])
{
    int i=0,j=0;
    while(i<strlen(test) && j<strlen(pat))
    {
        if(test[i]==pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j==0)
                i++;
            else
            {
                j=f[j-1];
            }
        }
    }
    if(j==strlen(pat))
        return i-strlen(pat);
    else
        return -1;
}
int main()
{
   char test[50],pat[20];
   int p;
   printf("Enter text string\n");
   gets(test);
   printf("Enter pattern string\n");
   gets(pat);
   failurefn(pat,f);
   p=kmp(test,pat);
   if(p!=-1)
        printf("Pattern present from index %d\n",p);
    else
        printf("Pattern not present\n");
    return 0;
}
