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
    else
    {
        return -1;
    }
}

int validate(string s)
{
    int i = 0;
    int j = 1;
    while (j < s.size())
    {
        if ((precedence(s[i]) > -1))
        {
            // cout<<s[i]<<" "<<precedence(s[i])<<endl;

            if (precedence(s[j]) > -1)
            {
                // cout<<s[j]<<" "<<precedence(s[j])<<endl;
                return 0;
            }
        }
        i++;
        j++;
    }
    return 1;
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
        else if (str[i] == '{')
        {
            if (s->isEmpty())
            {
                s->push('{');
            }
            else if (precedence('{') <= precedence(s->arr[s->top])){
                s->push('{');
            }
            else{
                return 0;
            }
        }
        else if (str[i] == '[')
        {
            if (s->isEmpty())
            {
                s->push('[');
            }
            else if (precedence('[') <= precedence(s->arr[s->top])){
                s->push('[');
            }
            else{
                return 0;
            }
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


string postfix(string infix)
{

    if (!validate(infix))
    {
        return "Wrong statement";
    }
    if (!balancedParenthesis(infix))
    {
        return "Wrong statement";
    }
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
            if (!s->isEmpty()){
                s->pop();
            }
        }
        else{
            while (s->isEmpty() == 0 && (precedence(s->arr[s->top]) >= precedence(infix[i])))
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
    cout<<postfix("(a+b)*c");
    return 0;
}