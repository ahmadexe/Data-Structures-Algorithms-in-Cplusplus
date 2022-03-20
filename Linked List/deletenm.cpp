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

void deletenm(int m, int n){
    int countAlpha = 1;
    int countBeta = 0;
    Node* p = head;
    while (p && countAlpha < m){
        p = p->next;
        countAlpha++;
    }
    while (p->next && countBeta < n){
        Node* temp = p->next;
        p->next = p->next->next;
        countBeta++;
        free(temp);
    }
}

int main(int argc, char const *argv[])
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    // insert(80);
    // insert(90);
    // insert(100);

    deletenm(3, 2);
    display();
    return 0;
}