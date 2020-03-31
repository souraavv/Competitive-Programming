#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;

vector<pair<int,int> > g[N],tree[N];
bool vis[N];
int dist[N],parent[N];

int primsMST(int source){
    
   
    for(int i=1;i<=n;++i)
        dist[i]=1e18;
        
    set<pair<int,int> > s;
    s.insert({0,source});
    int cost=0;
    dist[source]=0;
    
    while(!s.empty()){
        auto it=*(s.begin());
        s.erase(it);
        int v=it.second;
        int w=it.first;
        int u=parent[v];
        if(vis[v])
            continue;
        
        vis[v]=1;
        cost+=w;
        tree[v].pb({u,w});
        tree[u].pb({v,w});
        
        for(auto child: g[v]){
            if(vis[child.first])
                continue;
            
            if(dist[child.first]>child.second){
                s.erase({dist[child.first],child.first});
                dist[child.first]=child.second;
                s.insert({dist[child.first],child.first});
                parent[child.first]=v;
            }
        }
    }
    return cost;
}



// Problem: https://codeforces.com/contest/609/problem/E
