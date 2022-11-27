#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head1 = NULL;
Node* tail1 = NULL;
Node* head2 = NULL;
Node* tail2 = NULL;

void insert1(int val)
{
    Node* p = new Node;
    p->data = val;
    p->next = NULL;

    if (!head1 && !tail1)
    {
        head1 = p;
        tail1 = p;
    }
    else
    {
        tail1->next = p;
        tail1 = p;
    }
}

void insert2(int val)
{
    Node* p = new Node;
    p->data = val;
    p->next = NULL;

    if (!head2 && !tail2)
    {
        head2 = p;
        tail2 = p;
    }
    else
    {
        tail2->next = p;
        tail2 = p;
    }
}

void display(Node* head)
{
    Node* p = head;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
    
}

int flag = 1;
int checkPalindrome(Node* p, Node* q)
{
    if (q == NULL || p == NULL)
    {
        return 0;
    }
    else
    {
        checkPalindrome(p->next, q->next);
        if (p->data != q->data)
        {
            flag = 0;
        }
    }
    return flag;
}

void displayIt(Node* p)
{
    if (!p->next || !p)
    {
        return;
    }
    int temp = p->data;
    displayIt(p->next);
    cout << temp << " " << p->data <<" ";
}

int main(int argc, char const *argv[])
{

    insert1(10);
    insert1(20);
    insert1(30);
    insert1(40);
    Node* p = head1;
    displayIt(p);

    return 0;
}