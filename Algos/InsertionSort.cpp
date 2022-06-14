#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[]) {
    int arr[] = {2, 5, 1, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void insertionSortReccursive(int arr[], int size) {
    if (size == 1) {
        return;
    }
    insertionSortReccursive(arr, size - 1);
    int key = arr[size - 1];
    int j = size - 2;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
}

int main(int argc, char const *argv[])
{

    


    return 0;
}