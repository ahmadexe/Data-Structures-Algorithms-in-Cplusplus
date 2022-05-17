#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertMain(Node** first,Node** last,int val)
{
    Node* p = new Node(val);
    if (!(*first) && !(*last))
    {
        (*first) = p;
        (*last) = p;
    }
    else
    {
        (*last)->next = p;
        (*last) = p;
    }
}

void insertSorted(Node** first,Node** last, Node** p)
{
    Node * q = new Node((*p)->data);
    q->next = NULL;
    if (!(*last) && !(*first))
    {
        *last = q;
        *first = q;
        (*last)->next = NULL;
        (*first)->next = NULL;
    }
    else
    {
        (*last)->next = q;
        *last = q;  
        (*last)->next = NULL; 
    }
}



void segregate(Node** eHead,Node** eTail, Node** oHead, Node** oTail,Node** first)
{
    Node* p = NULL;
    Node* q = (*first);

    while (q)
    {
        if (q->data % 2 == 0)
        {
            insertSorted(eHead, eTail, &q);
            // insertMain(eHead, eTail, q->data);
        }
        else if (q->data % 2 == 1)
        {
            insertSorted(oHead, oTail, &q);
            // insertMain(oHead, oTail, q->data);
        }
    } 
}

void display(Node* first)
{
    Node* p = first;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{

    Node* head = NULL;
    Node* tail = NULL;
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;    

    insertMain(&head, &tail, 1);
    insertMain(&head, &tail, 2);
    insertMain(&head, &tail, 3);
    insertMain(&head, &tail, 4);
    insertMain(&head, &tail, 5);
    insertMain(&head, &tail, 6);
    display(head);
    segregate(&evenHead, &evenTail, &oddHead, &oddTail, &head);
    display(oddHead);
    display(evenHead);

    return 0;
}