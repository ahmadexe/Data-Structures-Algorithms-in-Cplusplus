#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Heap
{
    int last;
    int capacity;
    int * arr;
    Heap(int c)
    {
        capacity = c;
        last = -1;
        arr = (int*)malloc(sizeof(int) * capacity);
    }
};

Heap *heap = new Heap(10);

int isFull()
{
    return (heap->last == heap->capacity);    
}

void insert(int val)
{
    if (isFull())
    {
        return;
    }
    heap->last++;
    heap->arr[heap->last] = val;
    int i = heap->last;
    int parentData = INT_MAX;
    while (i != 0 && parentData > heap->arr[i])
    {
        int parentIndex = (i - 1) / 2;
        if (heap->arr[parentIndex] > heap->arr[i])
        {
            int temp = heap->arr[i];
            heap->arr[i] = heap->arr[parentIndex];
            heap->arr[parentIndex] = temp;
        }
        else
        {
            break;
        }
        i = parentIndex;
    }
}

void print()
{
    for (int i = 0; i <= heap->last; i++)
    {
        cout<<heap->arr[i]<<" ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    insert(10);
    insert(20);
    insert(1);
    insert(3);
    insert(2);
    print();
    
    return 0;
}