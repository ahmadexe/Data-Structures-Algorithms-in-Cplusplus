#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    char data;
    Node* right;
    Node* left;
};

void postOrder(Node* root)
{
    if (!root)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

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

    postOrder(root);   

    return 0;
}