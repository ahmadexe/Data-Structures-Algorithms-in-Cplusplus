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

void displayIt(NodeStudent* p)
{
    if (!p->next || !p)
    {
        return;
    }
    int temp = p->id;
    displayIt(p->next);
    cout << temp << " " << p->id <<" ";
}

int main(int argc, char const *argv[])
{
    insertAtEnd(10,1);
    insertAtEnd(10,2);
    insertAtEnd(10,3);
    insertAtEnd(10,4);
    insertAtEnd(10,5);
    insertAtEnd(10,6);
    cout << "Here" << endl;
    NodeStudent* p = head;
    displayIt(p);
    cout << "Here" << endl;

    return 0;
}