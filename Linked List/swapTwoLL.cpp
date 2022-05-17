#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

Node *head2 = NULL;
Node *tail2 = NULL;
void insert(int val)
{
    if (head == NULL && tail == NULL)
    {
        Node *c = new Node();
        c->data = val;
        c->next = NULL;
        head = c;
        tail = c;
    }
    else if (head == tail)
    {
        Node *c = new Node();
        c->data = val;
        c->next = NULL;
        tail->next = c;
        tail = c;
    }
    else
    {
        Node *c = new Node();
        c->data = val;
        c->next = NULL;
        tail->next = c;
        tail = c;
    }
}

void insert2(int val)
{
    if (head2 == NULL && tail2 == NULL)
    {
        Node *c = new Node();
        c->data = val;
        c->next = NULL;
        head2 = c;
        tail2 = c;
    }
    else if (head2 == tail2)
    {
        Node *c = new Node();
        c->data = val;
        c->next = NULL;
        tail2->next = c;
        tail2 = c;
    }
    else
    {
        Node *c = new Node();
        c->data = val;
        c->next = NULL;
        tail2->next = c;
        tail2 = c;
    }
}

void display()
{
    Node *p = head;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void display2()
{
    Node *p = head2;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}


int main(int argc, char const *argv[])
{

    


    return 0;
}