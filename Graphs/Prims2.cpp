#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e7+10;
vector<pair<int,int>> graph[N];
vector<int> distanceArr(N, INF);
vector<int> parent(N, -1);
bool visited[N];

struct Queue
{
    int f;
    int r;
    pair<int, int> arr[N];
    Queue()
    {
        f = r = -1;
    }
};

int empty(Queue *q)
{
    return (q->f == -1 && q->r == -1);
}

pair<int, int> deQueueFront(Queue *q)
{
    if (empty(q))
    {
        cout << "Empty" << endl;
        return {-1, -1};
    }
    if (q->f == q->r)
    {
        pair<int, int> val = q->arr[q->f];
        q->f = -1;
        q->r = -1;
        return val;
    }
    else
    {
        pair<int, int> val = q->arr[q->f];
        q->f += 1;
        return val;
    }
}

void enQueue(Queue *q, pair<int, int> val)
{
    if (empty(q))
    {
        // cout<<"Here "<<val<<endl;
        q->f = 0;
        q->r = 0;
        q->arr[q->f] = val;
    }
    else
    {
        int i = q->r;
        int j = i + 1;
        bool flagI = true;
        bool flagJ = true;
        while (j != q->f && q->arr[i] > val)
        {
            q->arr[j] = q->arr[i];
            i--;
            j--;
        }
        q->arr[j] = val;
        q->r = q->r + 1;
    }
}


void Prims(int source)
{
    Queue* s = new Queue();
    distanceArr[source] = 0;
    enQueue(s,{0, source});
    while (!empty(s))
    {
        auto current = deQueueFront(s);
        int weightCurrent = current.first;
        int vertex = current.second;
        visited[vertex] = true;
        for (auto child : graph[vertex])
        {
            int childVertex = child.first;
            int childWeight = child.second;
            if (childWeight < distanceArr[childVertex] && !visited[childVertex])
            {
                distanceArr[childVertex] = childWeight;
                parent[childVertex] = vertex;
                enQueue(s,{distanceArr[childVertex], childVertex});
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
        sum += distanceArr[i];
    }
    cout<<sum<<endl;


    return 0;
}