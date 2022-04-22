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

void takeOrderAtFront(Queue * q, int val)
{
    if (isFull(q))
    {
        cout<<"Not accepting more orders"<<endl;
    }
    else
    {

        if (q->f == -1 && q->r == -1)
        {
            q->f = 0;
            q->r = 0;
            q->arr[q->f] = val;
        }
        else if (q->f == 0)
        {
            q->f = q->size - 1;
            q->arr[q->f] = val;
        }
        else
        {
            q->arr[--q->f] = val;
        }
    }
}

int main(int argc, char const *argv[])
{
    

    Queue *q = new Queue;
    q->f = -1;
    q->r = -1;
    int M;
    cout << "Enter total number of accepted orders" << endl;
    cin>>M;
    q->size = M;
    q->arr = (int *)malloc(sizeof(int) * q->size);

    while (1)
    {
        int choiceMain;
        cout << "1. Enter as customer\n"
             << "2. Login as admin" << endl
             << "3. Exit" << endl;
        cin >> choiceMain;
        if (choiceMain == 1)
        {
            while (1)
            {
                int choiceC;
                cout << "1. Place order" << endl
                     << "2. Exit" << endl;
                cin >> choiceC;
                if (choiceC == 1)
                {
                    int order;
                    cout << "Enter order id" << endl;
                    cin>>order;
                    takeOrder(q, order);
                }
                else if (choiceC == 2)
                {
                    break;
                }
                else
                {
                    cout << "Invalid Choice" << endl;
                }
            }
        }

        else if (choiceMain == 2)
        {
            while (1)
            {
                int choiceC;
                cout << "1. Deliver" << endl
                     << "2. Exit" << endl;
                cin >> choiceC;
                if (choiceC == 1)
                {
                    cout << deliver(q) << endl;
                }
                else if (choiceC == 2)
                {
                    break;
                }
                else
                {
                    cout << "Invalid Choice" << endl;
                }
            }
        }
        else if (choiceMain == 3)
        {
            break;
        }

        else
        {
            cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}