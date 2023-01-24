/*We are performing searching in LL in both iterative and recursive manner*/

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




// void search(int ele)
// {
//     int flag=0,pos=0;
//     struct node *p=first;

//     while(p!=NULL)
//     {
        
//         if(p->data==ele)
//         {
//             flag= 1;
//             break;
//         }
//         else
//         pos++;
        
          
//         p=p->next;
//     }
//     if(flag==1)
//     {
//         printf("\nElement FOund at pos:%d\n",pos+1);
//     }
//     else
//     printf("\nElement  not FOund\n");

// }

//recursive funtion to search

void search(struct node *p,int ele,int pos)
{
    if(p==NULL)
    return ;
    else if(p->data==ele)
    {
        printf("Ele found at %d",pos+1);
        return;
    }
    else{
        pos++;
        search(p->next,ele,pos++);
    }



}

void main()
{
    int a[] = {1, 2, 5, 4,3 };
    create(a);
    display(first);
    int ele=5,pos=0;
    search(first,ele,pos);
   

    // 
}