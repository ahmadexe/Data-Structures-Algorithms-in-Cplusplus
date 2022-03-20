#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertAtEnd(int val){
    if (!head && !tail)
    {
        Node* current = new Node();
        current->data = val;
        current->next = NULL;
        head = current;
        tail = current;
    }
    else if (head == tail)
    {
        Node* current = new Node();
        current->data = val;
        current->next = NULL;
        head->next = current;
        tail = current;
    }
    else
    {
        Node* current = new Node();
        current->data = val;
        current->next = NULL;
        tail->next = current;
        tail = current;
    }
}

void display()
{
    Node* p = head;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void sort(){
    Node* p = head;
    
    while (p)
    {
        Node* q = p->next;
        while (q)
        {
            if (q->data < p->data)
            {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

int main(int argc, char const *argv[])
{

    insertAtEnd(50);
    insertAtEnd(20);
    insertAtEnd(10);
    insertAtEnd(30);
    insertAtEnd(40);
    sort();
    display();



    return 0;
}