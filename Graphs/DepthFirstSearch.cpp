#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> vertices[N];
bool visited[N];

int main(int argc, char const *argv[])
{
    int nodes, edges;
    cin>>nodes>>edges;
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        vertices[v1].push_back(v2);
        vertices[v2].push_back(v1);
    }

    return 0;
}