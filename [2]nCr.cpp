#include<bits/stdc++.h>

using namespace std;
#define int long long int

const int mod = 1e9L + 7;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1)res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

inline int inv(int x) {
    return power(x, mod - 2);
}


int32_t main(){

    vector<int> fact(100123), rfact(100123);
    fact[0] = 1;
    for (int i = 1; i < 100123; ++i) fact[i] = i * fact[i - 1] % mod;
    rfact[100122] = inv(fact[100122]);
    for (int i = 100121; i >= 0; --i) rfact[i] = (i + 1) * rfact[i + 1] % mod;

    auto ncr = [&](int n, int r) -> int {
        return fact[n] * rfact[n - r] % mod * rfact[r] % mod;
    };
    
    
    
}

