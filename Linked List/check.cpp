#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int checks(int* a, int b)
{
    *a += 1;
    cout<<a<<endl;
    a = &b;
    cout<<a<<endl;
    return *a;

}

int main(int argc, char const *argv[])
{
    // int z =10000;


    int b = 10;
    int* c = &b;
    // cout<<c;
    checks(c, 1000);
    // cout<<endl<<c;
    checks(c, 100000);
    // cout<<endl<<c;
    checks(c, 10);
    // cout<<endl<<c;


    return 0;
}