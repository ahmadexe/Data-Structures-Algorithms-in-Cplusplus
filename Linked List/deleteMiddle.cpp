#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int id;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;


void display(){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node*));
    p = head;
    while (p) {
        cout<<p->id<<" ";
        p = p->next;
    }
    cout<<endl;
}

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

void deleteMiddle(){
    struct Node* prev = head;
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
}

int main(int argc, char const *argv[])
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    deleteMiddle();
    display();
    return 0;
}