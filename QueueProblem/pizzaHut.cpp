#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int f = -1;
    int r = -1;
    int size;
    int *arr;
};

int isEmpty(Queue* q)
{
    return (q->f == -1 && q->r == -1);
}

int isFull(Queue * q)
{
    return ((q->r + 1) % q->size == q->f);
}



int main(int argc, char const *argv[])
{
    
    return 0;
}