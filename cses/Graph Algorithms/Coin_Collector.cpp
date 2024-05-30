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


template<typename Graph, typename SCC>
int Kosaraju(int n, SCC& scc, Graph& sadj, const Graph& adj, const Graph& radj) {
    int cc = 0;
    vector<int> order;
    vector<bool> vis(n, false);

    function<void(int)> dfs = [&](int v) -> void {
        vis[v] = true;
        for (auto u: adj[v])
            if (!vis[u]) dfs(u);
        order.push_back(v);
    };

    FOR(i, n) if (!vis[i]) dfs(i);
    reverse(all(order));
    scc.resize(n, -1);

    function<void(int)> dfs2 = [&](int v) -> void {
        scc[v] = cc;
        for (auto u: radj[v])
            if (scc[u] == -1)
                dfs2(u);
            else if (scc[u] != scc[v])
                sadj[scc[u]].push_back(scc[v]);
    };

    for (auto v: order) if (scc[v] == -1) {
        sadj.push_back({});
        dfs2(v); ++cc;
    }

    return sadj.size();
}

template<typename Container>
Container TopoSort(int n, const vector<Container>& adj) {
    Container order;
    vector<bool> vis(n, false);

    function<void(int)> dfs = [&](int v) -> void {
        vis[v] = true;
        for (auto u: adj[v]) 
            if (!vis[u]) dfs(u);
        order.push_back(v);
    };

    FOR(i, n) if (!vis[i]) dfs(i);
    reverse(all(order));
    return order;
}

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, m; cin >> n >> m;
    vector<int> vec(n); for (auto &v: vec) cin >> v;

    vector<vector<int>> adj(n), radj(n);
    while(m--) {
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
        radj[y].push_back(x);
    }

    vector<int> scc;
    vector<vector<int>> sadj;
    int cc = Kosaraju(n, scc, sadj, adj, radj);

    vector<int> val(cc);
    FOR(i, n) val[scc[i]] += vec[i];

    vector<int> dag = TopoSort(cc, sadj);
    vector<bool> vis(cc, false);

    function<void(int)> cal = [&](int v) -> void {
        vis[v] = true;
        int mx = 0;
        for (auto u: sadj[v]) {
            if (!vis[u]) cal(u);
            mx = max(mx, val[u]);
        }
        val[v] += mx;
    };

    for (auto &d: dag) if (!vis[d]) cal(d);
    cout << *max_element(all(val));
}
