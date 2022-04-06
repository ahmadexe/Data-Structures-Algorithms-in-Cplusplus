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

vector<int> v;
void traversalInReverse()
{
    NodeStudent* p = head;
    while (p)
    {
        v.push_back(p->id);
        p = p->next;
    }
    int i = v.size() - 1;
    while (i >= 0)
    {
        cout<<v[i]<<" ";
        i--;
    }
    cout<<endl;
}

void display()
{
    NodeStudent* p = head;
    while (p)
    {
        cout<<p->id<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{

    insertAtEnd(10);
    insertAtEnd(20);   
    insertAtEnd(30);   
    insertAtEnd(40);   
    traversalInReverse();
    display();
    return 0;
}