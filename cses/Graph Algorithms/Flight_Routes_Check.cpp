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

    vector<vector<int>> adj(n), radj(n);
    while(m--) {
        int u, v; cin >> u >> v;
        adj[--u].push_back(--v);
        radj[v].push_back(u);
    }

    int cnt = 0;
    vector<int> order;
    vector<bool> vis(n, false);

    function<void(int)> topo = [&](int v) {
        vis[v] = true;
        for (auto &u: adj[v]) 
            if (!vis[u]) topo(u);

        order.push_back(v);
    };

    function<void(int)> scc = [&](int v) {
        cnt += vis[v] = true;
        for (auto &u: radj[v])
            if (!vis[u]) scc(u);
    };

    FOR(i, n) if (!vis[i]) topo(i); 
    vis.assign(n, false);
    scc(order.back());

    if (cnt != n) {
        cout << "NO\n";
        int fa = 0;
        while (vis[fa]) ++fa;

        cout << ++fa << ' ' << ++order.back()  << '\n';
    } else {
        cout << "YES\n";
    }
}
