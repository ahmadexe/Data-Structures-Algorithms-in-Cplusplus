#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top = -1;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = (int *)malloc(sizeof(int) * this->size);
    }
    int isEmpty()
    {
        if (this->top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isFull()
    {
        if (this->top == this->size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push(int data)
    {
        if (this->isFull())
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            this->top++;
            this->arr[this->top] = data;
        }
    }

    int pop()
    {
        if (!this->isEmpty())
        {
            int valToReturn = this->arr[this->top];
            this->top--;
            return valToReturn;
        }
        else
        {
            cout << "Stack underflow" << endl;
            return 0;
        }
    }

    int topR()
    {
        if (!this->isEmpty())
        {
            return this->arr[this->top];
        }
        return -1;
    }
};

Stack *s = new Stack(100);
Stack *sorted = new Stack(100);

void insertSorted(int val)
{
    if (sorted->arr[sorted->top] > val || sorted->isEmpty())
    {
        sorted->push(val);
    }
    else
    {
        int x = sorted->pop();
        insertSorted(val);
        sorted->push(x);
    }
}

void sortMyStack()
{
    if (sorted->isEmpty())
    {
        return;
    }
    else
    {
        int val = sorted->pop();
        insertSorted(val);
              
    }
}

int main(int argc, char const *argv[])
{
    s->push(100);
    s->push(10);
    s->push(30);
    s->push(5);
    s->push(60);

    sorted->push(100);
    sorted->push(10);
    sorted->push(30);
    sorted->push(5);
    sorted->push(60);

    sortMyStack();

    s->push(sorted->arr[sorted->top]);

    // cout << s->pop() << endl;
    // cout << s->pop() << endl;
    // cout << s->pop() << endl;
    // cout << s->pop() << endl;
    // cout << s->pop() << endl;

    bool flag = 1;
    while (1)
    {
        int choice;
        cout<<"1. To pop\n"<<"2. Exit"<<endl;
        cin>>choice;
        if (choice == 1)
        {
            if (s->top <= sorted->top && (flag && s->arr[s->top] == sorted->arr[sorted->top]))
            {
                s->pop();
                cout<<s->pop()<<endl;
            }
            else
            {
                cout<<s->pop()<<endl;
            }
        }
        else if (choice == 2)
        {
            break;
        }
    }


    return 0;
}