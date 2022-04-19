#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Stack{
    int top;
    int size;
    int* arr;
};

int isEmpty(Stack* s){
    return (s->top == -1);
}

int isFull(Stack* s) {
    return (s->top == s->size-1);
}

void push(Stack* s, int val) {
    if (!isFull(s)) {
        s->arr[++s->top] = val;
    }
    else {
        cout<<"Stack overflow!"<<endl;
    }
}

int top(Stack* s){
    if (isEmpty(s)) {
        return -1;
    }
    else {
        return s->arr[s->top];
    }
}



int main(int argc, char const *argv[])
{

    


    return 0;
}