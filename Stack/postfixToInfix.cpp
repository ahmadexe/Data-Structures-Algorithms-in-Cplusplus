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


int main(int argc, char const *argv[])
{

    


    return 0;
}