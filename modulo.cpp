
// computing factorial upto n in O(n).

long long fact[n + 1];
fact[0] = fact[1] = 1;
for (int i = 2; i <= n; i++) {
  fact[i] = (fact[i - 1] * i) % m;
}

// b^-1 = (b^(m - 2)) % mod;
// So ifact[n] = modPow(fact[n], m - 2);

// ((n - 1)!)^-1 = n.(n!)^-1 , multiply and divide n 
// This we will use to compute inverse of fact[n - 1] i.e ifact[n - 1] from ifact[n]. 

long long ifact[n + 1];
ifact[n] = mpow(fact[n], m - 2);

for (int i = n - 1; i >= 0; i--) {
  ifact[i] = ((i + 1) * ifact[i + 1]) % m;
}

// computing all i^-1 up to n^-1 in O(n)
// Using the fact n^-1 = (n - 1)! / (n)! = (fact[n - 1] * ifact[n]) % mod;


long long inverse[n + 1];
for (int i = 1; i <= n; i++) {
  inverse[i] = (fact[i - 1] * ifact[i]) % m;
}
