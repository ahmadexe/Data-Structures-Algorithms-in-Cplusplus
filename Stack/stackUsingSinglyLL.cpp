#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    char data;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insert(char val)
{
    Node* c = new Node;
    c->data = val;
    c->next = NULL;
    if (!head && !tail) {
        head = c;
        tail = c;
    }
    else
    {
        tail->next = c;
        tail = c;
    }   
}

int checkPalindrome(string str) {
    
}

int main(int argc, char const *argv[])
{

    


    return 0;
}