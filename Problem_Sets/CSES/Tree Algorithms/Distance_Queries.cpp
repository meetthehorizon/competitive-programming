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


void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    auto lg2 = [](int n) { return 20; };
    int n, q; cin >> n >> q;
    vector<vector<int>> adj(n);

    FOR(i, n-1) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    int timer;
    vector<int> tin(n), tout(n), d(n);
    vector<vector<int>> spa(lg2(n)+1, vector<int> (n));
    function<void(int, int)> dfs = [&](int v, int p) -> void {
        tin[v] = timer++;

        spa[0][v] = p;
        for (int i = 1; i < spa.size(); ++i)
            spa[i][v] = spa[i-1][spa[i-1][v]];

        for (int u: adj[v]) 
            if (u != p) {
                d[u] = d[v] + 1;
                dfs(u, v);
            }

        tout[v] = timer++;
    }; dfs(0, 0);

    auto anc = [&](int u, int p) {
        return tin[p] <= tin[u] && tout[u] <= tout[p];
    };

    auto lca = [&](int u, int v) {
        if (anc(u, v)) return v;
        if (anc(v, u)) return u;

        for (int i = spa.size() - 1; i >= 0; --i) {
            if (!anc(v, spa[i][u]))
                u = spa[i][u];
        }
        return spa[0][u];
    };

    while (q--) {
        int a, b; cin >> a >> b;
        cout << d[--a] + d[--b] - 2 * d[lca(a, b)] << '\n';
    }
}
