#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Deq
{

public:
    int front;
    int rear;
    int size;
    int arr[100];
    Deq(int s)
    {
        rear = -1;
        front = -1;
        size = s;
    }
    int isFull()
    {
        if (front == 0 && rear == size - 1)
        {
            return 1;
        }
        return 0;
    }

    int isEmpty()
    {
        if (front = -1 || rear == -1)
        {
            return 1;
        }
        return 0;
    }
};

void insertAtEnd(Deq *q, int key)
{
    if (q->isEmpty())
    {
        q->front++;
        q->rear++;
        q->arr[q->front] = key;
    }
    
}

int main(int argc, char const *argv[])
{

    return 0;
}