#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;
Node* sortedHead = NULL;
void insert(int val)
{
    Node* p = new Node;
    p->data = val;
    p->next = NULL;
    if (!head)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
}

void insertSorted(int val)
{
    Node* p = new Node;
    p->data = val;
    p->next = NULL;
    if (!sortedHead)
    {
        sortedHead = p;
    }
    else
    {
        p->next = sortedHead;
        sortedHead = p;
    }
}

void display()
{
    Node* p = head;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int pop()
{
    if (!head)
    {
        return -1;
    }
    else
    {
        int value = head->data;
        head = head->next;
        return value;
    }
}



int main(int argc, char const *argv[])
{

    insert(10);
    insert(20);
    insert(30);
    insert(40);




    return 0;
}