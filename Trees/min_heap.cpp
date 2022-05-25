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

Heap *heap = new Heap(6);

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

int indexMin(int left, int right)
{
    if (heap->arr[left] < heap->arr[right])
    {
        return left;
    }
    return right;
}

int getMin()
{
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->last];
    heap->last--;
    int i = 0;
    int leftChildIndex = (2 * i) + 1;
    int rightChildIndex = (2 * i) + 2;
    int minIndex = indexMin(leftChildIndex, rightChildIndex);
    
    while (minIndex <= heap->last && i <= heap->last)
    {
        
        if (heap->arr[i] > heap->arr[minIndex])
        {
            int temp = heap->arr[i];
            heap->arr[i] = heap->arr[minIndex];
            heap->arr[minIndex] = temp;
            i = minIndex;
        }
        else
        {
            break;
        }
        leftChildIndex = (2 * i) + 1;
        rightChildIndex = (2 * i) + 2;
        int minIndex = indexMin(leftChildIndex, rightChildIndex);
    }
    return min;
}

int main(int argc, char const *argv[])
{
    insert(3);
    insert(9);
    insert(5);
    insert(37);
    insert(16);
    insert(12);
    
 
    cout<<getMin()<<endl;
    cout<<getMin()<<endl;
    cout<<getMin()<<endl;
    cout<<getMin()<<endl;
    cout<<getMin()<<endl;
    cout<<getMin()<<endl;




    
    return 0;
}