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
    
    vector<int> degree(n), path;        
    vector<bool> seen(m, false);
    vector<vector<pair<int, int>>> adj(n);

    FOR(i, m) {
        int x, y; cin >> x >> y;
        --x, --y;
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
        degree[x]++;
        degree[y]++;
    }

    if (count_if(all(degree), [](int x) {return x&1;})) {
        cout << "IMPOSSIBLE\n";
        return;
    }   

    function<void(int)> dfs = [&](int v) -> void {
        while (!adj[v].empty()) {
            auto [son, idx] = adj[v].back();
            adj[v].pop_back();

            if (seen[idx]) continue;
            seen[idx] = true;
            dfs(son);
        }

        path.push_back(v);
    };
    dfs(0);

    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (auto &v: path) {
            cout << ++v << ' ';
        }
    }

}
