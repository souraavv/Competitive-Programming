#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
int n;
const int N = 2e5+5;
vector<int> g[N];
int parent[N];


void make_set(){
    for(int i=1;i<=n;++i)parent[i]=i;
}

int find_set(int x){
    if(x==parent[x])return x;
    return parent[x]= find_set(parent[x]); //optimization
}

void union_set(int x,int y){
    x = find_set(x);
    y = find_set(y);
    // make either parent of y to x or other way round : we can use size optimization
    parent[y]=x;
}

void dfs(int u){
    cout<<u<<" ";
    for(int v: g[u])dfs(v);
}

int32_t main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int x,y;
    cin>>n;
   
    make_set();

    for(int i=0;i<n-1;++i){
        cin>>x>>y;
        union_set(x,y);
        g[x].push_back(y);
    }
    
}
