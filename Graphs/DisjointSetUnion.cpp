// This code doesn't invlolve reverse Ackerman time  
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int parent[N];

void make(int n) {
    parent[n] = n;
}

int find(int n) {
    if (parent[n] == n) {
        return n;
    }
    return find(parent[n]);
}

void unionn(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    parent[pa] = pb;
}

int main(int argc, char const *argv[])
{

    int n, k;
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    while (k--)
    {
        int u, v;
        cin>>u>>v;
        unionn(u, v);
    }

    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
        {
            total++;
        }
    }

    cout<<total;

    return 0;
}