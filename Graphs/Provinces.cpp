#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> graph[N];
bool visited[N];

void dfs(int source)
{
    if (visited[source])
    {
        return;
    }
    visited[source] = true;
    for (auto child : graph[source])
    {
        dfs(child);
    }
}

int totalProvinces = 0;

void findProvinces(int noOfNodes)
{
    for (int i = 0; i < noOfNodes; i++)
    {
        if (visited[i])
        {
            continue;
        }
        else
        {
            totalProvinces++;
            dfs(i);
        }
    }
}

int main(int argc, char const *argv[])
{

    int nodes, edges;
    cin>>nodes>>edges;
    for (int i = 0; i < edges; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    findProvinces(nodes);
    cout<<totalProvinces;

    return 0;
}