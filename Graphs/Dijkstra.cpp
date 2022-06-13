#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e7+10;
vector<pair<int,int>> graph[N];

vector<int> dijkstra(int source)
{
    vector<int> distance(N, INF);
    set<pair<int,int>> s;
    distance[source] = 0;
    s.insert({0, source});
    while (!s.empty())
    {
        auto current = *(s.begin());
        int weightCurrent = current.first;
        int vertex = current.second;
        s.erase(s.begin());
        for (auto child : graph[vertex])
        {
            int childVertex = child.first;
            int childWeight = child.second;
            if (childWeight + weightCurrent < distance[childVertex])
            {
                distance[childVertex] = childWeight + weightCurrent;
                s.insert({distance[childVertex], childVertex});
            }
        } 
    }
    return distance;
}

int main(int argc, char const *argv[])
{
    int vertices, edges;
    cin>>vertices>>edges;
    for (int i = 0; i < edges; i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back({v2, wt});
    }

    vector<int> distance = dijkstra(0);
    for (int i = 0; i < vertices; i++)
    {
        cout<<"0"<<" - "<<i<<" "<<distance[i]<<endl;
    }
    

    return 0;
}