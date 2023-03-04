/*Program to reverse or invert a singly linked list*/
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *start=NULL;
node *newnode,*temp;
void reverse(node *start)
{
    node *prev,*cur,*next;
    prev=NULL;
    cur=start;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    temp=prev;
   while(temp!=NULL)
    {
        printf("%d--->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    
}
int main()
{
    int choice;
    do{
    newnode=(node *)malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
        temp=start;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    printf("Do u want to continue(1/0)\n");
    scanf("%d",&choice);
    }while(choice!=0);
    printf("Linked list elements are\n");
    temp=start;
    while(temp!=NULL)
    {
        printf("%d--->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    reverse(start);
    return 0;
}
