#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int front;
    int rear;
    int size;
    int *arr;
};

int isFull(Queue *q)
{
    return (q->front == 0 && q->rear == q->size - 1);
}

int isEmpty(Queue *q)
{
    return (q->front == -1 && q->rear == -1);
}

void enQueue(Queue *q, int value)
{
    if (isEmpty(q))
    {
        q->front++;
        q->rear++;
        q->arr[q->front] = value;
    }
    else
    {
        int i = q->rear;
        int j = i + 1;
        while (i != -1 && q->arr[i] > value)
        {
            q->arr[j] = q->arr[i];
            i--;
            j--;
        }
        q->arr[j] = q->arr[i];
        q->arr[j] = value;
        q->rear++;
    }
}

void printArray(Queue *q)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        cout << q->arr[i] << " " << endl;
    }
    cout << endl;
}

int deQueueMinimum(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    return q->arr[q->front++];
}

int deQueueMaximum(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    return q->arr[q->rear--];
}

int main(int argc, char const *argv[])
{

    Queue *q = new Queue;
    q->front = -1;
    q->rear = -1;
    q->size = 5;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 40);
    enQueue(q, 30);
    enQueue(q, 15);
    printArray(q);
    deQueueMinimum(q);
    printArray(q);
    
    return 0;
}