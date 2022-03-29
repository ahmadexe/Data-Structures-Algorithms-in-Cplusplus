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

struct Node* getMid(){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* q = (struct Node*)malloc(sizeof(struct Node*));
    p = head;
    q = head;
    while (q && q->next){
        p = p->next;
        q = q->next->next;
    }
    return p;
}

void display(){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node*));
    p = head;
    while (p) {
        cout<<p->id<<" ";
        p = p->next;
    }
    cout<<endl;
}

struct Node* reverseLL(struct Node* start){
    if (!start || !start->next){
        return start;
    }
    else {
        struct Node* reversedHead = reverseLL(start->next);
        start->next->next = start;
        start->next = NULL;
        return reversedHead;
    }
}

void printLL(){
    struct Node* mid = getMid();
    struct Node* midHead = reverseLL(mid);
    struct Node* p = head;
    struct Node* q = midHead;
    while (q){
        if (p->id == q->id){
            cout<<q->id<<" ";
            p = p->next;
            q = q->next;
        }
        else{
        cout<<p->id<<" "<<q->id<<" ";
        p = p->next;
        q = q->next;
        }
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    //insert(60);
    printLL();
    //display();
    return 0;
}