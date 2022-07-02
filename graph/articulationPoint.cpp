#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent , int &timer , vector<int> &low , vector<int> &disc ,
 unordered_map<int,bool> &vis , vector<int> &ans,unordered_map<int,list<int>> &adj){
    vis[node] = true;
    low[node] = disc[node] = timer++;
    int child=0;

    for(auto nbr : adj[node]){
        if(nbr == parent){
            continue;
        }

        if(!vis[nbr]){
            dfs(nbr,node,timer,low,disc,vis,ans,adj);
            //if updated mini then update
            low[node] = min(low[node],low[nbr]);
            //check ap
            if(low[nbr] >= disc[node] && parent != -1){
                ans[node] = 1;
            }
            child++;
        }else{
            low[node]= min(low[node] , disc[nbr]);
        }

        if(parent == -1 and child > 1){
            ans[node] = 1;
        }
    }
}

int main(){

    int n=5;
    int e = 5;
    vector<pair<int,int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> vis;
    vector<int> disc(n);
    vector<int> low(n);
    int parent = -1;
    int timer = 0;
    vector<int>  result(n,0);

    for(int i=0;i<n;i++){
        disc[i] = -1;
        low[i] = -1;
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,parent,timer,low,disc,vis,result,adj);
        }
    }

    cout<<"The articulation Points are as follows"<<endl;

    for(int i=0;i<n;i++){
        if(result[i] != 0)
        cout<<i<<" ";
    }cout<<endl;

    return 0;

}