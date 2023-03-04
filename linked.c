/* program to concatenate two linked lists*/
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *first=NULL;
node *second=NULL;
node * create(node *start)
{
    node *p,*t;
    int choice;
    do{
    p=(node *)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&p->data);
    p->next=NULL;
    if(start==NULL)
    {
       start=p;
       t=p;
    }
    else
    {
        t->next=p;
        t=p;
    }
    printf("Do u want to continue(0/1)\n");
    scanf("%d",&choice);
    }while(choice!=0);
    return start;
}
void display(node *start)
{
    node *t;
    if(start==NULL)
        printf("Empty list\n");
    else
    {
        t=start;
        while(t!=NULL)
        {
            printf("%d\t",t->data);
            t=t->next;
        }
        printf("\n");
    }
}
node *concatenate(node *first,node *second)
{
    node *t;
    if(first==NULL)
        return second;
    else if(second==NULL)
        return first;
    else
    {
        t=first;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=second;
    }
    return first;
}

int main()
{
    
    printf("Enter elements of first LL\n");
    first=create(first);
    printf("First Linked list\n");
    display(first);
    printf("Enter elements of second LL\n");
    second=create(second);
    printf("second Linked list\n");
    display(second);
    first=concatenate(first,second);
    printf("Concatenated list\n");
    display(first);
    return 0;
}
