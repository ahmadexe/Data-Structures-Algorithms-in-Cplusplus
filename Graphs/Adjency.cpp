#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
static int arr[N][N];

void printList(int vertexTotal)
{
    for (int i = 0; i < vertexTotal; i++)
    {
        cout<<i;
        for (int j = 0; j < vertexTotal; j++)
        {
            if (arr[i][j])
            {
                cout<<"-> "<<j;
            }
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{

    int vertex, edges;
    cin>>vertex>>edges;
    for (int i = 0; i < edges; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        arr[v1][v2] = 1;
        arr[v2][v1] = 1;
    }

    printList(vertex);

    return 0;
}