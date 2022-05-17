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
    else if ((*first)->data == (*last)->data)
    {
        *last = q;
        (*last)->next = NULL;
        (*first)->next = *last;
    }
    else
    {
        (*last)->next = q;
        *last = q;  
        (*last)->next = NULL; 
        cout<<endl;
    }

    // (*p)->next = NULL;
    // if (!(*first) && !(*last))
    // {
    //     *first = *p;
    //     *last = *p;
    // }
    // else
    // {   cout<<"HERE ";
    //     cout<<(*last)->data<<" ";
    //     if ((*p)->data < (*first)->data)
    //     {
    //         cout<<endl;
    //         cout<<"Enter 1"<<endl;
    //         (*p)->next = (*first);
    //         (*first) = *p;
    //     }
    //     else if ((*p)->data > (*last)->data)
    //     {
    //         cout<<endl<<"Enter 2"<<endl;

    //         (*last)->next = *p;
    //         (*last) = *p;
    //     }
    //     else
    //     {
    //         cout<<endl<<"Enter 3"<<endl;
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
    //     cout<<(*last)->data<<" ";
    //     cout<<endl;
    // }
    // if (!(*first) && !(*last))
    // {
    //     (*first) = p;
    //     (*last) = p;
    //     cout<<"First "<<(*first)->data<<endl;
    //     cout<<"Last "<<(*last)->data<<endl;
    // }
    // else
    // {
    //     cout<<(*last)->data<<endl;
    //     (*last)->next = p;
    //     (*last) = p;
    //     cout<<(*last)->data<<endl;
    // }
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