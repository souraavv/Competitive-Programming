#include<stdio.h>
const int N = 1e5;  
int n;  
int t[2 * N];

void build() {  
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
 // modify(0, 1);
  int l,r;
  printf("%d\n", query(0,2)); // = a[0]+a[1] [l,r) and 0 base indexing;
  return 0;
}



/*
// for minimum in a range;
void build() {  
  for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1] ,t[i<<1|1]);
}
int query(int l, int r) {  
  int res = INT_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res =min(res,t[l++]);
    if (r&1) res =min(res, t[--r]);
  }
  return res;
}
*/
