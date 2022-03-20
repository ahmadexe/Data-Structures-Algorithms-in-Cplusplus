#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    char a;
    double c;
    char b;
};


int main(int argc, char const *argv[])
{
    //Node x = new Node();
    Node* b = (Node*)malloc(sizeof(Node*));
    cout<<sizeof(double)<<endl;
    //s = (Node*)malloc(sizeof(Node*));
    //cout<<&s->a<<endl;
    //cout<<&s->b<<endl;
    //cout<<&s->c<<endl;
    //b->data = 90;
    // b->prev = NULL;
    //b->next = NULL;
    Node* a = (Node*)malloc(sizeof(Node*));
    //a->data = 100;
    //a->next = NULL;
    //a->prev = b;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(Node);
    return 0;
}