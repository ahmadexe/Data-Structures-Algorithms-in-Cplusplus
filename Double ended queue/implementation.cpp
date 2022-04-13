#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DEQueue
{
public:
    int f = -1;
    int r = -1;
    int size = 0;
    int *arr;
    DEQueue(int size)
    {
        this->size = size;
        this->arr = (int *)malloc(sizeof(int) * this->size);
    }
    int isEmpty()
    {
        if ((f == r - 1) || (f == -1 && r == -1))
        {
            this->f == -1;
            this->r == -1;
            return 1;
        }
        return 0;
    }
    int isFull()
    {
        if (this->f == 0 && this->r == this->size - 1)
        {
            return 1;
        }
        return 0;
    }

    void enQueueFront(int val)
    {
        if (this->isEmpty())
        {
            this->f++;
            this->r++;
            this->arr[this->f] == val;
        }
        else if (this->isFull())
        {
            cout<<"Can't add from head"<<endl;
        }
        else if (this->f == 0)
        {
            this->r += 1;
            int i = this->r;
            int j = i-1;
            while (j >= 0)
            {
                this->arr[i] = this->arr[j];
                i--;
                j--;
            }
            this->arr[0] = val;
        }
        else
        {
            this->f--;
            this->arr[this->f] = val;
        }
    }
    void printArray()
    {
        for (int i = this->f; i <= this->r; i++)
        {
            cout<<this->arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(int argc, char const *argv[])
{
    DEQueue *q = new DEQueue(5);
    q->enQueueFront(10);
    q->enQueueFront(20);
    q->enQueueFront(30);
    q->enQueueFront(40);
    q->enQueueFront(50);

    //q->printArray();

    return 0;
}