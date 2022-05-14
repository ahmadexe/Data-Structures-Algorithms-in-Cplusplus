#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Stack
{
    int top;
    int size;
    int* arr;
    Stack(int sizeOfStack)
    {
        top = -1;
        size = sizeOfStack;
        arr = (int*)malloc(__SIZEOF_INT__ * size);
    }
};

int empty(Stack* s)
{
    return (s->top == -1);
}

int full(Stack* s)
{
    return (s->top == s->size - 1);
}

void push(Stack* s, int val)
{
    if (full(s))
    {
        cout<<"Full"<<endl;
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}

int pop(Stack* s)
{
    if (empty(s))
    {
        return -1;
    }
    int val = s->arr[s->top];
    s->top--;
    return val;
}

void sortMethod(Stack* s, int val)
{
    if (empty(s) || s->arr[s->top] > val)
    {
        push(s, val);
        return;
    }
    else
    {
        int temp = pop(s);
        sortMethod(s, val);
        push(s, temp);
    }
}

void sortStack(Stack* s, Stack* sorted)
{
    if (empty(s))
    {
        return;
    }
    else
    {
        int temp = pop(s);
        sortStack(s, sorted);
        sortMethod(sorted, temp);
        push(s, temp);
    }
}

int main(int argc, char const *argv[])
{

    Stack* s2 = new Stack(6);
    Stack* s = new Stack(6);
    push(s, 10);
    push(s, 2);
    push(s, 5);
    push(s, 3);
    push(s, 50);
    sortStack(s, s2);
    cout<<pop(s2)<<endl;
    cout<<pop(s2)<<endl;
    cout<<pop(s2)<<endl;
    cout<<pop(s2)<<endl;
    cout<<pop(s2)<<endl;



    return 0;
}