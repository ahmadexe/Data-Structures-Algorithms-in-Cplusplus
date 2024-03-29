#include <iostream>
#include <vector>
using namespace std;

struct Queue
{
    int f = -1;
    int r = -1;
    int size;
    int *arr;
};

int isFull(Queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q)
{
    if (q->r == -1 && q->f == -1)
    {
        return 1;
    }
    return 0;
}

void enQueue(Queue *q, int data)
{
    if (isEmpty(q))
    {
        q->f = (q->f + 1) % q->size;
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = data;
    }
    else if (isFull(q))
    {
        cout<<"Can't enqueue, Queue overflow"<<endl;
    }
    else
    {
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = data;
    }
}

int deQueue(Queue* q)
{
    if (isEmpty(q))
    {
        return -1;
    }
    else{
        int val = q->arr[q->f];
        q->f = (q->f + 1)%q->size;
        return val;
    }
}

int main(int argc, char const *argv[])
{
    Queue *q = new Queue;
    q->size = 4;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    enQueue(q,10);
    enQueue(q,20);
    enQueue(q,30);
    enQueue(q,40);
    enQueue(q,50);
    cout<<deQueue(q)<<endl;
    enQueue(q,50);
    cout<<deQueue(q)<<endl;
    

    return 0;
}