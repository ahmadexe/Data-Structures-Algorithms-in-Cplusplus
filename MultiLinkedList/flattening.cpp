#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct down
{
    int data;
    down* next;
    down(int val)
    {
        data = val;
        next = NULL;
    }
};

struct Node{
    int data;
    Node* next;
    down* below;
    Node(int val)
    {
        data = val;
        next = NULL;
        below = NULL;
    }
};

void insertParallel(Node** head,Node** tail,int data)
{
    Node * p = new Node(data);
    if (!(*head) && !(*tail))
    {
        *head = p;
        *tail = p;
    }
    else
    {
        (*tail)->next = p;
        (*tail) = p;
    }
}



void insertBelow(Node* head,int key, int data)
{
    Node* p = head;
    while (p->data != key)
    {
        p = p->next;
    }
    down* d = new down(data);
    if (!p->below)
    {
        p->below = d;
    }
    else
    {
        d->next = p->below;
        p->below = d;
    }
}

void display(Node* head)
{
    Node* p = head;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void displayLayer(Node* head)
{
    Node* p = head;
    while (p)
    {
        if (p->below)
        {
            while (p->below)
            {
                cout<<p->below->data<<" ";
                p->below = p->below->next;
            }
            cout<<endl;
        }
        p = p->next;
    }
}

int main(int argc, char const *argv[])
{

    Node* head = NULL;
    Node* tail = NULL;
    insertParallel(&head, &tail, 10);
    insertParallel(&head, &tail, 20);
    insertParallel(&head, &tail, 30);
    insertParallel(&head, &tail, 40);
    insertParallel(&head, &tail, 50);
    display(head);
    insertBelow(head, 20, 1);
    insertBelow(head, 20, 2);
    insertBelow(head, 20, 3);
    insertBelow(head, 20, 4);
    insertBelow(head, 20, 5);
    displayLayer(head);

    return 0;
}