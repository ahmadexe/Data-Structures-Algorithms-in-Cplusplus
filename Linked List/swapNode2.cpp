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


int main(int argc, char const *argv[])
{

    


    return 0;
}