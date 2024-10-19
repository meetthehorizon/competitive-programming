/*
Kshitij Sharma
github: meetthehorizon
     /\_/\
    (= ._.)  ~~meow~~
    / >  \>
*/

#include <bits/stdc++.h> 
using namespace std; 

#define int long long
#define MOD 1000000007
#define INF 10000000000000000
#define FOR(i, n) for (int i = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve(int);
bool test_cases = false;
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; if(test_cases) cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
    return 0;
}


void solve([[maybe_unused]] int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);

    vector<int> deg(n);
    FOR(i, m) {
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
        deg[x]++; deg[y]--;
    }

    deg.erase(unique(all(deg)), deg.end());
    if (deg != (decltype(deg)){1, 0, -1}) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> path;
    auto dfs = [&](int v, auto&& dfs) -> void {
        while (!adj[v].empty()) {
            int u = adj[v].back();
            adj[v].pop_back();

            dfs(u, dfs);
        }
        path.push_back(1+v);
    }; dfs(0, dfs);

    reverse(all(path));

    if (path.size() != m + 1 || path.back() != n) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (auto &v: path) cout << v << ' '; cout << '\n';
}
