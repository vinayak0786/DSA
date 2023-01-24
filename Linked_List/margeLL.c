// Merge two LL
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create(int a[])
{
    struct node *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;

    last = first;
    for (int i = 1; i < 6; i++)
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data = a[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}
void create1(int b[])
{
    struct node *last;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = b[0];
    second->next = NULL;

    last = second;
    for (int i = 1; i < 6; i++)
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data = b[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}
void display(struct node *p)
{

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void merge(struct node *p, struct node *q)
{
    struct node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
        if(p!=NULL)
        last->next=p;
        else
        last->next=q;
    }
}
void main()
{
    int a[] = {2,8,10,15,13,22}, b[] = {
                                      4,7,12,14,19,24};

    create(a);
    create1(b);
    merge(first, second);
    display(third);

    printf("\n");
}