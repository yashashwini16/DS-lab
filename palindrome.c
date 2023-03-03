/*program to check whether a given string is palindrome or not */
#include <stdio.h>
#include<string.h>
#define MAXSIZE 40
char stack[MAXSIZE];
int top=-1;
void push(char ch)
{
    top++;
    stack[top]=ch;
}
void palindrome()
{
    int i,temp;
    temp=top;
    for(i=0;i<=top/2;i++)
    {
        if(stack[i]!=stack[temp])
        {
            printf("Not palindrome\n");
            return;
        }
        temp--;
    }
    printf("Palindrome\n");
}
int main()
{
   char s[20],rev[20];
   int i,l;
   printf("Enter a string\n");
   gets(s);
   l=strlen(s);
   for(i=0;s[i]!='\0';i++)
        push(s[i]);
   palindrome();
    return 0;
}


