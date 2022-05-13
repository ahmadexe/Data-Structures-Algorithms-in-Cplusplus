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

int checkIdentical(Node* rootA, Node* rootB)
{
    if (!rootA && !rootB)
    {
        return 1;
    }
    else if (!rootA || !rootB)
    {
        return 0;
    }
    else
    {
        int condition1 = rootA->data == rootB->data;
        int condition2 = checkIdentical(rootA->left, rootB->left);
        int condition3 = checkIdentical(rootA->right, rootB->right);
        return (condition1 && condition2 && condition3); 
    }
}

int main(int argc, char const *argv[])
{

    Node *root1 = new Node(40);
    insert(root1, 30);
    insert(root1, 10);
    insert(root1, 15);
    insert(root1, 50);
    Node* root2 = new Node(40);
    insert(root2, 30);
    insert(root2, 10);
    insert(root2, 15);
    insert(root2, 50);

    inOrder(root1);
    cout<<endl;
    inOrder(root2);
    cout<<endl;
    cout<<checkIdentical(root1, root2);
    return 0;
}