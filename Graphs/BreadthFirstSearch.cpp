#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
bool visited[N];
vector<int> vertices[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int outVal = q.front();
        q.pop();
        cout<<outVal<<" ";
        for (int child : vertices[outVal])
        {
            if (!visited[child])
                q.push(child);
            visited[child] = true;
        }
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int vertex, edges;
    cin>>vertex>>edges;
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        vertices[v1].push_back(v2);
        vertices[v2].push_back(v1);
    }    

    bfs(1);
    return 0;
}