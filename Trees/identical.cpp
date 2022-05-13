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

void insert(Node* root, int val)
{
    if (!root->left || !root->right)
    {
        Node* p = new Node(val);
        if (p->data < root->data && !root->left)
        {
            root->left = p;
        }
        else
        {
            root->right = p;
        }
    }
    else
    {
        if (val < root->data)
        {
            insert(root->left, val);
        }
        else
        {
            insert(root->right,val);
        }
    }
}

int main(int argc, char const *argv[])
{

    


    return 0;
}