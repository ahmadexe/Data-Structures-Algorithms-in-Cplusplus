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



void traversalReccursive(struct NodeStudent* myHead){
    if (!myHead){
        return;
    }
    traversalReccursive(myHead->next);
    cout<<myHead->id<<" ";
}



int main(int argc, char const *argv[])
{

    insertAtEnd(10);
    insertAtEnd(20);   
    insertAtEnd(30);   
    insertAtEnd(40);   
    struct NodeStudent* p = head;
    traversalReccursive(p);


    return 0;
}