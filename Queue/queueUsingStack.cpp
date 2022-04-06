#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    stack<int> s2;

    void insertAtBottom(int value)
    {
        if (this->s2.empty())
        {
            this->s2.push(value);
        }
        else
        {
            int preVal = this->s2.top();
            this->s2.pop();
            insertAtBottom(value);
            this->s2.push(preVal);
        }
    }
    
    void enQueue(int data)
    {
        insertAtBottom(data);
    }

    int deQueue()
    {
        int value = this->s2.top();
        this->s2.pop();
        return value;
    }

};

int main(int argc, char const *argv[])
{

    Queue* q = new Queue();
    q->enQueue(10);
    q->enQueue(20);
    q->enQueue(30);
    q->enQueue(40);
    q->enQueue(50);
    cout<<q->deQueue()<<endl;
    cout<<q->deQueue()<<endl;
    cout<<q->deQueue()<<endl;
    cout<<q->deQueue()<<endl;
    cout<<q->deQueue()<<endl;


    return 0;
}