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
#define fill(v, val) memset((v), val, sizeof(v))
#define PI 3.1415926535897932384626
#define out cout << fixed << setprecision(12)
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define hey2(x, y) cerr << #x << " : " << x << "," << #y << " : " << y << '\n';

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);

vi p, sz;

void read(vi &a) {
    for(int &i : a)
        cin >> i;
}
void print(vi &a) {
    for(int i : a)
        cout << i << ' ';
}


int find_set(int x){
    return x == p[x] ? x : x = find_set(p[x]);
}

void union_set(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if(x != y){
        p[y] = x;
        sz[x] += sz[y];
        sz[y] = 0;
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // Initialization part : 
    int n;
    cin >> n;
    p = vi(n + 1);
    sz = vi(n + 1,1);
    for(int i = 1;i <= n; ++i)
        p[i] = i;
   
    // code below.
    return 0;
}