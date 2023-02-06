#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{

    int arr[] = {2, 3, 1, 6, 4, 9, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int index = linearSearch(arr, size, key);
    cout << index;

    return 0;
}