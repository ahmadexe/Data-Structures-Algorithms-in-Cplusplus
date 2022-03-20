#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct NodeStudent
{
    int id;
    int marks;
    struct NodeStudent *next;
};
struct NodeStudent *head = NULL;
struct NodeStudent *tail = NULL;

int isEmpty()
{
    if (!head && !tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insertAtEnd(int marks, int id)
{
    if (head == NULL && tail == NULL)
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->marks = marks;
        current->next = NULL;
        head = current;
        tail = current;
    }
    else if (head == tail)
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->marks = marks;
        current->next = NULL;
        head->next = current;
        tail = current;
    }
    else
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->marks = marks;
        current->next = NULL;
        tail->next = current;
        tail = current;
    }
}

void printList()
{
    if (isEmpty())
    {
        cout << "Empty list" << endl;
    }
    else
    {
        struct NodeStudent *p = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        p = head;
        while (p != NULL)
        {
            cout << "ID: " << p->id << " Marks: " << p->marks << endl;
            p = p->next;
        }
    }
}

void reverseIterative()
{
    struct NodeStudent *p = NULL;
    struct NodeStudent *c = head;
    struct NodeStudent *n;
    // p = NULL;
    // n = NULL;
    while (c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    tail = head;
    head = p;
}

int main(int argc, char const *argv[])
{

    insertAtEnd(10, 1);
    insertAtEnd(20, 2);
    insertAtEnd(30, 3);
    insertAtEnd(40, 4);
    insertAtEnd(50, 5);
    reverseIterative();
    cout << tail->id << endl;
    printList();
    return 0;
}