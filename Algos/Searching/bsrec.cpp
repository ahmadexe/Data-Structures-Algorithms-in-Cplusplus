#include<iostream>

using namespace std;

void binarySearchRecusrssive(int arr[], int key, int low, int high) {

    int mid = (low + high) / 2;
    if (low > high)
    {
        cout << "Element not found";
        return;
    }
    else if (key < arr[mid]) 
    {
binarySearchRecusrssive(arr, key, low, mid - 1);
    }
    else if (key > arr[mid])
    {
        binarySearchRecusrssive(arr, key, mid + 1, high);
    }
    else if (key == arr[mid])
    {
        cout<<"Element found at "<<mid<<endl;
        return;
    }
}

int main(int argc, char const *argv[])
{

    int arr[] = {1,2,3,4,5,6};
    int key = 5;
    binarySearchRecusrssive(arr, key, 0, 6);
    


    return 0;
}