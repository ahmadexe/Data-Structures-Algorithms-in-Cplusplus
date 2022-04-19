#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Stack
{
    int top;
    int size;
    string *arr;
};

int isEmpty(Stack *s)
{
    return (s->top == -1);
}

int isFull(Stack *s)
{
    return (s->top == s->size - 1);
}

void push(Stack *s, string val)
{
    if (!isFull(s))
    {
        s->arr[++s->top] = val;
    }
    else
    {
        cout << "Stack overflow!" << endl;
    }
}



string convertToInfix(Stack* s,string postfix) {
    int i = 0;
    while (i < postfix.size())
    {
        if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z'))
        {   
            string toPush = "";
            toPush += postfix[i];
            push(s, toPush);
        }
        else {
            string exp = "";
            string a = pop(s);
            
            string b = pop(s);
            
            exp = "("+b+postfix[i]+a+")";
            push(s,exp);
        }
        i++;
    }
    return pop(s);
}

string pop(Stack *s)
{
    if (!isEmpty(s))
    {
       return s->arr[s->top--];
    }
    else
    {
        cout << "Can't pop Stack underflow" << endl;
        return "-1";
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}