// Representation with weights
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> v[10];

int main(int argc, char const *argv[])
{
    v[0].push_back(0);
    v[0].push_back(1);
    v[0].push_back(2);
    v[0].push_back(3);
    v[0].push_back(4);

    v[1].push_back(10);
    v[1].push_back(20);
    v[1].push_back(30);
    v[1].push_back(40);
    v[1].push_back(50);

    v[1];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}