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

void display()
{
    Node *p = head;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void seg()
{
    Node* p = head;
    Node* q = tail;
    int flag = 0;
    do
    {
        if (p == head && (p->data % 2 == 1))
        {
            q->next = p;
            head = p->next;
            q = p;
            p = p->next;
            q->next = NULL;
        }
        else if (p->next->data % 2 ==1 && (p->next != tail))
        {
            Node* t = p->next;
            p->next = p->next->next;
            q->next = t;
            q = q->next;
            q->next = NULL;
            p = p->next;
        }
        else
        {
            p = p->next;
            flag = 1;
        }
    } while (p != tail);
    if (!flag)
    {
        q->next = p;
        q = q->next;
        head = p->next;
        q->next = NULL;
        tail = q;
    }
}

int main(int argc, char const *argv[])
{

    insert(1);   
    insert(2);   
    insert(2);   
    insert(2);   
     
    display();
    seg();
    cout<<endl;
    display();

    return 0;
}