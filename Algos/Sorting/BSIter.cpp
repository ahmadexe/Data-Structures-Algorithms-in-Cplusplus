#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bubSort(int arr[], int size) {
    int n = size;
    for (int i = 0; i < size; i++) 
    {
        int j = 0;
        while (j < n)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }   
            j++;
        }
        n--;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 5, 1, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    


    return 0;
}