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

void inOrder(Node* root)
{
    if (!root)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        cout<<root->data;
        inOrder(root->right);
    }
}

Node* rightRotation(Node* root)
{
    if (!root->left)
    {
        return root;
    }
    else
    {
        Node* x = root->left;
        Node* temp = x->right;
        x->right = root;
        root->left = temp;
        return x;
    }
}

Node* leftRotation(Node* root)
{
    if (!root->right)
    {
        return root;
    }
    else
    {
        Node* x = root->right;
        Node* temp = x->left;
        x->left = root;
        root->right = temp;
        return x;
    }
}

int height(Node* root)
{
    if (!root)
    {
        return 0;
    }
    return (max(height(root->left), height(root->right)) + 1);
}

int balanceFactor(Node* root)
{
    if (!root)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return (left - right);
}

Node* insert(Node* r, Node* insertNode)
{
    if (!r)
    {
        r = insertNode;
    }
    else if (insertNode->data > r->data)
    {
        r->right = insert(r->right, insertNode);
    }
    else if (insertNode->data < r->data)
    {
        r->left = insert(r->left, insertNode);
    }
    else
    {
        cout<<"Can't add duplicate values"<<endl;
        return r;
    }
    
    int bf = balanceFactor(r);

    if (bf > 1 && r->left->data > insertNode->data)
    {
        return rightRotation(r);
    }
    if (bf > 1 && r->left->data < insertNode->data)
    {
        r->left = leftRotation(r);
        return rightRotation(r);
    }
    if (bf < -1 && r->right->data < insertNode->data)
    {
        return leftRotation(r);
    }
    if (bf < -1 && r->right->data > insertNode->data)
    {
        r->right = rightRotation(r);
        return leftRotation(r);
    }
    return r;
}

int main(int argc, char const *argv[])
{

    Node* root = NULL;   
    root = insert(root, new Node(50));
    root = insert(root, new Node(40));
    root = insert(root, new Node(30));
    root = insert(root, new Node(20));
    root = insert(root, new Node(10));

    inOrder(root);
 
 
    return 0;
}