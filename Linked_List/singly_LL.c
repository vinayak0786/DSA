#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *first = NULL;

void insert_first(int ele)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = ele;
    p->next = NULL;

    if (first == NULL)
    {
        first = p;

        printf("Ele insered successfully:%d\n", p->data);
    }
    else
    {
        p->next = first;

        first = p;

        printf("Ele insered successfully:%d\n", p->data);
    }
}

void insert_last(int ele)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = ele;
    p->next = NULL;

    if (first == NULL)
    {
        first = p;
        printf("Ele insered successfully:%d\n", p->data);
    }
    else
    {
        struct node *t = first;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = p;

        printf("Ele insered successfully:%d\n", p->data);
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
void insert_pos(int ele, int pos)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = ele;
    p->next = NULL;

    if (pos == 0)
    {
        p->next = first;
        first = p;
        printf("Ele insered successfully:%d\n", p->data);
    }
    else
    {
        struct node *t = first;
        for (int i = 0; i < pos - 1; i++)
        {
            t = t->next;
        }

        p->next = t->next;
        t->next = p;
        printf("Ele insered successfully:%d\n", p->data);
    }
}
void delete_front()
{
    struct node *p = first;

    first = first->next;
    printf("Deleted Successfully:%d\n", p->data);
    free(p);
}
void delete_pos(int pos)
{
    struct node *p = first;
    struct node *q = NULL;

    if(pos==0)
    {
        first=first->next;
        free(p);

    }
    else{

    

    for (int i = 0; i < pos - 1; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    printf("Deleted Successfully:%d\n", p->data);
    free(p);
}
}
void main()
{
    int ch, ele, pos;

    printf("1.Insert before first\n 2.Insert at pos\n 3.Insert at last\n4.Display\n 5.delete from first\n6.delete at pos\n");

    while (1)
    {
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number to be inserted\n");
            scanf("%d", &ele);
            insert_first(ele);
            break;
        case 2:

            printf("Enter the number to be inserted\n");
            scanf("%d", &ele);
            printf("Enter the position where ele to be inserted\n");
            scanf("%d", &pos);
            insert_pos(ele, pos);
            break;
        case 3:
            printf("Enter the number to be inserted\n");
            scanf("%d", &ele);
            insert_last(ele);
            break;
        case 4:
            display();
            break;
        case 5:
            delete_front();
            break;
        case 6:
          printf("Enter the position where ele to be inserted\n");
            scanf("%d", &pos);
            delete_pos( pos);
            break;
        default:
            printf("Invalid Choice!!!!\n");
        }
    }
}