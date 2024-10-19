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
    int n, cnt, mx;
    vector<int> par, sz;
    DSU(int n) : n(n), cnt(n), mx(1LL) {
        par.resize(n);
        sz.assign(n, 1);
        iota(all(par), 0);
    }
    int find(int v) {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    int join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return u;

        --cnt;
        if (sz[v] > sz[u]) swap(u, v);
        sz[u] += sz[v];
        mx = max(mx, sz[u]);
        par[v] = u;
        return u;
    }
};

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, m; cin >> n >> m;
    DSU cc(n);

    vector<array<int, 3>> edges;
    while(m--) {
        int u, v; cin >> u >> v;
        cc.join(--u, --v);
        cout << cc.cnt << ' ' << cc.mx << '\n';
    }

}   
