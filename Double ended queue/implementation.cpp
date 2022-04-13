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

void enQueueLast(Queue *qu, int value)
{
    if (isFull(qu))
    {
        cout<<"Queue overflow"<<endl;
    }
    else if (qu->front == -1 && qu->rear == -1)
    {
        qu->arr[++qu->front] = value;
        qu->rear++;
    }
    else
    {
        qu->rear = (qu->rear + 1) % qu->size;
        qu->arr[qu->rear] = value;
    }
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

int deQueueFirst(Queue *q)
{
    if (!isEmpty(q))
    {
        if (q->front == 0 && q->rear == 0)
        {
            int val = q->arr[q->front];
            q->front--;
            q->rear--;
            return val;
        }
        else
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
    }
    return -1;
}

void printArray(Queue *q)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        cout << q->arr[i] << " ";
    }
    cout << endl;
}

void enQueueFirst(Queue *q, int val)
{
    if (isFull(q))
    {
        cout << "CAN'T" << endl;
    }
    else if (isEmpty(q))
    {
        q->front++;
        q->rear++;
        q->arr[q->front] = val;
    }
    else if (q->front != 0)
    {
        q->front--;
        q->arr[q->front] = val;
    }
    else if (q->front == 0)
    {
        int i = q->rear;
        int j = i + 1;
        while (i >= 0)
        {
            q->arr[j] = q->arr[i];
            j--;
            i--;
        }
        q->arr[j] = val;
        q->rear++;
    }
}

int deQueueLast(Queue* q)
{
    if (isEmpty(q))
    {
        cout<<"Can't, Queue undeflow"<<endl;
        return -1;
    }
    else if (q->rear == 0)
    {
        int value = q->arr[q->rear];
        q->rear--;
        q->front--;
        return value; 
    }
    else
    {
        int value = q->arr[q->rear];
        q->rear--;
        return value;
    }
}

int main(int argc, char const *argv[])
{

    Queue *q = new Queue;
    q->size = 5;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    enQueueFirst(q,10);
    enQueueFirst(q,20);
    enQueueFirst(q,30);
    enQueueFirst(q,40);
    enQueueLast(q,50);

    printArray(q);

    return 0;
}