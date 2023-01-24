// Insert in sorted LL

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void insert(int ele)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = ele;
    p->next = NULL;

    if (first == NULL)
    {
        first = p;
        printf("Element inserted successfull:%d\n", p->data);
    }
    else
    {
        struct node *t=first;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=p;
        printf("Element inserted successfull:%d\n", p->data);

    }
}

void insert_sort(int ele)
{
    struct node *p=first,*q=NULL;
    while(p && p->data<ele)
    {
        q=p;
        p=p->next;
    }
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data=ele;
    t->next=q->next;
    q->next=t;
    printf("Element inserted successfull:%d\n", t->data);



      
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
    int ch, ele;
    printf("\n1.insert in sorted manner\n2.Insert in sorted list \n3.Display\n");

    while (1)
    {
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number to be inserted\n");
            scanf("%d", &ele);
            insert(ele);

            break;
        case 2:
            printf("Enter the number to be inserted\n");
            scanf("%d", &ele);
            insert_sort(ele);
            break;
            // case 2:
            //     insert_pos();
            //     break;

        case 3:
            display();
            break;
        default:
            printf("Invalid Choice!!!!\n");
        }
    }
}