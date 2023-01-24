//Checking if LL is sorted or not

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} *first = NULL;

void create(int a[],int size)
{
    first = (struct node *)malloc(sizeof(struct node));
    struct node * p, *last;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < 10; i++)
    {
        p= (struct node *)malloc(sizeof(struct node));
        p->data=a[i];
        p->next=NULL;
        last->next=p;
        last=p;

    }
}
int is_sort()
{
    struct node *p=first;
    int x=p->data;
    p=p->next;
    while(p!=NULL)
    {
        if(p->data<x)
        return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

void display(struct node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        display(p->next);

    }
    
}
void main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(a) / sizeof(a[0]);
    printf("%d\n", size);
    create(a,size);
    display(first);
    if(is_sort()==1)
    printf("\nSorted LL\n");
    else
    printf("\nUnsorted LL\n");

}