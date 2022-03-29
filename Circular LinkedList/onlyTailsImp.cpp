#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* tail = NULL;
Node* tail2 = NULL;

void insert(int val)
{
    Node* n = new Node();
    n->data = val;
    n->next = NULL;

    if (!tail)
    {
        n->next = n;
        tail = n;
    }
    else{
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }
}

void insert2(int val)
{
    Node* n = new Node();
    n->data = val;
    n->next = NULL;

    if (!tail2)
    {
        n->next = n;
        tail2 = n;
    }
    else{
        n->next = tail2->next;
        tail2->next = n;
        tail2 = n;
    }
}

void display(Node* x)
{
    Node* p = new Node();
    p = x->next;
    do
    {
        cout<<p->data<<' ';
        p = p->next;
    } while (p != x->next);
}

void sort(Node* x)
{
    Node* p = x->next;
    Node* q = new Node();
    do{
        q = p->next;
        while(q != x->next)
        {
            if (q->data > p->data)
            {
                int temp = q->data;
                q->data = p->data;
                p->data = temp;
            }
            q = q->next;
            //cout<<"a";
        }
        p = p->next;
        //cout<<"s";
        // cout<<p->data<<endl;
        // cout<<x->next->data<<endl;
    }while (p != x->next);
}

Node* merge(){

    sort(tail2);
    sort(tail);
    Node* p = new Node();
    Node* q = new Node();
    Node* c = new Node();
    Node* d = new Node();
    p = tail->next;
    q = tail2->next;
    while (q != tail2)
    {
        c = p->next;
        p->next = q;
        d = q->next;
        q->next = c;
        p = c;
        q = d;
    }
    q->next = p->next;
    p->next = q;
    return q;
}

int main(int argc, char const *argv[])
{

    insert(12);
    insert(28);
    insert(18);
    insert(25);
    insert(19);

    insert2(5);
    insert2(24);
    insert2(12);
    insert2(6);
    insert2(15);

    Node* z = merge();
    display(z);



    return 0;
}