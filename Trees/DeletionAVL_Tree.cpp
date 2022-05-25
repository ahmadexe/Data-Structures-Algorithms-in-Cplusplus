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

Node *rightRotation(Node *root)
{
    Node *x = root->left;
    Node *temp = x->right;
    if (x)
    {
        x->right = root;
        root->left = temp;
        return x;
    }
    return root;
}

Node *leftRotation(Node *root)
{

    Node *x = root->right;
    Node *temp = x->left;
    if (x)
    {
        x->left = root;
        root->right = temp;
        return x;
    }
    return root;
}

int height(Node *root)
{
    if (!root)
    {
        return 0;
    }
    return (max(height(root->left), height(root->right)) + 1);
}

int balanceFactor(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return (left - right);
}

Node *insert(Node *r, Node *insertNode)
{
    if (!r)
    {
        r = insertNode;
        return r;
    }
    if (insertNode->data > r->data)
    {
        r->right = insert(r->right, insertNode);
    }
    else if (insertNode->data < r->data)
    {
        r->left = insert(r->left, insertNode);
    }
    else
    {
        cout << "Can't add duplicate values" << endl;
        return r;
    }

    int bf = balanceFactor(r);

    if (bf > 1 && r->left->data > insertNode->data)
    {
        return rightRotation(r);
    }
    if (bf < -1 && r->right->data < insertNode->data)
    {
        return leftRotation(r);
    }
    if (bf > 1 && r->left->data < insertNode->data)
    {
        r->left = leftRotation(r->left);
        return rightRotation(r);
    }
    if (bf < -1 && r->right->data > insertNode->data)
    {
        r->right = rightRotation(r->right);
        return leftRotation(r);
    }

    return r;
}

Node* inOrderPrePost(Node* root)
{
    if (root->left)
    {
        Node* x = root->left;
        while (x->right)
        {
            x = x->right;
        }
        return x;
    }
    else if (root->right)
    {
        Node* x = root->right;
        while (x->left)
        {
            x = x->left;
        }
        return x;
    }
    return root;
}

Node* deleteNode(Node* root, int key)
{
    if (!root)
    {
        return NULL;
    }
    if (!root->left && !root->right)
    {
        free(root);
        root = NULL;
        return NULL;
    }
    else
    {
        if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->data)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            Node* temp = inOrderPrePost(root);
            root->data = temp->data;
            if (root->left)
            {
                root->left = deleteNode(root->left, temp->data);
            }
            else
            {
                root->right = deleteNode(root->right, temp->data);
            }
        }
    }
    int bf = balanceFactor(root);
    if (bf > 1)
    {
        if (root->left->left)
        {
            return rightRotation(root);
        }
        else
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    if (bf < -1)
    {
        if (root->right->right)
        {
            return leftRotation(root);
        }
        else
        {
            root->right = rightRotation(root);
            return leftRotation(root);
        }
    }
    return root;
}

int main(int argc, char const *argv[])
{

    Node *root = NULL;
    root = insert(root, new Node(1));
    root = insert(root, new Node(20));
    root = insert(root, new Node(3));
    root = insert(root, new Node(4));
    root = insert(root, new Node(30));
    root = insert(root, new Node(2));
    root = deleteNode(root, 30);
    inOrder(root);

    return 0;
}