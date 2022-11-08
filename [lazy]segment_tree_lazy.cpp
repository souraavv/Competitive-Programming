#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define inf 1e16

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << "[";
    cout << vars << "] = [";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << "]\n";
}



struct node {
    // any attributes you want
    int mn;
    // int val, mx, xr;
    node() : mn(inf) {}; // for min
    // node() : mx(-inf) {}; // for max
    // node() : xr(0) {}: // for xor
    // node() : val(0) {}; // for sum
};

/*
 * sum ? 
 * xor ? 
 * min ? true
 * max ? true

 */
struct SegmentTree {
    int N;
    std::vector<node> st;
    std::vector<bool> clazy;
    std::vector<int> lazy;

    SegmentTree(int n) {
        N = n;
        st = vector<node> (4 * N + 5);
        clazy = vector<bool> (4 * N + 5, false);
        lazy = vector<int> (4 * N + 5, 0);
    }


    // change accordingly
    void merge(node& cur, node& left, node& right) {
        cur.mn = std::min(left.mn, right.mn);
	// cur.val = left.val + right.val;
    }
    
    void build(int u, int left, int right) {
        if (left == right) {
	    // note st is udpating u values (which is node idx, and left/right
	    // is the index from the array which we are updating.
            st[u].mn = inf; // set some default value
            return;
        }
        int mid = (left + right) / 2;
        build(2 * u, left, mid);
        build(2 * u + 1, mid + 1, right);
        merge(st[u], st[2 * u], st[2 * u + 1]);
    }
	
    void build(int u, int left, int right, vector<int>& values) {
	    if (left == right) {
		    // NOTE: u and left, u is node number, left is in the index in values.
		    st[u].mn = values[left];
            return;
	    }
	    int mid = (left + right) / 2;
	    build (2 * u, left, mid, values);
	    build (2 * u + 1, mid + 1, right, values);
	    merge(st[u], st[2 * u], st[2 * u + 1]);
    }
    // handle lazy prop.
    void propagate(int u, int left, int right) {
        if (left != right) {
            clazy[2 * u] = clazy[2 * u + 1] = true;
            lazy[2 * u] = lazy[u];
            lazy[2 * u + 1] = lazy[u];
        }
	// NOTE: st[u].mn
	// This is imp, this will surely 
	// update so +=, *=, min, max, xor
	// st[u].val = (Right - left + 1) * val;
	// and in case of range it contain
	// for xor it will be based on odd/even count
	// for sum it will right - left + 1 * val;
	// same for the product
	// for max and min it it simple
        st[u].mn = lazy[u];
	    lazy[u] = 0;
        clazy[u] = false;
    }
    // handle point-query
    node point_query(int u, int left, int right, int pos) {
        if (clazy[u]) {
            propagate(u, left, right);
        }
        if (left == right) {
            return st[u];
        }
        int mid = (left + right) / 2;
        if (pos <= mid) {
            return point_query(2 * u, left, mid, pos);
        }   
        else {
            return point_query(2 * u + 1, mid + 1, right, pos);
        }
    }
    // handle range-query
    node range_query(int u, int left, int right, int i, int j) {
        if (clazy[u]) {
            propagate(u, left, right);
        }
        // out of boud
        if (i > right || j < left) return node();
        // complete inside
        if (i <= left && right <= j) {
            return st[u];
        }
        int mid = (left + right) / 2;
        node leftChild = range_query(2 * u, left, mid, i, j);
        node rightChild = range_query(2 * u + 1, mid + 1, right, i, j);
        node cur;
        merge(cur, leftChild, rightChild);
        return cur;
    }
    // point-update
    void point_update(int u, int left, int right, int pos, int val) {
        // propagate...
	if (clazy[u]) {
            propagate(u, left, right);
        }
	// If can make lazy, make it & range is within boundary.
        if (left == right) {
            // ok this is the node, which I'm looking set and propagate.
            clazy[u] = true;
            lazy[u] = val;
            propagate(u, left, right);
            return;
	}
        int mid = (left + right) / 2;
        if (pos <= mid) {
            point_update(2 * u, left, mid, pos, val);
        }
        else {
            point_update(2 * u + 1, mid + 1, right, pos, val);
        }
        // send the result to the parent
        merge(st[u], st[2 * u], st[2 * u + 1]);
    }
    // range-udpate
    void range_update(int u, int left, int right, int i, int j, int val) {
        if (clazy[u]) {
            propagate(u, left, right);
        }
        if (left > j or right < i) return;
        if (i <= left && right <= j) {
            clazy[u] = 1;
            lazy[u] = val;
            propagate(u, left, right);
            return;
        }
        int mid = (left + right) / 2;
        range_update(2 * u, left, mid, i, j, val);
        range_update(2 * u + 1, mid + 1, right, i, j, val);
        merge(st[u], st[2 * u], st[2 * u + 1]);
    }

    void bulid() {
	    build(1, 0, N - 1);
    }
    void build(vector<int>& values) {
        build(1, 0, N - 1, values);
    }
    // over-loading
    node query(int pos) {
        return point_query(1, 0, N - 1, pos);
    }
    node query(int left, int right) {
        return range_query(1, 0, N - 1, left, right);
    }
    // for update
    void update(int pos, int val) {
        point_update(1, 0, N - 1, pos, val);
    }
    void update(int left, int right, int val) {
        range_update(1, 0, N - 1, left, right, val);
    }
};

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	int n = 5;
	SegmentTree st(n); // 0-based indexing, ensure because 0, n - 1 is the range node 1 contains.
	vector<int> values(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &values[i]);
	}
	st.build(values);
    // node ans = st.query(3, 3);
    cout << ans.mn << '\n';
	return 0;
}
