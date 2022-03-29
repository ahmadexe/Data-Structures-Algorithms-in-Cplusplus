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
    if ('[')
    {
        return 3;
    }
    else if ('{')
    {
        return 2;
    }
    else if ('(')
    {
        return 1;
    }
}

int balancedParenthesis(string str)
{
    int i = 0;
    while (i < s->size)
    {
        if (str[i] == '(')
        {
            s->push('(');
        }
        else if (str[i] == '{' && s->isEmpty() || str[i] == '{' && precedence('{') >= precedence(s->arr[s->top]))
        {
            s->push('{');
        }
        else if (str[i] == '[' && s->isEmpty() || str[i] == '[' && precedence('[') >= precedence(s->arr[s->top]))
        {
            s->push('[');
        }
        else if (str[i] == ']')
        {
            if (s->arr[s->top] == '[')
            {
                s->pop();
            }
            else
            {
                return 0;
            }
        }
        else if (str[i] == '}')
        {
            if (s->arr[s->top] == '{')
            {
                s->pop();
            }
            else
            {
                return 0;
            }
        }
        else if (str[i] == ')')
        {
            if (s->arr[s->top] == '(')
            {
                s->pop();
            }
            else
            {
                return 0;
            }
        }
        i++;
    }
    if (s->isEmpty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    cout << balancedParenthesis("[{(())}]");
    return 0;
}