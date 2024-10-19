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
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    FOR(i, n-1) {
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }

    int timer = 0;
    vector<int> spa[25], tin(n), tout(n);
    fill_n(spa, 25, vector<int> (n));

    function<void(int, int)> dfs = [&](int v, int p) -> void {
        tin[v] = timer++;
        spa[0][v] = p;
        for (int i = 1; i < 25; ++i)
            spa[i][v] = spa[i-1][spa[i-1][v]];

        for (auto u: adj[v]) 
            if (u != p) 
                dfs(u, v);

        tout[v] = timer++;
    }; dfs(0, 0);

    auto anc = [&](int v, int p) {
        return tin[p] <= tin[v] && tout[v] <= tout[p];
    };

    auto lca = [&](int u, int v) {
        if (anc(u, v)) return v;
        if (anc(v, u)) return u;

        for (int i = 24; i >= 0; --i) {
            if (!anc(v, spa[i][u])) 
                u = spa[i][u];
        }

        return spa[0][u];
    };

    vector<int> pre(n);
    while(m--) {
        int a, b; cin >> a >> b;
        pre[--a]++, pre[--b]++;
        int c = lca(a,  b);

        pre[c]--;
        if (c) pre[spa[0][c]]--;
    }

    function<int(int, int)> cal = [&](int v, int p) -> int {
        for (auto u: adj[v]) 
            if (u != p) {
                pre[v] += cal(u, v);
            }
        return pre[v];
    }; cal(0, 0);

    for (auto &e: pre) cout << e << ' ';
}
