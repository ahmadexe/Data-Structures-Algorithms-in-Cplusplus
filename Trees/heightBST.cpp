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

void insert(Node* root, int key) {
    if (!root->right || !root->left) {
        if (key < root->data && !root->left) {
            Node *x = new Node;
            x->data = key;
            x->left = NULL;
            x->right = NULL;
            root->left = x;
            return;
        }
        if (key > root->data && !root->right) {
            Node* x = new Node;
            x->data = key;
            x->left = NULL;
            x->right = NULL;
            root->right = x;
            return;
        }
    }
    if (root->data == key)
    {
        cout<<"Duplicate found"<<endl;
        return;
    }
    if (key < root->data) {
        insert(root->left, key);
    }
    if (key > root->data) {
        insert(root->right, key);
    }
}

int height(Node* r)
{
    if (!r)
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    Node * root = new Node;
    root->data = 50;
    root->left = NULL;
    root->right = NULL;

    insert(root,30);
    insert(root,20);
    insert(root,70);
    insert(root,40);
    insert(root,60);    
    
    inOrder(root);

    return 0;
}