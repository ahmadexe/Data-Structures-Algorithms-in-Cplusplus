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
    return ((q->rear + 1) % q->size == q->front);
}

int isEmpty(Queue *q)
{
    return (q->front == -1 && q->rear == -1);
}



void enQueue(Queue *q, int value, string ord, vector<string> &order)
{
    if (isEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
        q->arr[q->front] = value;
        order[q->front] = ord;
    }
    else
    {
        int i = q->rear;
        int j = (q->rear + 1) % q->size;
        bool flagI = true;
        bool flagJ = true;
        while (j != q->front && q->arr[i] < value)
        {
            q->arr[j] = q->arr[i];
            order[j] = order[i];
            if (i == 0 || j == 0)
            {
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

        q->arr[j] = value;

        order[j] = ord;

        q->rear = (q->rear + 1) % q->size;

    }
}

void deQueueMax(Queue *q, vector<string> order)
{
    if (isEmpty(q))
    {
        // return -1;
        cout << "NOOOO" << endl;
    }
    cout <<"Agr is "<< q->arr[q->front] << " order is " << order[q->front] << endl;
    q->front = (q->front + 1) % q->size;
}


int main(int argc, char const *argv[])
{

    Queue *q = new Queue;
    q->front = -1;
    q->rear = -1;
    cout<<"Enter size of your pizzeria"<<endl;
    cin>>q->size;    
    q->arr = (int *)malloc(sizeof(int) * q->size);
    vector<string> order(q->size, "No Pizza");

    while (1)
    {
        cout<<"1. Login as customer"<<endl<<"2. Login as Admin"<<endl<<"3. Exit"<<endl;
    }
    





    return 0;
}