#define ll long long

const int MOD = 1e9 + 7, N = 5e5 + 10;
const ll LINF = LLONG_MAX;
int fact[N];

ll modpow(ll x, ll y){
    ll ans=1;
    if(y==1){
        return x%MOD;
    }
    x=x % MOD;
    y=y % (MOD-1);
    while(y){
        if(y & 1){
            ans = (ans*x) %MOD;
        }
        x *= x;
        x = x % MOD;
        y >>= 1;
    }
    return ans % mod;
}
 
ll modinv(ll x){
    return modpow(x,MOD-2);
}

ll sub(ll x, ll y) {
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}

ll add(ll x, ll y) {
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}

ll multiply(int a,int b){
    return (a*b)%MOD;
}

ll nCr(int n, int r){
    return multiply(fact[n],multiply(modinv(fact[n-r]),modinv(fact[r])));
}

ll modinv2(int a){
  int b=MOD,p=1,q=0;
  while(b){
    int c=a/b,d=a;
    a=b;
    b=d%b;
    d=p;
    p=q;
    q=d-c*q;
  }
  return (p+MOD)%MOD;
}

void init(){
    fact[0]=1;
    for(int i = 1; i < N; ++i)
        fact[i]=multiply(fact[i-1],i);
}

int32_t main(){
    
    ios::sync_with_stdio(false):
    cin.tie(0);
    
    init();
    
    // continue;
    
    
    return 0;   
}
