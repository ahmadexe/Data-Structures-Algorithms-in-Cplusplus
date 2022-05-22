#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
    }
};

void inOrder(Node* root)
{
    if (!root)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        cout<<root->data;
        inOrder(root->right);
    }
}

Node* rightRotation(Node* root)
{
    if (!root->left)
    {
        return root;
    }
    else
    {
        Node* x = root->left;
        Node* temp = x->right;
        x->right = root;
        root->left = temp;
    }
}

Node* leftRotation(Node* root)
{
    if (!root->right)
    {
        return root;
    }
    else
    {
        Node* x = root->right;
        Node* temp = x->left;
        x->left = root;
        root->right = temp;
    }
}

int main(int argc, char const *argv[])
{

    


    return 0;
}