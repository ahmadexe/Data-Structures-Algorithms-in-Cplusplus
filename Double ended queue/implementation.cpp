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

void enQueue(Queue *qu, int value)
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
    if (qu->front == -1 && qu->rear == -1)
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

int deQueue(Queue *q)
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

int main(int argc, char const *argv[])
{

    Queue *q = new Queue;
    q->size = 5;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    cout << deQueue(q) << endl;
    cout << deQueue(q) << endl;
    cout << deQueue(q) << endl;
    cout << deQueue(q) << endl;
    cout << deQueue(q) << endl;
    cout << isEmpty(q) << endl;
    return 0;
}