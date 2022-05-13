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
        left = NULL;
        right = NULL;
    }
};

void insert(Node* root,int val)
{
    if (!root->left || !root->right)
    {
        Node* p = new Node(val);
        if (p->data < root->data && !root->left)
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

void leafs(Node* root)
{
    if (!root)
    {
        return;
    }
    else if (!root->left && !root->right)
    {
        cout<<root->data<<" ";
    }
    else
    {
        leafs(root->left);
        leafs(root->right);
    }
}

int main(int argc, char const *argv[])
{

    Node* r = new Node(40);
    insert(r, 30);
    insert(r, 10);
    insert(r, 15);
    insert(r, 50);
    insert(r, 60);

    Node* p = r;
    leafs(p);


    return 0;
}