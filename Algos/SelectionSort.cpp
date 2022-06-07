#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (i != min)
            swap(arr[i], arr[min]);
    }
}

int main(int argc, char const *argv[])
{

    int ar[] = {2, 5, 1, 4, 3};
    int size = sizeof(ar) / sizeof(ar[0]);
    selectionSort(ar, size);
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}