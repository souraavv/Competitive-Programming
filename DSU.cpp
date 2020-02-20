#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(v) v.begin(), v.end()
#define f(i, l, n) for (int i = l; i < n; ++i)
#define pb push_back


vi p;
vi sz;

int find_set(int x){
    return x==p[x]?x:x=find_set(p[x]);
}

void union_set(int x,int y){
    x = find_set(x);
    y = find_set(y);
    if(x!=y){
        p[y]=x;
        sz[x]+=sz[y];
        sz[y]=0;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    p=vi(n+1);
    sz=vi(n+1,1);
    
    for(int i=1;i<=n;++i)p[i]=i;
    
    
    return 0;
}


/*

Problem: https://codeforces.com/contest/177/problem/C2
Solution : https://codeforces.com/contest/177/submission/70535832

*/
