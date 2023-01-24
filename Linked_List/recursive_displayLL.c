/*creating a linked list and storing array elements in the linked list and
displaying it recursively*/

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
// void display(struct node *p)
// {
//     if (p != NULL)
//     {
//         printf("%d ", p->data);
//         display(p->next);
//     }
// }
void display(struct node *p)
{
    if (p != NULL)
    {
        display( p->next);
        printf("%d ", p->data);
        
    }
}
void main()
{
   int a[] = {1, 2, 3, 4, 5};
   create(a);
   display(first);

}