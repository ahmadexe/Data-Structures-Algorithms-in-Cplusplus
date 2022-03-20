#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* tail = NULL;
void insert(int userData){
    if (!head) {
        struct Node* p = (struct Node*)malloc(sizeof(struct Node*));
        p->data = userData;
        p->next = NULL;
        head = p;
        //head->next = NULL;
    }
    else if (!head->next){
        struct Node* p = (struct Node*)malloc(sizeof(struct Node*));
        p->data = userData;
        p->next = NULL;
        tail = p;
        head->next = tail;
    }
    else {
        struct Node* p = (struct Node*)malloc(sizeof(struct Node*));
        p->data = userData;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
}

void display(){
    struct Node* p = head;
    while (p) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

Node* reverseInK(struct Node* headM, int k){
    int count = 0;
    Node* prev = NULL;
    Node* curr = headM;
    Node* next = NULL;

    while (curr && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next){
        headM->next = reverseInK(next, k);
    }
    return prev;
}

int main(int argc, char const *argv[])
{

    
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    //display();
    Node* a = head;
    head = reverseInK(a, 2);
    display();
    return 0;
}