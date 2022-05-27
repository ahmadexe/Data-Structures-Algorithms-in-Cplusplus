#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e7+10;
vector<pair<int,int>> graph[N];

void dijkstra(int source)
{
    vector<int> distance(N, INF);
    
}

int main(int argc, char const *argv[])
{

    int vertices, edges;
    cin>>vertices>>edges;
    for (int i = 0; i < edges; i++)
    {
        int v1,v2,wt;
        cin>>v1,v2,wt;
        graph[v1].push_back({v2, wt});
    }

    dijkstra(0);

    return 0;
}