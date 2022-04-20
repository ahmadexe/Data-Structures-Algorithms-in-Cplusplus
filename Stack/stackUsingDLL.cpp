#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

void insert(char value) 
{
    Node* curr = new Node;
    curr->data = value;
    curr->next = NULL;
    curr->prev = NULL;
    if (!head && !tail) 
    {
        head = curr;
        tail = curr;
    }   
    else
    {
        tail->next = curr;
        tail = curr;
    }
}

void checkPalindrome()
{
    
}

int main(int argc, char const *argv[])
{

    


    return 0;
}