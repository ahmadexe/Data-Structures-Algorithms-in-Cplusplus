#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};


void inOrder(Node* root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}



int main(int argc, char const *argv[])
{

    


    return 0;
}