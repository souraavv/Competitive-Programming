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

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);

void read(vi &a) {
    for(int &i : a) cin >> i;
}
void print(vi &a) {
    for(int i : a) cerr << i << ' ';
    cerr << "\n";
}

class SegmentTree {
public:
    SegmentTree(int count) {
        n = count;
        data = std::vector<int>(2 * n, 0);
    }

    SegmentTree(std::vector<int> const &values) {
        n = values.size();
        data = std::vector<int>(2 * n);
        std::copy(values.begin(), values.end(), &data[0] + n);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = opr(data[idx * 2], data[idx * 2 + 1]);
    }

    // write the operation : 
    int opr(int a, int b) {
        return 
    }
    void update(int idx, int value) {
        for(data[idx += n] = value; idx > 1; idx >> = 1 ) {
            data[idx >> 1] = opr(data[idx], data[idx ^ 1]);
        }
    }

    int query(int left, int right) { // interval [left, right)
        int ret = 0; // initialize it accordingly
        for(left += n, right += n; left < right; left >>= 1, right >>= 1){
            if (left & 1) 
              ret = opr(ret, data[left++]);
            if (right & 1) 
              ret = opr(ret, data[--right]);
        }
        return ret;
    }

private:
    int n;
    std::vector<int> data;
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // Warning 0 :If need to add to prev value then seg[p += n] += val; 
    // Warning 1 : [l, r) + 1 based value of l, r : 
    // Warning 2 : ask (l, r + 1) 0 index is not used to ask query : [1, r); 
    // Warning 3 : initial opration and ret in query accordingly;
    // Warning 4 : check in update whether need to add in previous value or new value
    
    // create segment tree instance
    SegmentTree st(n);

}
