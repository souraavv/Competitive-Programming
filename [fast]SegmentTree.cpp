#include <bits/stdc++.h>
using namespace std;
 
#define hey(x) cerr << #x << " : " << x << "\n";
#define int long long int
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int, int> >
#define vvpi vector<vector<pair<int, int> > >
#define all(v) (v).begin(), (v).end()   
#define rall(v) (v).rbegin(), (v).rend()
#define pii pair<int, int>
#define pb push_back
#define SZ(x) (int)(x).size()
#define inf 1e12
#define F first
#define S second
#define PI 3.1415926535897932384626
#define out cout << fixed << setprecision(12)
#define fill(v, val) memset((v), val, sizeof(v))
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define hey2(x, y) cerr << #x << " : " << x << "," << #y << " : " << y << '\n';
 
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);
 
void read(vi &a) {
    for(int &i : a) cin >> i;
}
void print(vi &a) {
    for(int i : a) cerr << i << ' ';
    cerr << "\n";
}
 
int seg[4 * N];
int n;
int opr(int a, int b) {
    return (a + b);
}
void build() {  
    for (int i = n - 1; i > 0; --i) 
      seg[i] = opr(seg[i<<1], seg[i<<1|1]);
}
 
void update(int p, int value) {  
    for (seg[p += n] += value; p > 1; p >>= 1) 
        seg[p>>1] = opr(seg[p], seg[p^1]);
}
 
int query(int l, int r) {  
  int res = 0; 
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) 
      res = opr(res, seg[l++]);
    if (r&1) 
      res = opr(res, seg[--r]);
  }
  return res;
}

int32_t main() {
    fast;
    
   
    return 0;   
}
