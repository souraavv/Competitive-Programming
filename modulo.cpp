
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

// compute all k^-i up to 0 <= i <= n;
// BAse case : k^-0 = k^0 = 1;
// k^-1 = modPow(k, m - 2);
// For rest k^-i = k^-1 * (k ^ -(i - 1));
// so if we value of cur = k^-(i - 1)) we can compute k^-i by multiplying k^(-(i - 1)) with k^-1;

long long k_inverse[n + 1];
k_inverse[0] = 1;
long long k_inv = mpow(k, m - 2), cur = 1;
for (int i = 1; i <= n; i++) {
  cur = (cur * k_inv) % m;
  k_inverse[i] = cur;
}
