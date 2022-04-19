#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top = -1;
    char* arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        this->arr = (char*)malloc(sizeof(char) * this->size);
    }

    int isEmpty()
    {
        if (this->top == -1)
        {
            return 1;
        }
        return 0;
    }

    int isFull()
    {
        if (this->top == this->size - 1)
        {
            return 1;
        }
        return 0;
    }

    void push(char data)
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

    char pop()
    {
        if (!this->isEmpty())
        {
            int valToReturn = arr[top];
            this->top--;
            return valToReturn;
        }
        else
        {
            cout << "Stack underflow" << endl;
            return '\0';
        }
    }
};

Stack *s = new Stack(99);




int main(int argc, char const *argv[])
{
    
    return 0;
}