#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e7+10;
vector<pair<int,int>> graph[N];
vector<int> distanceArr(N, INF);
vector<int> parent(N, -1);
bool visited[N];

void Prims(int source)
{
    set<pair<int,int>> s;
    distanceArr[source] = 0;
    s.insert({0, source});
    while (!s.empty())
    {
        auto current = *(s.begin());
        int weightCurrent = current.first;
        int vertex = current.second;
        s.erase(s.begin());
        visited[vertex] = true;
        for (auto child : graph[vertex])
        {
            int childVertex = child.first;
            int childWeight = child.second;
            if (childWeight < distanceArr[childVertex] && !visited[childVertex])
            {
                distanceArr[childVertex] = childWeight;
                parent[childVertex] = vertex;
                s.insert({distanceArr[childVertex], childVertex});
            }
        } 
    }
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
        graph[v2].push_back({v1, wt});
    }

    Prims(0);
    int sum = 0;
    for (int i = 0; i <= vertices; i++)
    {
        // cout << "0 " << i << " " << distanceArr[i] << endl;
        sum += distanceArr[i];
    }
    cout<<sum<<endl;

    return 0;
}