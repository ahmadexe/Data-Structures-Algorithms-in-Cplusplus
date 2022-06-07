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

    vector<pair<int, pair<int, int>>> edges;
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt, {u,v}});
    }   

    sort(edges.begin(), edges.end());
    int totalCost = 0;
    for (auto &edge : edges) {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (find(u) == find(v)) continue;
        unionn(u, v);
        totalCost += wt;
    }

    cout<<totalCost;
    
    return 0;
}