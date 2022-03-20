#include<iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

struct Node{
    Node* prev;
    int data;
    Node* next;
    int z;
    Node* veryNext;
};

struct Control{
    int a;
    int b;
    int c;
};

int main(int argc, char const *argv[])
{

    Control* c = (Control*) malloc(17);
    Node* n = (Node*)malloc(4);
    // n->prev = NULL;
    // n->next = NULL;
    n->data = 100;
    cout<<n->prev<<endl;
    cout<<n->next<<endl;
    //cout<<n->veryNext<<endl;
    cout<<n->data<<endl;
    c->a = 9;
    c->b = 8;
    c->c = 7;
    cout<<c->a<<c->b<<c->c<<endl;
    cout<<sizeof(Control)<<" "<<sizeof(Node);


    return 0;
}