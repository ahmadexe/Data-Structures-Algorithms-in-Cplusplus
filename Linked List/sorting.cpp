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

// void insertAtIndex(int index, int val)
// {
//     int count = 0;
//     Node *p = head;

//     if (index == 0)
//     {
//         Node *q = new Node();
//         q->data = val;
//         q->next = head;
//         head = q;
//     }
//     else
//     {
//         while (count < index - 1 && p != NULL)
//         {
//             p = p->next;
//             count++;
//         }
//         if (p != NULL)
//         {
//             Node *q = new Node();
//             q->data = val;
//             q->next = p->next;
//             p->next = q;
//         }
//     }
// }

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

void removeDuplicates()
{
    Node *c = head;

    while (c->next != NULL)
    {
        Node *p = c;
        Node *q = p->next;
        while (q != NULL)
        {
            if (c->data == q->data)
            {
                p->next = q->next;
                insert2(c->data);
            }

            else
            {
                p = q;
            }
            q = q->next;
        }
        c = c->next;
    }
}

int main(int argc, char const *argv[])
{
    insert(50);
    insert(10);
    insert(10);
    insert(10);
    // insert(10);
    insert(40);
    insert(40);
    insert(30);
    insert(20);
    removeDuplicates();
    display();
    cout << endl;
    display2();
    return 0;
}