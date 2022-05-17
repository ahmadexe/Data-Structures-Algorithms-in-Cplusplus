#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};


void insertMain(Node** first,Node** last,int val)
{
    Node* p = new Node(val);
    if (!(*first) && !(*last))
    {
        (*first) = p;
        (*last) = p;
    }
    else
    {
        (*last)->next = p;
        (*last) = p;
    }
}


int main(int argc, char const *argv[])
{

    


    return 0;
}