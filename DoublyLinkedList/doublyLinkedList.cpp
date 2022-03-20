#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *prev;
    int id;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertAtEnd(int idToInsert)
{
    if (head == NULL && tail == NULL)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        p->id = idToInsert;
        p->next = NULL;
        p->prev = NULL;
        head = p;
        tail = p;
    }
    else if (head == tail)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        p->id = idToInsert;
        p->next = NULL;
        p->prev = head;
        head->next = p;
        tail = p;
        cout << "\n"<< "Node Check " << sizeof(p) << endl;
    }
    else
    {
        Node *ptr = (Node *)malloc(sizeof(Node));
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        Node *q = (Node *)malloc(sizeof(Node));
        ptr->next = q;
        q->id = idToInsert;
        q->prev = ptr;
        q->next = NULL;
        tail = q;
    }
}

void display()
{
    Node *p = head;
    if (p)
    {
        while (p)
        {
            cout << p->id << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void insertAtStart(int idToInsert)
{
    if (!head && !tail)
    {
        Node *current = (Node *)malloc(sizeof(Node));
        current->id = idToInsert;
        current->next = NULL;
        current->prev = NULL;
        head = current;
        tail = current;
    }
    else if (head == tail)
    {
        Node *current = (Node *)malloc(sizeof(Node));
        current->id = idToInsert;
        current->next = head;
        current->prev = NULL;
        head->prev = current;
        head = current;
    }
    else
    {
        Node *current = (Node *)malloc(sizeof(Node));
        current->id = idToInsert;
        current->next = head;
        current->prev = NULL;
        head->prev = current;
        head = current;
    }
}

void insertBefore(int idBefore, int val)
{
    Node *p = new Node();
    p = head;

    if (head->id == idBefore)
    {
        cout << "Can't insert before head" << endl;
    }
    else
    {
        while (p->id != idBefore && p != NULL)
        {
            p = p->next;
        }
        Node *q = new Node();
        q->id = val;
        p->prev->next = q;
        q->prev = p->prev;
        p->prev = q;
        q->next = p;
    }
}

void insertAfter(int idAfter, int val){
    if (tail->id == idAfter){
        cout<<"Can't insert after tail"<<endl;
    }
}

int main(int argc, char const *argv[])
{
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtStart(60);
    insertAtStart(70);
    insertAtStart(80);
    //insertBefore(80,0);
    insertBefore(70,1);
    insertBefore(50,2);
    insertBefore(20,3);
    display();
    return 0;
}