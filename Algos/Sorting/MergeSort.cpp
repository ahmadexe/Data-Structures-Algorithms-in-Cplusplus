#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
void merge(int A[],int low,int mid,int high)
{
    int i,j,k, B[100];
    i = low;
    j = mid+1;
    k = low;
    while (i <= mid && j<= high) 
    {
        if(A[i] < A[j]) 
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = 0; i <= high; i++)
    {
        A[i] = B[i];
    }
}
 
void mergeSort(int A[],int low,int high)
{
    if (low >= high) 
    {
        return;
    }
    int mid = (low + high) / 2;
    mergeSort(A,low,mid);
    mergeSort(A,mid+1,high);
    merge(A,low,mid,high);
}
 
void printArr(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
 
int main(int argc, char const *argv[])
{    
    int A[] = {2, 8, 7, 3, 4, 1, 6,0,6};
    int size = sizeof(A) / sizeof(A[0]);
    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;
    printArr(A, size);
    mergeSort(A, low, high);
    printArr(A, size);
 
    return 0;
}