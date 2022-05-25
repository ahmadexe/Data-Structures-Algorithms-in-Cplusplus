#include <iostream>
#include <bits/stdc++.h>
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

Node* inOrderPostPre(Node* root)
{
    Node* p = root;
    if (p->right)
    {
        p = p->right;
        while (p->left)
        {
            p = p->left;
        }
    }
    else if (p->left)
    {
        p = p->left;
        while (p->right)
        {
            p = p->right;
        }
    }
    return p;
}

Node* deleteNode(Node* root , int val)
{
    if (!root)
    {
        return NULL;
    }
    else if (!root->left && !root->right)
    {
        free(root);
        root = NULL;
        return NULL;
    }
    else
    {
        if (val > root->data)
        {
            root->right = deleteNode(root->right, val);
        }
        else if (val < root->data)
        {
            root->left = deleteNode(root->left, val);
        }
        else
        {
            Node* replace = inOrderPostPre(root);
            root->data = replace->data;
            if (root->right)
            {
                root->right = deleteNode(root->right, root->data);
            }
            else if (root->left)
            {
                root->left = deleteNode(root->left, root->data);
            }
        }
    }
    return root;
}

int main(int argc, char const *argv[])
{
    Node *root1 = new Node(40);
    insert(root1, 30);
    insert(root1, 10);
    insert(root1, 15);
    insert(root1, 50);
    Node* p = root1;
    inOrder(root1);
    cout<<"\n";
    root1  =  deleteNode(p, 40);
    cout<<"\n";
    inOrder(root1);
 
    return 0;
}