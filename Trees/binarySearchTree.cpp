#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};

Node* root = NULL;

void insert(int data)
{
    Node *cur = new Node;
    cur->data = data;
    cur->left = NULL;
    cur->right = NULL;
    if (!root)
    {
        root = cur;
    }
    else
    {
        Node *p = new Node;
        p = root;
        while (p)
        {
            if (p->data < data)
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }
        p = cur;
    }
}

void inOrder(Node* x)
{
    if (!x)
    {
        return;
    }
    inOrder(x->left);
    cout<<x->data<<" ";
    inOrder(x->right);
}

int main(int argc, char const *argv[])
{
    insert(30);
    insert(20);
    insert(50);
    Node* z = root;
    inOrder(z);
    return 0;
}