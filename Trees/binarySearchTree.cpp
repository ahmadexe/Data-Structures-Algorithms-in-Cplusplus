#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    char data;
    Node* right;
    Node* left;
};

Node* root = NULL;

void insert(int data)
{
    if (!root) {
        Node* cur = new Node;
        cur->data = data;
        cur->left = NULL;
        cur->right = NULL;
    }
    else {
        Node* p = new Node;
        p = root;
        while (p->left != NULL || p->right != NULL){
            
        }

    }
}

int main(int argc, char const *argv[])
{

    


    return 0;
}