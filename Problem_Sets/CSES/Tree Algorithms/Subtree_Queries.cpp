#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(void) {
    int n, q; cin >> n >> q;
    vector<vector<int>> adj(n);

    vector<int> vec(n); for (auto &v: vec) cin >> v;
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin >> u >> v;
        adj[--v].push_back(--u);
        adj[u].push_back(v);
    }    

    int timer = 0;
    vector<int> bit(n<<1);
    vector<int> tin(n), tout(n);

    auto upd = [&](int idx, int del) {
        for (; idx < (n<<1); idx = idx | (idx + 1)) {
            bit[idx] += del;
        }
    };

    auto psum = [&](int idx) {
        int val = 0;
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            val += bit[idx];
        }
        return val;
    };

    function<void(int, int)> dfs = [&](int v, int p) -> void {
        tin[v] = timer++;

        upd(tin[v], vec[v]);
        for (auto u: adj[v])
            if (u != p) dfs(u, v);
        tout[v] = timer++;
    }; dfs(0, 0);

    while(q--) {
        int type; cin >> type;
        if (type == 1) {
            int v, x; cin >> v >> x;
            --v;
            upd(tin[v], -vec[v]);
            vec[v] = x;
            upd(tin[v], vec[v]);
        } else {
            int v; cin >> v;
            cout << psum(tout[--v]) - psum(tin[v] - 1) << '\n';
        }
    }

}
