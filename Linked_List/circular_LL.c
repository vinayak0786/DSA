#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

// void create(int a[])
// {
//     struct node *p, *last;
//     head = (struct node *)malloc(sizeof(struct node));
//     head->data = a[0];
//     head->next = head;
//     last = head;

//     for (int i = 1; i < 6; i++)
//     {
//         p = (struct node *)malloc(sizeof(struct node));
//         p->data = a[i];
//         p->next = last->next;
//         last->next = p;
//         last = p;
//     }
// }

void insert(int pos, int x)
{
    struct node *t, *p;
    if (pos == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            p = head;
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        p = head;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
void display(struct node *p)
{
    do
    {

        printf("%d ", p->data);
        p = p->next;

    } while (p != head);
    printf("\n");
}

// Recursive Display

void Rdisplay(struct node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        printf("%d ", p->data);
        Rdisplay(p->next);
    }
}
void main()
{
    int a[] = {1, 2, 3, 4, 5, 6};

    insert(0, 10);
    insert(1, 20);
    insert(2, 30);
    insert(3, 40);
    insert(4, 50);
    insert(0, 60);
    display(head);
    Rdisplay(head);
}