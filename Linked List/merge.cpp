#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};



void insert(Node* first, Node* last, int val)
{
    if (first->data == -1 && first->next == NULL && last->data == -1 && last->next){
        Node* c = new Node();
        c->data = val;
        c->next = NULL;
        first = c;
        last = c;
    }
    else if (first->data == last->data)
    {
        Node* c = new Node();
        c->data = val;
        c->next = NULL;
        last->next = c;
        last = c;
    }
    else
    {
        Node* c = new Node();
        c->data = val;
        c->next = NULL;
        last->next = c;
        last = c;
    }
}

void display(Node* first)
{
    Node* p = first;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    Node *head1 = new Node();
    head1->data = -1;
    head1->next = NULL;
    Node *tail1 = new Node();
    tail1->data = -1;
    tail1->next = NULL;
    insert(head1, tail1, 10);
    insert(head1, tail1, 20);
    insert(head1, tail1, 30);
    insert(head1, tail1, 40);
    insert(head1, tail1, 50);
    display(head1);
    
    return 0;
}