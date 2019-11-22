#include<bits/stdc++.h>
using namespace std;
#define N 1000
vector<int>adj[N];
int in[N],out[N];

void dfs1(int u,int par){
    in[u]=0;
    for(int v:adj[u]){
        if(v==par)continue;
        dfs1(v,u);
        in[u]=max(in[u],1+in[v]);
    }
}

void dfs2(int u,int par){
    int mx1(-1),mx2(-1);
    for(int v:adj[u]){ 
        if(v==par)continue;//O(n)
        if(in[v]>=mx1)mx2=mx1,mx1=in[v];
        else if(in[v]>mx2)mx2=in[v];
        
    }
    // out[u]=max(1+out[par],2+use(maximum value that you can get from all in[v] of u))
    for(int v:adj[u]){
        if(v==par)continue;
        int use=mx1;
        if(in[v]==mx1)use=mx2;
        out[v]=max(2+use,1+out[u]);
        dfs2(v,u);
    }
    
    
}
int main(){
    
    int n;
    cin>>n;
    for(int i=1;i<n;++i){
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    
    
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;++i){
        int a=max(in[i],out[i]);
        cout<<a<<" ";
    }
    
}
