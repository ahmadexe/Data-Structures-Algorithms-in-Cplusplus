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


    return 0;
}