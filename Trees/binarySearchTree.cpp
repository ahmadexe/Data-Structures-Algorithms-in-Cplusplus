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
Node* x = root;
void inOrder()
{
    if (!x)
    {
        return;
    }
    x = x->left;
    inOrder();
    cout<<x->data<<" ";
    x = x->right;
    inOrder();
}

int main(int argc, char const *argv[])
{
    insert(30);
    insert(20);
    insert(50);
    inOrder();
    return 0;
}