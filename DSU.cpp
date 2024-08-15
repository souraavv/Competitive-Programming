/*
 * e[x] - Captures two information at the same time based on the sign (< 0) or (>= 0)
 *   - if e[x] < 0 : Then x represent the parent of a component and -e[x] represent the size of the component
 *   - if e[x] >= 0 : x is a part of some component and x is not root in that component; where e[x] is the parent of x
 */
class UF {
    public :
        UF(int count) {
            n = count;
            e = vi(n, -1);
        }
        bool same_set(int a, int b) {
            return find(a) == find(b);
        }
        int size(int x) {
            return -e[find(x)];
        }
        int find(int x) {
            return e[x] < 0 ? x : e[x] = find(e[x]);
        }
        bool join(int a, int b) {
            a = find(a), b = find(b);
            if(a == b)
                return false;
            if(e[a] > e[b]) swap(a, b); 
            e[a] += e[b];
            e[b] = a;
            return true;
        }
    private :
        int n;
        vector<int> e;
};
