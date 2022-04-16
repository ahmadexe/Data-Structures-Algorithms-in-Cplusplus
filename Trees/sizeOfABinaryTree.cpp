#include<iostream>
#include<bits/stdc++.h>
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
        Node* temp = new Node;
        while (p != NULL)
        {
            if (p->data < data)
            {
                temp = p;
                p = p->right;
            }
            else
            {
                temp = p;
                p = p->left;
            }
        }
        p = cur;
        if (p->data > temp->data){
            temp->right = p;
        }
        else {
            temp->left = p;
        }
    }
}
int sizeGlobal = 0;
int findSize(Node* r)
{
    if (!r)
    {
        return 0;
    }
    else
    {
        sizeGlobal++;
        findSize(r->left);
        findSize(r->right);
    }
    return sizeGlobal;
}

int findSize2(Node* r)
{
    if (!r)
    {
        return 0;
    }
    return findSize2(r->left) + findSize2(r->right) + 1;
}

int main(int argc, char const *argv[])
{    
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    cout<<findSize2(root);
    return 0;
}