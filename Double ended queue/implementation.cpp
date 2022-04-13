#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DEQueue{
public:
    int f = -1;
    int r = -1;
    int size = 0;
    DEQueue(int size)
    {
        this->size = size;
    }
    int isEmpty(){
        if (this->f == this->r - 1){
            return 1;
        }
        return 0;
    }
    int isFull()
    {
        if (this->f = 0 && this->r == this->size - 1)
        {
            return 1;
        }
        return 0;
    }
};

void enQueueFront(DEQueue* q)
{
    
}

int main(int argc, char const *argv[])
{
    DEQueue* q = new DEQueue(5);
    cout<<q->isFull()<<endl;
    cout<<q->isEmpty()<<endl;

    return 0;
}