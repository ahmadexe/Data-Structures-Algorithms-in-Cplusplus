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
        q->front = 0;
        q->rear = 0;
        q->arr[q->front] = value;
        order[q->front] = ord;
        cout<<q->arr[0]<<endl;
        cout<<order[0]<<endl;
        cout<<"---------------------------"<<endl;
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
        cout<<j<<" "<<"adding here "<<value<<endl;
        q->arr[j] = value;
        cout<<q->arr[j]<<endl;
        order[j] = ord;
        cout<<order[j]<<endl;
        q->rear = (q->rear + 1) % q->size;
        cout<<"----------------"<<endl;
    }
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


int main(int argc, char const *argv[])
{

    Queue *q = new Queue;
    q->front = -1;
    q->rear = -1;
    cout<<"Enter size of your pizzeria"<<endl;
    cin>>q->size;    
    q->arr = (int *)malloc(sizeof(int) * q->size);
    vector<string> order(q->size, "No Pizza");
    






    return 0;
}