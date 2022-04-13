#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int front;
    int rear;
    int size;
    int* arr;
};

int isFull(Queue* q)
{
    return (q->front == 0 && q->rear == q->size - 1);
}



int main(int argc, char const *argv[])
{

    


    return 0;
}