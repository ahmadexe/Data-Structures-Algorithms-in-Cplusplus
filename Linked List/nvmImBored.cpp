#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* next;
    Node(int val)
    {
        key = val;
    }
};

void insert(Node** start,Node** end, int val)
{
    Node* p = new Node(val);
    p->next = NULL;

    if (!(*end))
    {
        *start = p;
        *end = p;
    }
    else
    {
    Node* p = new Node(val);
    p->next = NULL;
    (*end)->next = p;
    *end = p;
    }
}

void display(Node* start)
{
    Node* p = start;
    while (p)
    {
        cout<<p->key<<" ";
        p = p->next;
    }
    cout<<endl;
}


int main(int argc, char const *argv[])
{

    Node* head = NULL;
    Node* tail = NULL;
    Node* headEven = NULL;
    Node* oddHead = NULL;
    Node* tailEven = NULL;
    Node* tailOdd = NULL;
    
    // if (!head && !tail)
    // {
    //     Node * p = new Node(10);
    //     head = p;
    //     tail = p;   
    // }
    insert(&head,&tail, 20);

    insert(&head,&tail, 30);

    insert(&head,&tail, 40);

    insert(&head,&tail, 50);

 
    display(head);

    return 0;
}