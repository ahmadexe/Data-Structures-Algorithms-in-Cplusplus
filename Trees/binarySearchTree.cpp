#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *right;
    Node *left;
};

Node *root = NULL;

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
        while (p->left != NULL || p->right != NULL)
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
        if (data > p->data)
        {
            p->right = cur;
        }
        else{
            p->left = cur;
        }
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}