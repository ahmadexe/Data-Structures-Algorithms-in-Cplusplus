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

int isEmpty(Queue *q)
{
    return (q->f == -1 && q->r == -1);
}

int isFull(Queue *q)
{
    return ((q->r + 1) % q->size == q->f);
}

void takeOrderAtRear(Queue *q, int oid)
{
    if (isFull(q))
    {
        cout << "Sorry! Can't accept more orders." << endl;
    }
    else if (isEmpty(q))
    {
        q->f = 0;
        q->r = 0;
        q->arr[q->f] = oid;
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = oid;
    }
}

int deliverFromFront(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "No pending orders"<< endl;
        return -1;
    }
    else
    {
        if (q->f != q->r)
        {
            int id = q->arr[q->f];
            q->f = (q->f + 1) % q->size;
            return id;
        }
        else
        {
            int id = q->arr[q->f];
            q->f = -1;
            q->r = -1;
            return id;
        }
    }
}

int deliverFromRear(Queue* q)
{
    if (isEmpty(q))
    {
        cout<<"No pending orders"<<endl;
        return -1;
    }
    else
    {
        if (q->f == q->r)
        {
            int id = q->arr[q->r];
            q->f = -1;
            q->r = -1;
            return id;
        }
        else
        {
            if (q->r == 0)
            {
                int id = q->arr[q->r];
                q->r = q->size -1;
                return id;
            }
            else
            {
                int id = q->arr[q->r];
                q->r = q->r - 1;
                return id;
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    


    return 0;
}