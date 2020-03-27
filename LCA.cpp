#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define f(i, l, n) for (int i = l; i < n; ++i)
#define pb push_back


const int N=1e5;
int Par[N][20];
vi lvl;
vvi g;

void dfs(int u,int par){
    Par[u][0]=par;
    lvl[u]=1+lvl[par];
    for(int v: g[u]){
        if(v!=par){
            dfs(v,u);
        }
    }
}

int lca(int u,int v){
    if(lvl[u]<=lvl[v])swap(u,v);
    
    int jump;
    for(jump=0;(lvl[u]>=(1<<jump));++jump);
    jump--;
    
    for(int i=jump;i>=0;--i){
        if(lvl[v]<=lvl[u]-(1<<i))u=Par[u][i];
    }
    
    if(u==v)return u;

    for(int i=jump;i>=0;--i){
        if(Par[u][i]!=-1 and Par[u][i]!=Par[v][i]){
            u=Par[u][i],v=Par[v][i];
        }
    }
    
    return Par[u][0];
    
}


int dist(int a,int b){
    return(lvl[a]+lvl[b]-2*lvl[lca(a,b)]);
}

int32_t main(){
    
    int n;
    cin>>n;
    g=vvi(n+1);
    lvl=vi(n+1,0);
    for(int i=0;i+1<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    for(int i=1;i<=n;++i)for(int j=0;j<20;++j)Par[i][j]=-1;
    
    lvl[0]=-1;
    dfs(1,0);
    
    for(int i=1;i<=n;++i){
        for(int j=1;j<20;++j){
            if(Par[i][j-1]!=-1)Par[i][j]=Par[Par[i][j-1]][j-1];
        }
    }
    cout<<lca(8,4)<<"\n";
    cout<<dist(8,4);
    return 0;
}

/*

Sample Tree: 
8
1 2
1 3
1 4
2 5
2 6
6 7
7 8

Sample Problem: 

Problem list: https://www.codechef.com/LTIME77A/problems/DDQUERY

Problem : https://codeforces.com/contest/1328/problem/E

*/
