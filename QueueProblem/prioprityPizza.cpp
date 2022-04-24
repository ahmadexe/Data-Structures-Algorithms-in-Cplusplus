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



void enQueue(Queue *q, int value, string ord, vector<string> &order)
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
        int j = (q->rear + 1) % q->size;
        bool flagI = true;
        bool flagJ = true;
        while (j != q->front && q->arr[i] < value)
        {
            q->arr[j] = q->arr[i];
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
        cout<<order[j]<<endl;
        q->rear = (q->rear + 1) % q->size;
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

void deQueueMax(Queue *q, vector<string> order)
{
    if (isEmpty(q))
    {
        // return -1;
        cout << "NOOOO" << endl;
    }
    cout << q->arr[q->front] << " order is " << order[q->front] << endl;
    q->front = (q->front + 1) % q->size;
}

int deQueueMin(Queue *q)
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
    q->size = 6;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    vector<string> order(q->size);
    enQueue(q, 20, "B pizza", order);
    enQueue(q, 10, "A Pizza", order);
    enQueue(q, 40, "E Pizza", order);
    enQueue(q, 40, "D pizza", order);
    enQueue(q, 30, "C pizza", order);
    // enQueue(q, 15, "OK");
    // printArray(q);
    deQueueMax(q, order);
    deQueueMax(q, order);
    // cout<<"MIN "<<deQueueMin<<q<<endl;
    deQueueMax(q, order);
    deQueueMax(q, order);
    deQueueMax(q, order);

    // printArray(q);
    // deQueueMaximum(q);
    // printArray(q);
    return 0;
}