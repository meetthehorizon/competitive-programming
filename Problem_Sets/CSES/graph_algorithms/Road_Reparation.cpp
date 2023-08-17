/*
Kshitij Sharma
github: meetthehorizon
   /\_/\
  (= ._.)
  / >  \>
*/

#include <bits/stdc++.h> 
using namespace std; 

#define int long long
#define MOD 1000000007
#define INF 10000000000000000
#define FOR(i, n) for (size_t i = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve(int);
bool test_cases = false;
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; if(test_cases) cin >> t;
    for(size_t i = 1; i <= t; i++)
        solve(i);
    return 0;
}

struct DSU{
    int n;
    vector<int> par, rank;
    DSU(int n) : n(n) {
        par.resize(n);
        rank.assign(n, 1);
        iota(all(par), 0);
    }
    int find(int v) {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    int join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return u;
        if (rank[v] > rank[u]) swap(u, v);
        if (rank[u] == rank[v]) rank[u]++;
        par[v] = u;

        return u;
    }
};

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, m; cin >> n >> m;
    DSU cc(n+1);

    vector<array<int, 3>> edges;
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(all(edges));
    int ans = 0, cnt = 0;
    for (auto &e: edges) {
        if (cc.find(e[1]) == cc.find(e[2])) continue;
        ++cnt; ans += e[0];
        cc.join(e[1], e[2]);
    }

    if (cnt == n-1) cout << ans;
    else cout << "IMPOSSIBLE";
}
