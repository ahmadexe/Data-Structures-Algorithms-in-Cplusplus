#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int len)
{
    if (len == 1)
    {
        return;
    }
    for (int i = 0; i < len - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSort(arr, len - 1);
}

int main(int argc, char const *argv[])
{

    int arr[] = {2, 5, 1, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}