/* Program to reverse a string */
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
char pop()
{
    return stack[top--];
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
    for(i=0;i<l;i++)
        rev[i]=pop();
    rev[i]='\0';
    puts(rev);
    return 0;
}
------------------------------------