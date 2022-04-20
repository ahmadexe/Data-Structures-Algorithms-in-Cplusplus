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

int checkPalindrome(string str)
{
    for (int i = 0; i < str.size(); i++){
        insert(str[i]);
    }
    Node* rev = tail;
    int i = 0;
    while (rev) {
        if (rev->data != str[i]){
            return 0;
        }
        i++;
        rev = rev->prev;
    }
    return 1;
}

int main(int argc, char const *argv[])
{

    cout<<checkPalindrome("civi");


    return 0;
}