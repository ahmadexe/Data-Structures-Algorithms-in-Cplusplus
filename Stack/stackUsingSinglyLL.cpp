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
string s1 = "";
string s2 = "";
void checkPalindrome(Node* p) {

    if (!p) 
    {
        return;
    }
    else
    {
        s1 += p->data;
        checkPalindrome(p->next);
        s2 += p->data;
    }
}



int main(int argc, char const *argv[])
{

    string s = "civic";
    for (int i = 0; i < s.size(); i++)
    {
        insert(s[i]);
    }
    Node* p = head;
    checkPalindrome(p);
    if (s1 == s2) {
        cout<<"palindrome"<<endl;
    }
    else{
        cout<<"NOT";
    }

    return 0;
}