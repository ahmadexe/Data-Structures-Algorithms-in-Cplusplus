#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top = -1;
    vector<char> arr;
    int size;

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

    void push(char data)
    {
        if (this->isFull())
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            this->top++;
            this->arr.push_back(data);
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

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else{
        return -1;
    }
}

string postfix(string infix)
{
    string result = "";
    int i = 0;
    while (i < infix.size())
    {
        
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {         
            result += infix[i];
        }
        else if (infix[i] == '('){
            s->push('(');
        }
        else if (infix[i] == ')'){
            while (s->isEmpty() == 0 && s->arr[s->top] != '(')
            {
                result += s->arr[s->top];
                s->pop();
            }
            if (s->isEmpty() == 0){
                s->pop();
            }
        }
        else{
            while (s->isEmpty() == 0 && precedence(s->arr[s->top]) > precedence(infix[i]))
            {
                result += s->arr[s->top];
                s->pop();
            }
            s->push(infix[i]);
        }
        i++;
    }
    while (s->isEmpty() != 1)
    {
        result += s->arr[s->top];
        s->pop();
    }
    return result;
}

int main(int argc, char const *argv[])
{
    cout<<postfix("(a+b)*(c/d-l)");
    return 0;
}