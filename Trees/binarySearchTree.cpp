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
        root = cur;
    }
    else {
        Node* p = new Node;
        p = root;
        while (p->left != NULL || p->right != NULL){
            if (p->data < data)
            {
                p = p->right;
            }
            else{
                p = p->left;
            }
        }

    }
}

int main(int argc, char const *argv[])
{

    


    return 0;
}