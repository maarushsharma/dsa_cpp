#include <vector>
#include <stack>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdges(int u, int v, int w)
    {
        pair<int, int> p = {v, w};
        adj[u].push_back(p);
    }

    void printDAG()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &topo)
    {
        vis[node] = true;

        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                dfs(it.first, vis, topo);
            }
        }

        topo.push(node);
    }

    void getSortestPath(int src, vector<int> &dist, stack<int> &s)
    {
        dist[src] = 0;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if (dist[top] != INT_MAX)
            {
                for (auto it : adj[top])
                {
                    if (dist[top] + it.second < dist[it.first])
                        dist[it.first] = dist[top] + it.second;
                }
            }
        }
    }
};

int main()
{
    graph g;
    g.addEdges(0, 1, 5);
    g.addEdges(0, 2, 3);
    g.addEdges(1, 2, 2);
    g.addEdges(1, 3, 6);
    g.addEdges(2, 3, 7);
    g.addEdges(2, 4, 4);
    g.addEdges(2, 5, 2);
    g.addEdges(3, 4, -1);
    g.addEdges(4, 5, -2);

    g.printDAG();

    int n = 6;
    unordered_map<int, bool> vis;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            g.dfs(i, vis, s);
        }
    }

    int src = 1;
    vector<int> dist(n);

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    g.getSortestPath(src, dist, s);

    cout << "answer is:" << endl;

    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }cout<<endl;


    return 0;
}