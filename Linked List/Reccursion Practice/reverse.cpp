#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct NodeStudent{
    int id;
    struct NodeStudent* next;
};

struct NodeStudent* head = NULL;
struct NodeStudent* tail = NULL;

void insertAtEnd(int id)
{
    if (head == NULL && tail == NULL)
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->next = NULL;
        head = current;
        tail = current;
    }
    else if (head == tail)
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->next = NULL;
        head->next = current;
        tail = current;
    }
    else
    {
        struct NodeStudent *current = (struct NodeStudent *)malloc(sizeof(struct NodeStudent));
        current->id = id;
        current->next = NULL;
        tail->next = current;
        tail = current;
    }
}



struct NodeStudent* reverseLL(struct NodeStudent* first){
    if (!first->next || !first){
        return first;
    }
    
    NodeStudent* myHead = reverseLL(first->next);
    first->next->next = first;
    first->next = NULL;
    return myHead;
}

void traversalReccursive(struct NodeStudent* myHead){
    if (!myHead){
        return;
    }
    cout<<myHead->id<<" ";
    traversalReccursive(myHead->next);
}


int main(int argc, char const *argv[])
{

    insertAtEnd(10);
    insertAtEnd(20);   
    insertAtEnd(30);   
    insertAtEnd(40);   
    struct NodeStudent* p = head;
    NodeStudent* x = reverseLL(p);
    traversalReccursive(x);

    return 0;
}