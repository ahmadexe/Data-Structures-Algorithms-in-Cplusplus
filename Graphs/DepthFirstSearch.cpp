#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;
vector<int> vertices[N];
bool visited[N];

void dfs(int vertex)
{
    /*
    * Take action after entering the vertex.
    */
    if (visited[vertex])
        return;
    visited[vertex] = true;
    cout<<vertex<<" ";
    for (int child : vertices[vertex])
    {
    /*
    * Take action on child vertex before it sends its child on top of the stack
    */
        dfs(child);
    /*
    * Take action on the child after leaving the child.
    */
    }
    /*
    * Take action on the vertex before leaving the vertex.
    */
}

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

    dfs(0);

    return 0;
}