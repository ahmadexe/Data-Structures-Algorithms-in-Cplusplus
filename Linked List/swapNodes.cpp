#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct NodeStudent
{
    int id;
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

void insertAtEnd(int id)
{
    if (head == NULL && tail == NULL)
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        // current->marks = marks;
        current->next = NULL;
        head = current;
        tail = current;
    }
    else if (head == tail)
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        // current->marks = marks;
        current->next = NULL;
        head->next = current;
        tail = current;
    }
    else
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        // current->marks = marks;
        current->next = NULL;
        tail->next = current;
        tail = current;
    }
}

void display()
{
    struct NodeStudent *p = head;
    while (p)
    {
        cout << p->id << " ";
        p = p->next;
    }
    cout << endl;
}

void swapNodes(int id1, int id2)
{
    NodeStudent *p = head;
    NodeStudent *q = head->next;
    if (id1 == id2)
    {
        cout << "Different id's required to swap" << endl;
    }
    else
    {
        while (p->next || q->next)
        {
            if (p->id != id1)
            {
                p = p->next;
            }
            if (q->id != id2)
            {
                q = q->next;
            }
            if (p->id == id1 && q->id == id2)
            {
                break;
            }
        }
        int temp = p->id;
        p->id = q->id;
        q->id = temp;
    }
}

int main(int argc, char const *argv[])
{
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    swapNodes(1, 1);
    display();
    return 0;
}