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
    int n; cin >> n;
    vector<vector<int>> adj(n);

    FOR(i, n-1) {
        int x, y; cin >> x >> y;
        adj[--y].push_back(--x);
        adj[x].push_back(y);
    }

    vector<int> dp1(n), dp2(n);
    vector<bool> vis(n, false);

    function<int(int)> dfs = [&](int v) {
        vis[v] = true;

        dp1[v] = 0, dp2[v] = 0;
        for (auto u: adj[v]) if (!vis[u]) {
            int x = dfs(u);
            dp1[v] += x;
            dp2[v] = max(dp2[v], dp1[u]+1-x);
        }

        dp2[v] += dp1[v];
        return max(dp1[v], dp2[v]);
    };

    dfs(0);
    cout << max(dp1[0], dp2[0]);
}
