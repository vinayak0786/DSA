// Reversing from LL

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;

} *first = NULL;

void create(int a[], int size)
{
    first = (struct node *)malloc(sizeof(struct node));
    struct node *p, *last;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < 10; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}

// void reverse1()
// {
//     struct node *p;
//     p=first;
//     int a[10],i=0;

//     while(p!=NULL)
//     {
//         a[i]=p->data;
//         p=p->next;
//         i++;

//     }
//     p=first,i--;
//     while(p!=NULL)
//     {
//         p->data=a[i--];
//         p=p->next;
//     }

// }


//Method 2:Sliding Pointer

// void reverse2()
// {
//     struct node *p=first,*q=NULL,*r=NULL;

//     while(p!=NULL)
//     {
//         r=q;
//         q=p;        
//         p=p->next;
//         q->next=r;
//     }
//     first=q;
    

// }

//Method:3 Recursive reversing

void reverse3(struct node *q,struct node *p)
{
    if(p!=NULL)
    {
        reverse3(p,p->next);
        p->next=q;

    }
    else
    first=q;
    
}

void display(struct node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        display(p->next);
    }
   
}

void main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(a) / sizeof(a[0]);
    printf("%d\n", size);
    create(a, size);

    display(first);
    // reverse1();
     printf("\n");
    //reverse2();
       reverse3(NULL,first);
    display(first);

}