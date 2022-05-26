#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    vector<int> b = {1,2,3,4};
    vector<int>* v = &b;
    v[0].push_back(10);
    cout<<v[0][0];


    
    



    return 0;
}