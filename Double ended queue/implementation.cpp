#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Deq{

int front;
int rear;
int size;
int arr[100];

public:
    Deq(int s)
    {
        rear = 0;
        front = -1;
        size = s;
    }
    int isFull()
    {
        if (front == 0 && rear == size - 1 || front == rear + 1)
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

int main(int argc, char const *argv[])
{

    


    return 0;
}