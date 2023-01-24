// check Loop in LL
//  Merge two LL
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;

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

void display(struct node *p)
{

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void check_loop()
{
    struct node *p = first, *q = first;

    do
    {
        p = p->next;
        q = q->next;
        q = q  ? q->next : q;

    } while ((p && q)&& (p!=q));
    if ((p == q) )
    {
        printf("\nLoop\n");
        return;
    }

    printf("\nLinear\n");
}

void main()
{
    struct node *t1, *t2;
    int a[] = {2, 8, 10, 15, 13, 22};

    create(a);
    t1 = first->next->next;
    t2 = first->next->next->next->next->next;
    t2->next = t1;

    

    check_loop();

    printf("\n");
}