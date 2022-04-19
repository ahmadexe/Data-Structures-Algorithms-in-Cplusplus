#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top = -1;
    int size;
    int* arr;
    Stack(int size)
    {
        this->size = size;
        arr = (int*)malloc(sizeof(int) * size);
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
            this->arr[top] = data;
        }
    }

    int pop()
    {
        if (!this->isEmpty())
        {
            int valToReturn = arr[top];
            this->top--;
            return valToReturn;
        }
        cout << "Stack underflow" << endl;
        return -1;
    }
};

Stack *s = new Stack(20);

int evaluate(string eq)
{
    int i = 0;
    while (i < eq.size())
    {
        if (eq[i] == '+')
        {
            int a = s->pop();
            int b = s->pop();
            int c = b + a;
            s->push(c);
        }
        else if (eq[i] == '-')
        {
            int a = s->pop();
            int b = s->pop();
            int c = b - a;
            s->push(c);
        }
        else if (eq[i] == '*')
        {
            int a = s->pop();
            int b = s->pop();
            int c = b * a;
            s->push(c);
        }
        else if (eq[i] == '/')
        {
            int a = s->pop();
            int b = s->pop();
            int c = b / a;
            s->push(c);
        }
        else
        {
            int x = eq[i] - 48;
            s->push(x);
        }
        i++;
    }
    return s->pop();
}

int main(int argc, char const *argv[])
{
    cout<<evaluate("231*+9-");
    return 0;
}