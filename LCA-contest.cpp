#include <bits/stdc++.h>
using namespace std;

#define print(x) cerr << #x << " is " << x << endl;
#define int long long int
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define pb push_back

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

vi g[N];
int u, v;

int dp[N][25];
int lvl[N];

void dfs(int u,int par){
    dp[u][0]=par;
    lvl[u]=lvl[par]+1;
    
    for(int i=1;i<=20;++i)
        if(dp[u][i-1])
            dp[u][i]=dp[dp[u][i-1]][i-1];
    
    for(int v: g[u]){
        if(v!=par){
            dfs(v,u);
        }
    }
}



int lca(int u,int v){
    
    if(lvl[u]<lvl[v])
        swap(u,v);
    
    for(int i=20;~i;--i)
        if(lvl[u]-(1<<i)>=lvl[v])
            u=dp[u][i];
    
    if(u==v)
        return u;
    
    for(int i=20;~i;--i)
        if(dp[u][i]^dp[v][i])
            u=dp[u][i],v=dp[v][i];
        
    return dp[u][0];
}


int32_t main()
{    
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int n;
    cin>>n;
    
    for(int i=0;i+1<n;++i){
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    
    memset(dp,-1,sizeof(dp));
    lvl[0]=-1;
    dfs(1,0);
    
    /* ---------------write code below---------------------------- */
    
 
 
   
   
    return 0;
}
