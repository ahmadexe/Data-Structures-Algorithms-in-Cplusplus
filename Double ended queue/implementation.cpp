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
        
    }
};

int main(int argc, char const *argv[])
{
    DEQueue *q = new DEQueue(5);
    cout << q->isFull() << endl;
    cout << q->isEmpty() << endl;

    return 0;
}