/*Polynomial addition using Linked List*/
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
node *head1,*head2,*head3;
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
void addpoly(node *p1,node *p2,node *p3)
{
    int s;
    p1=p1->next;
    p2=p2->next;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->expon==p2->expon)
        {
            s=p1->coef+p2->coef;
            if(s!=0)
            {
                attachpoly(p3,s,p1->expon);
            }
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->expon>p2->expon)
        {
            attachpoly(p3,p1->coef,p1->expon);
            p1=p1->next;
        }
        else
        {
           attachpoly(p3,p2->coef,p2->expon);
            p2=p2->next; 
        }
    }
    while(p1!=NULL)
    {
        attachpoly(p3,p1->coef,p1->expon);
        p1=p1->next;
    }
     while(p2!=NULL)
     {
       attachpoly(p3,p2->coef,p2->expon);
       p2=p2->next;   
     }
}
int main()
{
    head1 =(node *)malloc(sizeof(node));
    head1->next=NULL;
    printf("Read first polynomial\n");
    readpoly(head1);
    head2 =(node *)malloc(sizeof(node));
    head2->next=NULL;
    head3=(node *)malloc(sizeof(node));
    head3->next=NULL;
    printf("Read second polynomial\n");
    readpoly(head2);
    addpoly(head1,head2,head3);
    printf("First polynomial\n");
    display(head1);
    printf("Second polynomial\n");
    display(head2);
    printf("Resultant polynomial\n");
    display(head3);
    return 0;
}


