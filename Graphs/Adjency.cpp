#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
static int arr[N][N];

int main(int argc, char const *argv[])
{

    int edges;
    cin>>edges;
    for (int i = 0; i < edges; i++)
    {
        int v1,v2;
        arr[v1][v2] = 1;
        arr[v2][v1] = 1;
    }


    return 0;
}