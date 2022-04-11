#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DEQueue{
public:
    int f = -1;
    int r = -1;
    int isEmpty(){
        if (this->f == -1 && this->r == -1){
            return 1;
        }
        return 0;
    }
    int isFull()
    {
        if (this->f == this->r)
        {
            return 1;
        }
        return 0;
    }
};



int main(int argc, char const *argv[])
{
    DEQueue* q = new DEQueue();
    cout<<q->isFull()<<endl;
    cout<<q->isEmpty()<<endl;

    return 0;
}