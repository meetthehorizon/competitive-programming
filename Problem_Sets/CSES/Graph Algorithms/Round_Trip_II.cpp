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
 
    while(m--) {
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
    }
 
    int timer = 0;
    vector<int> tin(n, -1), tout(n, -1), par(n, -1);
 
    function<int(int)> dfs = [&](int v) -> int {
        tin[v] = timer++;
 
        for (auto &u: adj[v]) {
            if (tin[u] == -1) {
                par[u] = v;
                int res = dfs(u);
                if (res != -1) return res;
            } else {
                if (tout[u] == -1) {
                    return par[u] = v;  
                }
            }
        }
 
        tout[v] = timer++;
        return -1;
    };
        
    int c = -1;
    FOR(i, n) if (tin[i] == -1) {
        c = dfs(i);
        if (c != -1) break;
    }
 
    if (c == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle{c};
        while (par[cycle.back()] != cycle[0])
            cycle.push_back(par[cycle.back()]);
 
        reverse(all(cycle));
        cycle.push_back(cycle[0]);
 
        cout << cycle.size() << '\n';
        for (auto &c: cycle) cout << ++c << ' ';
    }
}