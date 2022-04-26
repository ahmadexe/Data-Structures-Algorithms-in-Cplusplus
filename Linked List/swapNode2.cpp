#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct Node{
    int id;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

void insert(int uid){
    if (!head && !tail){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
        newNode->id = uid;
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }
    else if (head == tail) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
        newNode->id = uid;
        newNode->next = NULL;
        tail = newNode;
        head->next = tail;
    }
    else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
        newNode->id = uid;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

void display()
{
    struct Node*p = head;
    while (p)
    {
        cout << p->id << " ";
        p = p->next;
    }
    cout << endl;
}

void swapNodes(int a, int b)
{
    if (!a || !b)
    {
        return;
    }
    Node* p = new Node;
    p = head;
    Node* pPrev = NULL;
    Node* q = new Node;
    q = head;
    Node* qPrev = NULL;

    while ((p->id != a || q->id != b) && (p && q))
    {
        if (p->id != a)
        {
            pPrev = p;
            p = p->next;
        }
        if (q->id != b)
        {
            qPrev = q;
            q = q->next;
        }
    }

    pPrev->next = q;
    qPrev->next = p;

    Node * temp = q->next;
    q->next = p->next;
    p->next = temp;
}

int main(int argc, char const *argv[])
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    display();
    cout<<endl;
    swapNodes(30, 40);
    display();


    return 0;
}