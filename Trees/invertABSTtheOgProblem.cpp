#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insert(Node *root, int val)
{
    if (!root->left || !root->right)
    {
        Node *p = new Node(val);
        if (val < root->data && !root->left)
        {
            root->left = p;
            return;
        }
        else if (p->data > root->data && !root->right)
        {
            root->right = p;
            return;
        }
    }
    if (val > root->data)
    {
        insert(root->right, val);
    }
    else
    {
        insert(root->left, val);
    }
}

void inOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void invertAroot(Node* root)
{
    if (!root->left && !root->right)
    {
        return;
    }
    else if (!root->left || !root->right)
    {
        if (!root->right)
        {
            root->right = root->left;
            root->left = NULL;
        }
        else
        {
            root->left = root->right;
            root->right = NULL;
        }
    }
    else
    {
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void invert(Node* root)
{
    if (!root)
    {
        return;
    }
    else
    {
        invert(root->left);
        invert(root->right);
        invertAroot(root);
    }
}

int main(int argc, char const *argv[])
{

    
    

    return 0;
}