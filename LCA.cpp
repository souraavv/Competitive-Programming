#include<bits/stdc++.h>
using namespace std;
#define LG 11
#define N 1024
int P[N][20];
int lvl[N];
vector<int>adj[N];

void dfs(int u,int par){
    P[u][0]=par;
    lvl[u]=1+lvl[par];
    for(int v:adj[u]){
        if(v==par)continue;
        dfs(v,u);
    }
}

int lca(int u,int v){
    if(lvl[u]<=lvl[v])swap(u,v);
    int lg;
    for(lg=0;lvl[u]>=(1<<lg);++lg);
    lg--;
    
    for(int i=lg;i>=0;--i){
        if(lvl[u]-(1<<i)>=lvl[v])
            u=P[u][i];
    }
    
    if(u==v)
      return u;
    
    for(int i=lg;i>=0;--i){
        if( P[u][i]!=-1 and P[u][i]!=P[v][i]){
            u=P[u][i],v=P[v][i];
        }
    }
    
    return P[u][0];
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
    for(int j=0;j<20;++j)for(int i=0;i<=n;++i)P[i][j]=-1;
    lvl[0]=-1;
    dfs(1,0);
    
    for(int i=1; i<LG; i++){
        for(int j=1;j<=n;++j)
            if (P[j][i-1] != -1)
                P[j][i] = P[P[j][i-1]][i-1];
	}

    
    
    cout<<lca(10,3);
    
}
