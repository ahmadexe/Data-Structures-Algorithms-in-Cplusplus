#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int id;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insert(int uid)
{
    if (!head && !tail)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
        newNode->id = uid;
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }
    else if (head == tail)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
        newNode->id = uid;
        newNode->next = NULL;
        tail = newNode;
        head->next = tail;
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node *));
        newNode->id = uid;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

void display()
{
    struct Node *p = head;
    while (p)
    {
        cout << p->id << " ";
        p = p->next;
    }
    cout << endl;
}

void swapNodes(int a, int b)
{
    if (a == b)
    {
        return;
    }
    Node *p = new Node;
    p = head;
    Node *pPrev = NULL;
    Node *q = new Node;
    q = head;
    Node *qPrev = NULL;

    while ((p->id != a || q->id != b) && (p && q))
    {
        if (p->id != a)
        {
            pPrev = p;
            p = p->next;
        }
        if (q->id != b)
        {
            qPrev = q;
            q = q->next;
        }
    }

    if (!p || !q)
    {
        return;
    }
    if (!pPrev)
    {
        if (p->next = q)
        {
            Node *temp = q->next;
            q->next = p;
            p->next = temp;
            head = q;
        }
        else
        {

            Node *temp = q->next;
            q->next = p->next;
            qPrev->next = p;
            p->next = temp;
            head = q;
        }
    }
    else if (!qPrev)
    {
        if (q->next = p)
        {
            Node *temp = p->next;
            p->next = q;
            q->next = temp;
            head = p;
        }
        else
        {
            Node *temp = p->next;
            p->next = q->next;
            pPrev->next = q;
            q->next = temp;
            head = p;
        }
    }
    else
    {
        pPrev->next = q;
        qPrev->next = p;
        Node *temp = q->next;
        q->next = p->next;
        p->next = temp;
    }
}

int main(int argc, char const *argv[])
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    display();
    cout << endl;
    swapNodes(60, 50);
    display();
    return 0;
}