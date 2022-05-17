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
    // (*p)->next = NULL;
    // if (!(*first) && !(*last))
    // {
    //     *first = *p;
    //     *last = *p;
    // }
    // else
    // {
    //     if ((*p)->data < (*first)->data)
    //     {
    //         (*p)->next = (*first);
    //         (*first) = *p;
    //     }
    //     else if ((*p)->data > (*last)->data)
    //     {
    //         (*last)->next = *p;
    //         (*last) = *p;
    //     }
    //     else
    //     {
    //         Node* prev = (*first);
    //         Node* curr = (*first)->next;
    //         while (curr->data)
    //         {
    //             if (prev->data < (*p)->data && curr->data > (*p)->data)
    //             {
    //                 break;
    //             }
    //             prev = prev->next;
    //             curr = curr->next;
    //         }
    //         prev->next = *p;
    //         (*p)->next = curr;
    //     }
    // }
    if (!(*first) && !(*last))
    {
        cout<<"Here 1"<<endl;
        (*first) = *p;
        (*last) = *p;
    }
    else
    {
        cout<<"Here 2"<<endl;
        (*last)->next = *p;
        (*last) = *p;
    }
}



void segregate(Node** eHead,Node** eTail, Node** oHead, Node** oTail,Node** first)
{
    Node* p = (*first);
    Node* q = NULL;

    while (p)
    {
        q = p;
        p = p->next;
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
        free(q);
        q = NULL;
    }
    if (q)
    {
        if (q->data % 2 == 0)
        {
            // insertMain(eHead, eTail, q->data);
            insertSorted(eHead, eTail, &q);
        }
        else if (q->data % 2 == 1)
        {
            // insertMain(oHead, oTail, q->data);
            insertSorted(oHead, oTail, &q);
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
    // display(oddHead);
    // display(evenHead);





    return 0;
}