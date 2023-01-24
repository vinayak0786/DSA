#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int a[])
{
    struct node *p, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < 5; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}
void display(struct node *p)
{
    if (p != NULL)

    {
        printf("%d ", p->data);
        display(p->next);
    }
}
//

// Recursion to find max

// int find_max(struct node *p)
// {
//     int x = 0;
//     if (p == NULL)
//         return x;
//     x = find_max(p->next);
//     return x > p->data ? x : p->data;
// }

int find_max()
{
    struct node *p=first;
    int m=p->data;
    p=p->next;
    while(p!=NULL)
    {
        if(m<p->data)
        m=p->data;
        p=p->next;
    }
    return m;
}

void main()
{
    int a[] = {1, 2, 5, 4,3 };
    create(a);
    display(first);
    printf("\nMax Element is:%d\n", find_max());
    // printf("\nMax Element is:%d\n", find_max(first));
}