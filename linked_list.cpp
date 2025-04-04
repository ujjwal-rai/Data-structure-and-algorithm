#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* first;
public:
    LinkedList()
    {
        first=NULL;
    }
    LinkedList(int A[], int n);
    ~LinkedList();
    void Display();
    void Insert(int index, int x);
    int Length();
    void Delete(int index);
};

LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i = 1; i<n; i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=last->next;
    }
}
LinkedList::~LinkedList()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}
void LinkedList::Display()
{
    Node *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<"\n";
}
int LinkedList::Length()
{
    int count = 0;
    Node *p=first;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}
void LinkedList::Delete(int index)
{
    Node *p = first;
    Node *t=NULL;
    if(index<0 || index>=Length())
        return;
    if(index==0)
    {
        first=first->next;
        delete p;
    }
    else
    {
        for(int i = 0; i<index; i++)
        {
            t=p;
            p=p->next;
        }
        t->next=p->next;
        delete p;
    }
}
void LinkedList::Insert(int index, int x)
{
    Node *t, *p=first;
    if(index < 0 || index > Length())
        return;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(index==0)
    {
        t->next=p;
        first=t;
    }
    else
    {
        for(int i = 1; i<index; i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

int main()
{
    int A[]={1,2,3,4,5};
    LinkedList l(A,5);
    l.Insert(5,6);
    l.Delete(6);
    l.Display();
    cout<<l.Length();
    return 0;
}
