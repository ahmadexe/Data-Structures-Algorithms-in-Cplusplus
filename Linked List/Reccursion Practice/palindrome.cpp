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

struct NodeStudent *reverseLL(struct NodeStudent *firstx)
{
    if (!firstx->next || !firstx)
    {
        return firstx;
    }
    NodeStudent *myHead = reverseLL(firstx->next);
    firstx->next->next = firstx;
    firstx->next = NULL;
    return myHead;
}

struct NodeStudent *findMid()
{
    struct NodeStudent *p = head;
    struct NodeStudent *q = head;
    if (head)
    {
        while (q && q->next)
        {
            q = q->next->next;
            p = p->next;
        }
    }
    return p;
}

int palindrome(struct NodeStudent *revHead)
{
    NodeStudent *p = head;
    NodeStudent *q = revHead;
    int check = 0;
    while (q->next)
    {
        if (p->id != q->id)
        {
            check++;
            break;
        }
        p = p->next;
        q = q->next;
    }
    if (!check)
    {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{

    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(30);
    insertAtEnd(20);
    insertAtEnd(10);
    NodeStudent *mid = findMid();
    // cout<<mid->id;
    NodeStudent *revHead = reverseLL(mid);
    cout<<palindrome(revHead);

    return 0;
}