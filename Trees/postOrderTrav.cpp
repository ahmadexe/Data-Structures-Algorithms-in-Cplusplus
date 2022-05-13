#include<iostream>
#include<bits/stdc++.h>
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
        if (p->data < root->data && !root->left)
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
    else if (val < root->data)
    {
        insert(root->left, val);
    }
}

void postOrder(Node* root)
{
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while (!s1.empty())
    {   
        s2.push(s1.top());
        root = s1.top();
        s1.pop();
        if (root->left)
        {
            s1.push(root->left);
        }
        if (root->right)
        {
            s1.push(root->right);
        }
    }
    while (!s2.empty())
    {
        // cout<<"Here"<<endl;
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

void inOrder(Node* root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder2(Node* root)
{
    if (!root)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(int argc, char const *argv[])
{
    Node *root1 = new Node(40);
    insert(root1, 30);
    insert(root1, 10);
    insert(root1, 15);
    insert(root1, 50);
    insert(root1, 60);
    insert(root1, 70);   
    Node* p = root1;
    postOrder2(p);
    cout<<endl;
    p = root1;
    postOrder(p);
    return 0;
}