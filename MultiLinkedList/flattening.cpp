#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* next;
    Node* below;
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
    while (p->data != key && p != NULL)
    {
        p = p->next;
    
    }
    
    Node* d = new Node(data);
    if (!p->below)
    {
        p->below = d;
    }
    else
    {
        d->below = p->below;
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
                p->below = p->below->below;
            }
            cout<<endl;
        }
        p = p->next;
    }
}

Node* flat(Node* head)
{
    if (!head->next)
    {
        return head;
    }
    else
    {
        while (head)
        {
            if (head->below)
            {
                Node* temp = flat(head->below);
                temp->next = head->next;
                head->next = temp;
            }
            head = head->next;
        }
    }
    return head;
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
    insertBelow(head, 20, 100);
    insertBelow(head, 20, 200);
    insertBelow(head, 20, 300);
    insertBelow(head, 20, 400);
    insertBelow(head, 20, 500);
    Node* p = head;
    flat(p);
    display(head);

    // displayLayer(head);

    return 0;
}