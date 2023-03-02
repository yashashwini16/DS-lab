/*Program to add two polynomials */
#include <stdio.h>
typedef struct
{
    int coef;int expon;
}POLY;
POLY p1[10],p2[10],p3[10];
void read(POLY p[],int n)
{
    int i;
    printf("Enter coeff and expon\n");
    for(i=0;i<n;i++)
    {
    scanf("%d%d",&p[i].coef,&p[i].expon);
    }
}
void display(POLY p[],int n)
{
    int i;
    for(i=0;i<n-1;i++)
        printf("%dx^%d+",p[i].coef,p[i].expon);
    printf("%dx^%d\n",p[i].coef,p[i].expon);
}
int compare(int ex1,int ex2)
{
    if(ex1==ex2)
        return 0;
    else if(ex1>ex2)
        return 1;
    else
        return -1;
}
void add(int m,int n)
{
    int i=0,j=0,k=0,s;
    while(i<m && j<n)
    {
        int p=compare(p1[i].expon,p2[j].expon);
        switch(p)
        {
            case 0:
                 s=p1[i].coef+p2[j].coef;
                 if(s!=0)
                 {
                    p3[k].coef=s;
                    p3[k].expon=p1[i].expon;
                    k++;
                 }
                 i++;
                 j++;
                 break;
            case 1:
                p3[k].coef=p1[i].coef;
                p3[k].expon=p1[i].expon;
                k++;
                i++;
                break;
            case -1:
                p3[k].coef=p2[j].coef;
                p3[k].expon=p2[j].expon;
                k++;
                j++;
                break;
        }
    }
    while(i<m)
    {
        p3[k].coef=p1[i].coef;
                p3[k].expon=p1[i].expon;
                k++;
                i++;
    }
    while(j<n)
    {
        p3[k].coef=p2[j].coef;
                p3[k].expon=p2[j].expon;
                k++;
                j++;
    }
    display(p3,k);
}

int main()
{
   
    int m,n;
    printf("Enter number of terms of poly1\n");
    scanf("%d",&m);
    read(p1,m);
   display(p1,m);
   printf("Enter number of terms of poly2\n");
    scanf("%d",&n);
    read(p2,n);
   display(p2,n);
   printf("SUM\n");
   add(m,n);
    return 0;
}
