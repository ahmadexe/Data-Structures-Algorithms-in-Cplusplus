#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top = -1;
    int size;
    string arr[99];

    Stack(int size)
    {
        this->size = size;
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

    void push(string data)
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

    string pop()
    {
        if (!this->isEmpty())
        {
            string valToReturn = arr[top];
            this->top--;
            return valToReturn;
        }
        else
        {
            cout << "Stack underflow" << endl;
            return "\0";
        }
    }
};

Stack *s = new Stack(99);

string postfix(string postfix) {
    int i = 0;
    while (i < postfix.size()){
    if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
        string a = s->pop();
        string b = s->pop();
        string exp = "";
        exp = "("+b+postfix[i]+a+")";
        s->push(exp);
    }
    else{
        string x = "";
        x += postfix[i];
        s->push(x);
    }
    i++;
    }
    return s->pop();
}


int main(int argc, char const *argv[])
{
    cout<<postfix("abc*+de*f+g*+")<<endl;   
    return 0;
}