
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

void read(vi &a) {
	for(int &i : a)
		cin >> i;
}

void print(vi &a) {
	for(int i : a)
		cout << i << ' ';
}

const ll LINF = LLONG_MAX;
int fact[N];

ll modpow(ll x, ll y){
    ll ans=1;
    if(y==1){
        return x%mod;
    }
    x=x % mod;
    y=y % (mod-1);
    while(y){
        if(y & 1){
            ans = (ans * x) %mod;
        }
        x *= x;
        x = x % mod;
        y >>= 1;
    }
    return ans % mod;
}
 
ll modinv(ll x){
    return modpow(x, mod - 2);
}

ll sub(ll x, ll y) {
    x -= y;
    if (x < 0) return x + mod;
    return x;
}

ll add(ll x, ll y) {
    x += y;
    if (x >= mod) return x - mod;
    return x;
}

ll multiply(int a,int b){
    return (a*b)%mod;
}

ll nCr(int n, int r){
    return multiply(fact[n], multiply(modinv(fact[n - r]), modinv(fact[r])));
}

ll modinv2(int a){
  int b = mod,p = 1,q = 0;
  while(b){
    int c = a / b, d = a;
    a = b;
    b = d % b;
    d = p;
    p = q;
    q = d - c * q;
  }
  return (p + mod) % mod;
}

void init(){
    fact[0] = 1;
    for(int i = 1; i < N; ++i)
        fact[i] = multiply(fact[i - 1], i);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // Initilization
    init();
    
    // code below.
    
    
    return 0;   
}
