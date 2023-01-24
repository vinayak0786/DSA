/*Improved searching in Linked List*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*first=NULL;

void createLL(int a[])
{
    struct node *p,*last;
    first=(struct node*)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<5;i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=a[i];
        p->next=NULL;
        last->next=p;
        last=p;

    }
}
void display()
{
    struct node *p=first;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void improved_search(int key)
{
    struct node *p=first,*q=NULL;
    int flag=0;

    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            printf("\n Ele Found\n");
            flag=1;

        }
       
        
        q=p;
        p=p->next;
    }
    if(flag==0)
    printf("\nNot found\n");
    


    
    
}
void main()
{
    int a[]={1,2,3,4,5};
    createLL(a);
    display();
    int key=3;
    improved_search(key);
    display();
}