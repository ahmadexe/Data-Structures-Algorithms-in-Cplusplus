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

bool skip = 0;
void del(Stack* s, int val)
{
    if (s->arr[s->top] == val || empty(s))
    {
        if (!empty(s))
        {
            pop(s);
        }
        // skip = 1;
        return;
    }
    else
    {
        int temp = pop(s);
        del(s, val);
        if (temp != val);
        {
            push(s, temp);
        }
    }
}

int main(int argc, char const *argv[])
{

    
    Stack* s = new Stack(6);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    
    del(s,70);

    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;



    return 0;
}