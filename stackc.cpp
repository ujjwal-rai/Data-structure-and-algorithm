#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class Stack
{
private:
    Node *st;
public:
    Stack();
    ~Stack();
    void push(int val);
    void pop();
    void Display();
    int isEmpty();
    int isFull();
    int stackTop();
    int peek(int pos);
};

Stack::Stack()
{
    st=NULL;
}

Stack::~Stack()
{
    Node* t = st;
    while(st)
    {
        t=st;
        st=st->next;
        delete t;
    }
}
void Stack::Display()
{
    Node* t = st;
    while(t)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<"\n";
}
void Stack::push(int val)
{
    Node *t = new Node;
    if(t==NULL)
        return;
    else
    {
        t->data = val;
        t->next=st;
        st=t;
    }
}
void Stack::pop()
{
    if(st==NULL)
        return;
    else
    {
        Node *t = st;
        st=st->next;
        delete t;
    }
}

int Stack::stackTop()
{
    if(st)
        return st->data;
    else
        return -1;
}
int Stack::isEmpty()
{
    if(st)
        return 1;
    else
        return 0;
}
int Stack::isFull()
{
    Node *t = new Node;
    if(t)
        return 1;
    else
        return 0;
}
int Stack::peek(int pos)
{
    Node *t = st;
    for(int i = 0; i<pos-1 && t; i++)
    {
        t=t->next;
    }
    if(t)
        return t->data;
    else
        return -1;
}

int main()
{
    Stack stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.Display();
    stk.pop();
    stk.Display();
    return 0;
}