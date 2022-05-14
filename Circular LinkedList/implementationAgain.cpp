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

Node* tail = NULL;

void insert(int val)
{
    Node* p = new Node(val);
    if (!tail)
    {
        p->next = p;
        tail = p;   
    }
    else
    {
        Node* q = tail->next;
        tail->next = p;
        p->next = q;
        tail = p;
    }
}

void print()
{
    Node* p = tail->next;
    if (p)
    {
        do
        {
            cout<<p->data<<" ";
            p = p->next;
        } while (p != tail->next);
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
     
    print();

    return 0;
}