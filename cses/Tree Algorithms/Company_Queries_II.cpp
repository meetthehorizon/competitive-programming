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
    auto lg2 = [](int n) { return  n ? __builtin_clzll(1) - __builtin_clzll(n) : -1; };

    int n, q; cin >> n >> q;
    vector<vector<int>> adj(n);
    FOR(i, n-1) {
        int x; cin >> x;
        adj[--x].push_back(i+1);
    }

    vector<int> tin(n, -1), d(n);
    vector<int> euler; euler.reserve(n<<1);

    function<void(int)> dfs = [&](int v) -> void {
        tin[v] = euler.size();
        euler.push_back(v);
        
        for (auto u: adj[v])
        if (tin[u] == -1) {
            d[u] = d[v] + 1;
            dfs(u);
            euler.push_back(v);
        }
    }; dfs(0); 
    int sz = euler.size(), k = 20;

    auto mi = [&](int u, int v) {
        if (d[u] > d[v]) return v;
        return u;
    };

    vector<int> spa[k]; spa[0] = euler;
    for (int i = 1; i < k; ++i) {
        spa[i].resize(sz);

        for (int j = 0; j + (1 << i) <= sz; ++j)
            spa[i][j] = mi(spa[i-1][j], spa[i-1][j+(1<<(i-1))]);
    }

    while (q--) {
        int a, b; cin >> a >> b;
        int l = tin[--a], r = tin[--b];
        if (l > r) swap(l, r);
        int len = lg2(r-l+1);

        cout << mi(spa[len][l], spa[len][r-(1<<len)+1])+1 << '\n';
    }
}
