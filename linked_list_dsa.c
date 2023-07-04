#include <stdio.h>
#include <stdlib.h>


//self referential structure
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[], int n)
{
    struct Node *t, *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i = 1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Create(int n)
{
    struct Node *t, *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    scanf("%d",&first->data);
    first->next=NULL;
    last=first;
    for(int i = 1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &t->data);
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void Display(struct Node *p)
{
    if(p==NULL)
    {
        return;
    }
    printf("%d ", p->data);
    Display(p->next);
}

int main()
{
    Create(5);
    //Create(7);
    Display(first);
    return 0;
}