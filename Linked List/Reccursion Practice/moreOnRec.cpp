#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
    }
};

Node* head = NULL;
Node* tail = NULL;
Node* head2 = NULL;
Node* tail2 = NULL;

void insert1(int val)
{
    Node* p = new Node(val);
    if (!head && !tail)
    {
        p->next = NULL;
        head = p;
        tail = p;
    }
    else
    {
        tail->next = p;
        p->next = NULL;
        tail = p;
    }
}

void insert2(int val)
{
    Node* p = new Node(val);
    if (!head2 && !tail2)
    {
        p->next = NULL;
        head2 = p;
        tail2 = p;
    }
    else
    {
        tail2->next = p;
        p->next = NULL;
        tail2 = p;
    }
}

void print1(Node* h)
{
    Node* p = h;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

Node* reverse(Node* p)
{
    if (!p->next || !p)
    {
        return p;
    }
    else
    {
        Node* newHead = reverse(p->next);
        p->next->next = p;
        p->next = NULL;
        return newHead;
    }
}

int main(int argc, char const *argv[])
{
    insert1(10);
    insert1(20);
    insert1(30);
    insert1(40);
    insert1(50);
    insert2(60);
    insert2(70);
    insert2(80);
    insert2(90);
    insert2(100);

    head = reverse(head);
    print1(head);
    

    return 0;
}