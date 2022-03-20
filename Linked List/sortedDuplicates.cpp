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

void sort()
{
    Node *p = head;
    while (p != NULL)
    {
        Node *q = p->next;
        while (q != NULL)
        {
            if (q->data < p->data)
            {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void removeDuplicates(){
    if (head)
    {
        Node* p = head;
        Node* q = p->next;
        while (q)
        {
            if (p->data == q->data)
            {
                p->next = q->next;
            }
            else
            {
                p = q;
            }
            q = q->next;
        }
    }

}

int main(int argc, char const *argv[])
{

    insert(10);
    insert(30);
    insert(20);
    insert(10);
    insert(10);
    insert(30);
    insert(30);
    insert(20);
    insert(20);
    insert(20);

    sort();

    removeDuplicates();
    display();


    return 0;
}