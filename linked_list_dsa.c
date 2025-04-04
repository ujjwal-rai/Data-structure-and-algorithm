#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//self referential structure
struct Node
{
    int data;
    struct Node *next;
}*first=NULL, *end=NULL, *z=NULL, *third=NULL;


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
    end=t;
}

void create2(int A[], int n)
{
    struct Node *t, *last;
    z=(struct Node *)malloc(sizeof(struct Node));
    z->data=A[0];
    z->next=NULL;
    last=z;
    for(int i = 1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    end=t;
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
        printf("\n");
        return;
    }
    else
    {
        printf("%d ", p->data);
        Display(p->next);
    }
}

int count(struct Node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}

int count1(struct Node *p)
{
    if(p==NULL)
        return 0;
    else
        return 1+count1(p->next);
}

int summ(struct Node *p)
{
    int c=0;
    while(p!=NULL)
    {
        c+=p->data;
        p=p->next;
    }
    return c;
}

int sum1(struct Node *p)
{
    if(p==NULL)
        return 0;
    else
        return p->data+sum1(p->next);
}

int maxi(struct Node *p)
{
    int max = p->data;
    p=p->next;
    while(p!=NULL)
    {
        if(max<p->data)
            max=p->data;
        p=p->next;
    }
    return max;
}

int maxi1(struct Node *p)
{
    int x = 0;
    if(p==NULL)
        return x;
    x=maxi1(p->next);
    return x>p->data ? x : p->data;
}

bool search_ll(struct Node *p, int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
            return true;
        p=p->next;
    }
    return false; 
}

bool Rsearch_ll(struct Node *p, int key)
{
    if(p==NULL)
        return false;
    if(key==p->data)
        return true;
    else
        Rsearch_ll(p->next, key);
}

bool mthsearch_ll(struct Node *p, int key)
{
    struct Node *q = NULL;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return true;
        }
        q=p;
        p=p->next;
    }
    return false;
}

void insert(struct Node *p, int pos, int key)
{
    struct Node *t;
    int i;
    if(pos<0 || pos > count(p))
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=key;
    t->next=NULL;
    if(pos==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i = 0; i<pos-1; i++)
        {
            p=p->next;
        }
        if(p->next==NULL)
        {
            end=t;
        }
        t->next=p->next;
        p->next=t;
    }
}

void insert_last(int x)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        end=t;
        first = end;
    }
    else
    {
        end->next=t;
        end=t;
    }
}

void insert_sorted(struct Node *p, int x)
{
    struct Node *t, *q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first = t;
    else
    {
        while(p && p->data < x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

void delete(struct Node *p, int pos)
{
    struct Node *q=NULL;
    if(pos==0)
    {
        first=first->next;
    }
    else
    {
        for(int i = 0; i<pos; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
    }
}

bool isSorted(struct Node *p)
{
    int x = p->data;
    while((p=p->next)!=NULL)
    {
        if(x>p->data)
        {
            return false;
        }
        x=p->data;
    }
    return true;
}

void remove_duplicate(struct Node *p)
{
    struct Node *q=p->next;
    while((q=p->next)!=NULL)
    {
        if(q->data==p->data)
        {
            p->next=q->next;
            free(q);
        }
        else
        {
            p=q;
        }
    }
}

void reverse_ll(struct Node *p)
{
    int z = count(p);
    int A[z];
    for(int i = 0; i<z; i++)
    {
        A[i]=p->data;
        p=p->next;
    }
    p=first;
    for(int i = z-1; i>=0; i--)
    {
        p->data=A[i];
        p=p->next;
    }
}

void reverse_llsp(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void recursive_reverse_ll(struct Node *q, struct Node *p)
{
    if(p!=NULL)
    {
        recursive_reverse_ll(p, p->next);
        p->next=q;
    }
    else
    {
        first = q;
    }
    
}

void concatanating(struct Node *p, struct Node *q)
{
    third=p;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
    q=NULL;
}

void merging(struct Node *p, struct Node *q)
{
    struct Node *lt=NULL;
    if(p->data<q->data)
    {
        third=lt=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=lt=q;
        q=q->next;
        third->next=NULL;
    }
    while (p!=NULL && q!=NULL)
    {
        if (p->data<q->data)
        {
            lt->next=p;
            lt=p;
            p=p->next;
            lt->next=NULL;
        }
        else
        {
            lt->next=q;
            lt=q;
            q=q->next;
            lt->next=NULL;
        }
    }
    if(p!=NULL)
    {
        lt->next=p;
    }
    else
    {
        lt->next=q;
    }
}

bool isloop(struct Node *p)
{
    struct Node *q=NULL;
    p=q=first;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:NULL;
    } while (p && q && p!=q);
    if(p==q)
        return true;
    else
        return false;
    
}

int findMiddle(struct Node* p)
{
    int x = -1;
    if(p)
    {
        struct Node* t = (struct Node*)malloc(sizeof(struct Node));
        t=first;
        while(p)
        {
            p=p->next;
            if(p)
            {
                p=p->next;
                t=t->next;
            }
        }
        x=t->data;
    }
    return x;
}

// void findIntersection(struct Node *p, struct Node *q)
// {
//     while(p!=NULL) push(&stk1,p);
//     while(q) push(&stk2, q);
//     while(stackTop(stk1)==stackTop(stk2))
//     {
//         p=pop(&stk1);
//         pop(&stk2);
//     }
//     printf("%d\n", p->data);
// }

int main()
{
    int A[]={2,8,10,15,9,14,13,12,11};
    create(A,9);
    printf("%d", findMiddle(first));
    return 0;
}
