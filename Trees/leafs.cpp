#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    char data;
    Node* right;
    Node* left;
};

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

int printLeafs(Node* root)
{
    static int count = 0;
    // cout << count << endl;
    if (!root)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        count++;
        return count;
    }
    int dataL = printLeafs(root->left);
    int dataR = printLeafs(root->right);
    cout << dataL << " " << dataR << endl;
    return (dataL + dataR);
}   

int main(int argc, char const *argv[])
{
 
    Node* root = new Node;
    Node* left = new Node;    
    Node* right = new Node;
    Node* bl = new Node;
    bl->data = 'D';
    bl->left = NULL;
    bl->right = NULL;
    
    Node* br = new Node;
    br->data = 'E';
    br->left = NULL;
    br->right = NULL;

    Node* cl = new Node;
    cl->data = 'F';
    cl->left = NULL;
    cl->right = NULL;

    Node* cr = new Node;
    cr->data = 'G';
    cr->left = NULL;
    cr->right = NULL;
 
    root->data = 'A';
    root->left = left;
    root->right = right;
 
    left->data = 'B';
    left->left = bl;
    left->right = br;
 
    right->data = 'C';
    right->left = cl;
    right->right = cr;
 
    // inOrder(root);   

    // printLeafs(root);
    cout << printLeafs(root);
    return 0;
}