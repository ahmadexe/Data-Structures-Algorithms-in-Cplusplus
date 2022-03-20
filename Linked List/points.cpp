#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{

    int a = 9;
    int* b = &a;
    cout<<b<<endl;
    free(b);
    cout<<b<<endl;;
    b = NULL;
    cout<<b<<endl;
    if (!b)
    {
        cout<<"work"<<endl;
    }

    return 0;
}