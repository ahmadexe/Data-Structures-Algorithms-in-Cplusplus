#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int front = -1;
    int rear = -1;
    int size;
    int *arr;
};

void enQueueFront(Queue *qu, int value)
{
    if (qu->front == -1 && qu->rear == -1)
    {
        qu->arr[++qu->front] = value;
        qu->rear++;
    }
    else
    {
        qu->rear++;
        qu->arr[qu->rear] = value;
    }
}

int isEmpty(Queue *qu)
{
    if (qu->front == -1 || qu->rear == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(Queue *q)
{
    if (q->front == 0 && q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void peek(Queue *q)
{
    if (!isEmpty(q))
    {
        cout << q->arr[q->front];
    }
    else
    {
        cout << "Can't peekm Queue underflow" << endl;
    }
}

int deQueueLast(Queue *q)
{
    if (!isEmpty(q))
    {
        int value = q->arr[q->front];
        int i = 0;
        int j = 1;
        while (j <= q->rear)
        {
            q->arr[i] = q->arr[j];
            i++;
            j++;
        }
        q->rear--;
        if (q->front > q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        return value;
    }
    return -1;
}

void printArray(Queue* q)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        cout<<q->arr[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{

    Queue *q = new Queue;
    q->size = 5;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    enQueueFront(q, 10);
    enQueueFront(q, 20);
    enQueueFront(q, 30);
    enQueueFront(q, 40);
    enQueueFront(q, 50);
    printArray(q);

    return 0;
}