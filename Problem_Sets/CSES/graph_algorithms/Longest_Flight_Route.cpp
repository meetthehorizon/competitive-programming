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

    vector<int> dp(n, -1);
    function<int(int)> dfs = [&](int v) -> int {
    	if (dp[v] != -1) return dp[v];
    	if (v == n - 1) return dp[v] = 1;

    	dp[v] = -INF;
    	for (auto &u: adj[v]) {
    		dp[v] = max(dp[v], dfs(u));
    	}
    	return ++dp[v];
    }; 

    if (dfs(0) < 0) {
    	cout << "IMPOSSIBLE\n";
    	return;
    }

    vector<int> path;
    for (int v = 0; v != n - 1; ) {
    	path.push_back(v);
    	int x = adj[v][0];

    	for (auto &u: adj[v]) {
    		if (dp[u] > dp[x]) x = u;
    	}
    	v = x;
    }
    cout << path.size() + 1 << '\n';
    for (auto &d: path) cout << ++d << ' '; cout << n;
}