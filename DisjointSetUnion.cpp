
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
