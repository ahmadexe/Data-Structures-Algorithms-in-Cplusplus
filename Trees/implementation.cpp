#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    char data;
    Node* right;
    Node* left;
};

int main(int argc, char const *argv[])
{

    Node* root = new Node;
    Node* left = new Node;    
    Node* right = new Node;

    root->data = 'A';
    root->left = left;
    root->right = right;

    left->data = 'B';
    left->left = NULL;
    left->right = NULL;

    right->data = 'C';
    right->left = NULL;
    right->right = NULL;


    return 0;
}