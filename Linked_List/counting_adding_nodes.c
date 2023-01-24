/*creating a linked list and storing array elements in the linked list and
displaying it */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

// int count()
// {
//     int count=0;
//     struct node *p=first;
//     while(p!=NULL)
//     {
//         count++;
//         p=p->next;

//     }
//     return count;

// }

// RECURSION fn to count

int counting(struct node *p)
{

    if (p != NULL)
    {

        return counting(p->next) + 1;
    }
    else
    {
        return 0;
    }
}

// int sumLL()
// {
//     struct node *p=first;
//     int sum=0;
//     while(p!=NULL)
//     {
//         sum+=p->data;
//         p=p->next;

//     }
//     return sum;
// }

// RECURSION fn to sum

int sumLL(struct node *p)
{

    if (p != NULL)
    {

        return sumLL(p->next) + p->data;
    }
    else
        return 0;
}

void create(int a[])
{
    struct node *p, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i <= 4; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}
void display()
{
    struct node *p = first;
    while (p != NULL)

    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a);
    display();
    // printf("Total number nodes: %d",count());
    printf("Total number nodes: %d\n", counting(first));
    //  printf("SUM of LL: %d\n",sumLL());
    printf("SUM of LL: %d\n", sumLL(first));
}