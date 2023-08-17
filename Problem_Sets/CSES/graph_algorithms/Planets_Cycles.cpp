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
    vector<vector<int>> radj(n);
    vector<int> vec(n), root(n, -1), dis(n, -1);

    FOR(i, n) {
        int x; cin >> x;
        vec[i] = --x;
        radj[x].push_back(i);
    }

    function<void(int)> dfs = [&](int v) -> void {
        for (auto u: radj[v]) if (dis[u] == -1){
            dis[u] = dis[v] + 1;
            root[u] = root[v];
            dfs(u);
        }
    };

    auto floyd = [&](int v) {
        int x = v, sz = 0;
        do {
            v = vec[v];
            x = vec[vec[x]];
        } while(x != v);

        do {
            dis[v] = sz--;
            v = vec[v];
        } while (v != x);

        sz *= -1;
        do {
            dis[v] += sz;
            root[v] = v;
            v = vec[v];
        } while (v != x);

        dis[v] = 0;
        do {
            dfs(v);
            root[v] = -sz;
            v = vec[v];
        } while(v != x);
    };

    FOR(i, n) if (dis[i] == -1) floyd(i);

    for (int i = 0; i < n; ++i) {
        int ans = 0;
        if (root[i] >= 0) ans += dis[i] - dis[root[i]];
        ans -= root[i] < 0 ? root[i] : root[root[i]];

        cout << ans << ' ';
    }
}
 