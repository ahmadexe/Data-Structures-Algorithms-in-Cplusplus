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

Heap *heap = new Heap(20);

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
        parentData = heap->arr[parentIndex];
        if (parentData > heap->arr[i])
        {
            int temp = heap->arr[i];
            heap->arr[i] = heap->arr[parentIndex];
            heap->arr[parentIndex] = temp;
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
    insert(3);
    insert(9);
    insert(5);
    insert(37);
    insert(16);
    insert(12);
    insert(22);
    insert(4);
    insert(44);
    insert(32);
    insert(19);
    insert(47);
    insert(50);

    print();
    
    return 0;
}