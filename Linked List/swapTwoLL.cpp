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

Node *head2 = NULL;
Node *tail2 = NULL;
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

void insert2(int val)
{
    if (head2 == NULL && tail2 == NULL)
    {
        Node *c = new Node();
        c->data = val;
        c->next = NULL;
        head2 = c;
        tail2 = c;
    }
    else if (head2 == tail2)
    {
        Node *c = new Node();
        c->data = val;
        c->next = NULL;
        tail2->next = c;
        tail2 = c;
    }
    else
    {
        Node *c = new Node();
        c->data = val;
        c->next = NULL;
        tail2->next = c;
        tail2 = c;
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

void display2()
{
    Node *p = head2;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void swap2(int firstVal, int secondVal)
{
    Node *q1 = NULL;
    Node *p1 = head;
    Node *q2 = NULL;
    Node *p2 = head2;

    while ((p1 && p2) && (p1->data != firstVal || p2->data != secondVal))
    {
        if (p1->data != firstVal)
        {
            q1 = p1;
            p1 = p1->next;
        }
        if (p2->data != secondVal)
        {
            q2 = p2;
            p2 = p2->next;
        }
    }

    if (!p1 || !p2)
    {
        cout << "None";
        return;
    }

    // q1 and q2 null

    if (!q1 && !q2)
    {
        Node *temp = p1->next;
        p1->next = p2->next;
        p2->next = temp;
    }

    // q1 is null

    else if (!q1)
    {
        Node *temp = p1->next;
        p1->next = p2->next;
        p2->next = temp;
        q2->next = p1;
    }

    // q2 is null

    else if (!q2)
    {
        Node *temp = p1->next;
        p1->next = p2->next;
        p2->next = temp;
        q1->next = p2;
    }

    else
    {
        Node *temp1 = p1->next;
        q1->next = p2;
        q2->next = p1;
        p1->next = p2->next;
        p2->next = temp1;
    }
}

int main(int argc, char const *argv[])
{

    insert(1);
    insert(2);
    insert(3);
    insert(4);

    insert2(5);
    insert2(6);
    insert2(7);
    insert2(8);

    display();
    cout << endl;
    display2();
    cout << endl;
    swap2(1, 7);
    cout << endl;
    display();
    cout << endl;
    display2();

    return 0;
}