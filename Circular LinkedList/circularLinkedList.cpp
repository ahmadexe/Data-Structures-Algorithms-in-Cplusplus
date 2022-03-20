#include <iostream>
#include <bits/stdc++.h>
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
    if (!head && !tail)
    {
        Node *n = new Node();
        n->data = val;
        n->next = n;
        head = n;
        tail = n;
    }
    else
    {
        Node *n = new Node();
        n->data = val;
        n->next = head;
        tail->next = n;
        tail = n;
    }
}

void display()
{
    Node *p = head;
    if (p->next == head)
    {

        cout << p->data << endl;
    }
    else
    {
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    display();

    return 0;
}