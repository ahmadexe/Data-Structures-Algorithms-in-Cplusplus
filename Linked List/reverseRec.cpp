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
struct NodeStudent *node = head;

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
        struct NodeStudent *current = (struct NodeStudent *)malloc(8);
        current->id = id;
        current->marks = marks;
        current->next = NULL;
        head = current;
        tail = current;
    }
    else if (head == tail)
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(8);
        current->id = id;
        current->marks = marks;
        current->next = NULL;
        head->next = current;
        tail = current;
    }
    else
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(8);
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
        struct NodeStudent *p = (struct NodeStudent *)malloc(8);
        p = head;
        while (p != NULL)
        {
            cout << "ID: " << p->id << " Marks: " << p->marks << endl;
            p = p->next;
        }
    }
}

void printInReverse(struct NodeStudent *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        printInReverse(p->next);
        cout << p->id << endl;
    }
}

struct NodeStudent *doReverse(struct NodeStudent *p)
{
    if (p->next == NULL || p == NULL)
    {
        return p;
    }
    else
    {
        struct NodeStudent *newNode = doReverse(p->next);
        p->next->next = p;
        p->next = NULL;
        return newNode;
    }
}

int main(int argc, char const *argv[])
{
    insertAtEnd(10, 1);
    insertAtEnd(20, 2);
    // insertAtEnd(30,3);
    // insertAtEnd(40,4);
    // insertAtEnd(50,5);
    struct NodeStudent *p = head;
    head = doReverse(p);
    // cout<<tail->id;
    printList();
    return 0;
}