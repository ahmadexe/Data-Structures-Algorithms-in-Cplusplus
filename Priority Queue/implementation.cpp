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

int isEmpty(Queue* q)
{
    return (q->front == -1 && q->rear == - 1);
}

int main(int argc, char const *argv[])
{

    Queue *q = new Queue;
    q->front = -1;
    q->rear = -1;
    q->size = 5;
    q->arr = (int*)malloc(sizeof(int) * q->size);
    cout<<isEmpty(q)<<endl;
    cout<<isFull(q)<<endl;


    return 0;
}