//Concatenating two LL
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int a[])
{
    struct node *last;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    
    last=first;
    for(int i=1;i<6;i++)
    {
        struct node *p=(struct node *)malloc(sizeof(struct node));
        p->data=a[i];
        p->next=NULL;       
        last->next=p;
        last=p;

    }

}
void create1(int b[])
{
    struct node *last;
    second=(struct node *)malloc(sizeof(struct node));
    second->data=b[0];
    second->next=NULL;
    
    last=second;
    for(int i=1;i<6;i++)
    {
        struct node *p=(struct node *)malloc(sizeof(struct node));
        p->data=b[i];
        p->next=NULL;       
        last->next=p;
        last=p;

    }

}
void display(struct node *p)
{

    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
        
    }
    
}
void concat()
{
  
    struct node *p=first,*q=second;
      third=p;

    while(p->next!=NULL)

    {
        p=p->next;
    }
    p->next=q;
}
void main()
{
    int a[]={1,2,3,4,5,6},b[]={
        7,8,9,10,11,12};

    create(a);
    create1(b);
    concat();
    display(first);
    
    printf("\n");
     
}