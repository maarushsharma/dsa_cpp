#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
vector<int> adj[N];
// bool vis[]; 

void dfs(int node , vector<int> &vis, vector<int> adj[], vector<int> &storedfs){
    storedfs.push_back(node);
    vis[node] =1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,storedfs);
        }
    }
}

int main(){
    int x,y;
    cin>>x>>y;

        vector<int>  storedfs;
        vector<int> vis(x+1 , 0);

    for(int i=0; i<N;i++ )
        vis[i] =0;

        int n,m;
    for(int i=0;i<x;i++){
        cin>>n>>m;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1;i<=x;i++){
        if(!vis[i]){
        dfs(i,vis,adj,storedfs);
        }
    }
    for(int i=0;i<storedfs.size();i++){
       cout<<storedfs[i];
    }
    
} 