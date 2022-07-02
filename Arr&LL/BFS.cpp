#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
vector<int> adj[N];

int main(){
    int x,y;
    cin>>x>>y;

        vector<int>  storedfs;
        vector<int> vis(x+1 , 0);

    for(int i=0; i<N;i++ )
        vis[i] =0;

        int n,m;
    for(int i=0;i<y;i++){
        cin>>n>>m;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vis[1]=true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<endl;

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
                
            }
        }
    }
}