/*Program to read and display polynomial of single variable */
#include <stdio.h>
typedef struct
{
    int coef;
    int expon;
}poly;
poly p1[20],p2[20],p3[20];
void read(poly p[],int n)
{
    int i;
    printf("Enter coefficient and exponents in decreasing order of exponents\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].coef,&p[i].expon);
    }
}
void display(poly p[],int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        printf(" %dx^%d+",p[i].coef,p[i].expon);
    }
    printf(" %dx^%d\n",p[i].coef,p[i].expon);
}
void main()
{
    int n1,n2;
    printf("Enter first polynomial\n");
    printf("Enter number of terms\n");
    scanf("%d",&n1);
    read(p1,n1);
    printf("Enter second polynomial\n");
    printf("Enter number of terms\n");
    scanf("%d",&n2);
    read(p2,n2);
    printf("First polynomial is\n");
    display(p1,n1);
    printf("Second polynomial is\n");
    display(p2,n2);
}
