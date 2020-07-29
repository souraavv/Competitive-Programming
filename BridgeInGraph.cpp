#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> g[N];
vector<int> vis;

static int t = -1;
vector<int> tin;
vector<int> low_anc;

void dfs(int u, int par)
{
    low_anc[u] = tin[u] = ++t;
    vis[u] = 1;
    for (auto v : g[u]) {
        if (v == par)
            continue;
        if (vis[v]) {
            low_anc[u] = min(low_anc[u], tin[v]);
            continue;
        }
        dfs(v, u);
        low_anc[u] = min(low_anc[v], low_anc[u]);
        if (low_anc[v] > tin[u])
            cout << u << " " << v << "\n";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vis.resize(n + 1, 0);
    tin.resize(n + 1, -1);
    low_anc.resize(n + 1, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i, 0);
    return 0;
}
