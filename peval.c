/*Polynomial evaluation using Linked List*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int coef;
    int expon;
    struct node *next;
};
typedef struct node node;
node *head;
void attachpoly(node *head,int co,int ex)
{
    node *p,*t;
    p=(node *)malloc(sizeof(node));
    p->coef=co;
    p->expon=ex;
    p->next=NULL;
    t=head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=p;
}
void display(node *head)
{
    node *p;
    p=head->next;
    while(p->next!=NULL)
    {
        printf("%dx^%d+",p->coef,p->expon);
        p=p->next;
    }
     printf("%dx^%d\n",p->coef,p->expon);
}
void readpoly(node *head)
{
    int n,co,ex,i;
    printf("Enter the number of terms\n");
    scanf("%d",&n);
    printf("Enter coeff,expon\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&co,&ex);
        attachpoly(head,co,ex);
    }
}
void evaluatepoly(node *head)
{
    int x,s=0;
    node *t;
    printf("Enter the value of x\n");
    scanf("%d",&x);
    t=head->next;
    while(t!=NULL)
    {
        s=s+t->coef*pow(x,t->expon);
        t=t->next;
    }
    printf("Sum=%d\n",s);
}
int main()
{
    head =(node *)malloc(sizeof(node));
    head->next=NULL;
    readpoly(head);
    display(head);
    evaluatepoly(head);
    return 0;
}
