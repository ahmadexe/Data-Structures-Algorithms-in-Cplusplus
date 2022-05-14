#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int f;
    int r;
    int size;
    int *arr;
};

int empty(Queue *q)
{
    return (q->f == -1 && q->r == -1);
}

int full(Queue *q)
{
    return ((q->r + 1) % q->size == q->f);
}

int deQueueFront(Queue *q)
{
    if (empty(q))
    {
        cout << "Empty" << endl;
        return -1;
    }
    if (q->f == q->r)
    {
        int val = q->arr[q->f];
        q->f = -1;
        q->r = -1;
        return val;
    }
    else
    {
        int val = q->arr[q->f];
        q->f = (q->f + 1) % q->size;
        return val;
    }
}

int deQueueRear(Queue *q)
{
    if (empty(q))
    {
        cout << "Empty" << endl;
        return -1;
    }
    if (q->f == q->r)
    {
        int val = q->arr[q->r];
        q->r = -1;
        q->f = -1;
        return val;
    }
    else
    {
        int val = q->arr[q->r];
        if (q->r == 0)
        {
            q->r = q->size - 1;
            return val;
        }
        else
        {
            q->r = q->r - 1;
            return val;
        }
    }
}

void enQueue(Queue *q, int val)
{
    if (full(q))
    {
        cout << "Full" << endl;
        return;
    }
    if (empty(q))
    {
        // cout<<"Here "<<val<<endl;
        q->f = 0;
        q->r = 0;
        q->arr[q->f] = val;
    }
    else
    {
        int i = q->r;
        int j = (i + 1) % q->size;
        bool flagI = true;
        bool flagJ = true;
        while (j != q->f && q->arr[i] > val)
        {
            q->arr[j] = q->arr[i];
            if (i == 0)
            {
                i = q->size - 1;
                flagI = false;
            }
            if (j == 0)
            {
                j = q->size - 1;
                flagJ = false;
            }
            if (flagI)
            {
                i--;
            }
            if (flagJ)
            {
                j--;
            }
            flagI = true;
            flagJ = true;
        }
        q->arr[j] = val;
        q->r = (q->r + 1) % q->size;
    }
}

int main(int argc, char const *argv[])
{

    Queue* q = new Queue();
    q->f = -1;
    q->r = -1;
    q->size = 5;
    q->arr = (int*)malloc(sizeof(int) * q->size);
    enQueue(q, 5);
    enQueue(q, 15);
    enQueue(q, 10);
    enQueue(q, 3);
    enQueue(q, 9);
    cout<<deQueueRear(q)<<endl;

    return 0;
}