#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
bool visited[N];
vector<int> vertices[N];
static int level[N];

struct Queue
{
    int front, rear;
    int arr[N];
    Queue() {
        front = rear = -1;
    }
};

int isEmpty(Queue *q)
{
    return ((q->front == q->rear) && (q->front == -1 && q->rear == -1));
}

void push(Queue *q, int x)
{
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = x;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = x;
    }
}


int front(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty 1" << endl;
        return -1;
    }
    else
    {
        int returnValue = q->arr[q->front];
        return returnValue;
    }
}

void pop(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty 2" << endl;
    }
    else
    {
        q->front++;
        // cout<<q->front<<" "<<q->rear<<endl;
        if (q->front > q->rear)
        {
            // cout<<"Here ";
            q->front = -1;
            q->rear = -1;
        }
    }
}

void bfs(int source)
{
    Queue* q = new Queue();
    push(q, source);
    visited[source] = true;

    while (!isEmpty(q))
    {
        int outVal = front(q);
        pop(q);
        // cout<<q->front<<" "<<q->rear<<endl;
        cout<<outVal<<" ";
        for (int child : vertices[outVal])
        {
            if (!visited[child])
            {
                push(q,child);
                level[child] = level[outVal] + 1;
                visited[child] = true;
            }
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

    bfs(0);
    cout<<endl;
    for (int i = 1; i <= vertex; i++)
    {
        cout<<i<<" node has level  "<<level[i]<<endl;
    }

    return 0;
}