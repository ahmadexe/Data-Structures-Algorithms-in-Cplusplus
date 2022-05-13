#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    int data;
    Node *right;
};

void insert(int val, Node *r)
{
    if (!r->left || !r->right)
    {
        Node *n = new Node;
        n->data = val;
        n->left = NULL;
        n->right = NULL;
        if (!r->left && val < r->data)
        {
            r->left = n;
            return;
        }
        else if (!r->right && val > r->data)
        {
            r->right = n;
            return;
        }
    }

    if (val > r->data)
    {
        insert(val, r->right);
    }
    else
    {
        insert(val, r->left);
    }
}

void inOrder(Node *r)
{
    if (!r)
    {
        return;
    }
    else
    {
        inOrder(r->left);
        cout << r->data << " ";
        inOrder(r->right);
    }
}

void printAncestors(Node *r, int num)
{
    Node *p = new Node;
    p = r;
    while (p->data != num && (p->left != NULL && p->right != NULL))
    {
        cout << p->data << " ";
        if (p->data < num)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
}

int main(int argc, char const *argv[])
{
    Node *root = new Node;
    root->data = 40;
    root->left = NULL;
    root->right = NULL;
    insert(30, root);
    insert(10, root);
    insert(15, root);
    insert(50, root);
    // insert(5, root);
    inOrder(root);
    cout << endl;
    // printAncestors(root, 20);
    return 0;
}