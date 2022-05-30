#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e3;
vector<int> graph[N];
int visited[N];
bool found = false;
 
void closure(int source, int target)
{
    if (visited[source])
    {
        return;
    }
    visited[source] = true;
    for (int child : graph[source])
    {
        if (child == target)
        {
            found = true;
        }
        closure(child, target);
    }
}
 
int main(int argc, char const *argv[])
{
 
    int vertices,edges;
    cin>>vertices>>edges;
    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
    }    
 
    closure(0,2);
    cout<<found;
    return 0;
}