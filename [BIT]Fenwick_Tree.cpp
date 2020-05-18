
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int bit[N];
int n;

void add(int idx, int val) {
  for (++idx; idx <= n; idx += idx & -idx)
    bit[idx] += val;
}

int query(int idx) {
  int sum = 0;
  for (++idx; idx > 0; idx -= idx & -idx)
    sum += bit[idx];
  return sum;
}

int range_query(int i, int j) {
  if (i == 0)
    return query(j);
  else
    return query(j) - query(i - 1);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    add(i, a);
  }
}



/* ----------------------------------------------------------------------------- */

struct BIT
{
	int N;
	vector<int> bit;

	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] += val;
			idx += idx & -idx;
		}
	}

	void updateMax(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int pref(int idx)
	{
		int ans = 0;
		while(idx > 0)
		{
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r)
	{
		return pref(r) - pref(l - 1);
	}

	int prefMax(int idx)
	{
		int ans = -2e9;
		while(idx > 0)
		{
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};
