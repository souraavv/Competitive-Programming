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

int n;
class BIT {
    private: 
        int n;
        vector<int> bit;
    public: 
        BIT(vector<int> a){
            n = a.size();
            bit = vector<int>(n + 1, 0);
            // O(n) filling of BIT
            // copy(a.begin(),a.end(),bit.begin()+1);
            for(int i = 0; i < a.size(); ++i)
                bit[i + 1] = a[i];
            for(int idx = 1; idx <= n; ++idx){
                int idx1 = idx + (idx & -idx);
                if(idx1 <= n){
                    bit[idx1] += bit[idx];
                }
            }
        }
        // prefix_sum
        int query(int idx){
            int sum = 0;
            for(++idx; idx > 0;idx -= idx & -idx)
                 sum += bit[idx];
            return sum;
        }
        
        // add x to index i
        void add(int idx, int val){
            for(++idx; idx <= n; idx += idx & -idx)
                bit[idx] += val;
        }
        
        // [i,j] inclusive
        int rangeQuery(int i, int j){
            if(i == 0)
                return query(j);
            return (query(j) - query(i - 1));
        }
};

int32_t main(){
    fast;
    /* sample of working 
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    
    BIT b(a);
    
    cout<<b.rangeQuery(4,13)<<"\n";
    b.add(13,3);
    cout<<b.rangeQuery(4,13)<<"\n";
    */
    
    
    return 0;
    
}
