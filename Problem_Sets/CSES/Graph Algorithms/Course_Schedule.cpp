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
 
    vector<int> col(n, 0), req(n, 0);
    while(m--) {
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
        req[y]++;
    }
 
    function<bool(int)> dfsc = [&] (int v) -> bool {
        col[v] = 1;
        for (auto &u: adj[v])
            if ((col[u] == 1) || (!col[u] && dfsc(u))) 
                return true;
        col[v] = 2;
        return false;
    };
 
    FOR(i, n) if (!col[i]) if (dfsc(i)) {
        cout << "IMPOSSIBLE\n";
        return;
    }
 
    queue<int> q;
    FOR(i, n) if (!req[i]) q.push(i);
 
    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << v + 1 << ' ';
 
        for (auto &u: adj[v]) {
            req[u]--;
            if (!req[u]) q.push(u);
        }
    }
}   