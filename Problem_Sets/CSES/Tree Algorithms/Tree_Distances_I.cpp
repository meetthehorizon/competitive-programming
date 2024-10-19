/*
Kshitij Sharma
github: meetthehorizon
     /\_/\
    (= ._.)  ~~meow~~
    / >  \>
*/

#include <bits/stdc++.h> 
using namespace std; 

#define int          long long
#define MOD          1000000007
#define INF          10000000000000000
#define all(x)       (x).begin(), (x).end()
#define rall(x)      (x).rbegin(), (x).rend()
#define FOR(i, n)    for (int i = 0; (i) < (n); (i)++)

void solve(int);
bool test_cases = false;
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; if (test_cases) cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}


void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n; cin >> n;
    vector<vector<int>> adj(n);
    FOR(i, n-1) {
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }

    vector<pair<int, int>> dis[2];
    dis[0].assign(n, {0, -1});
    dis[1].assign(n, {0, -1});

    auto dfs = [&](int v, int p, auto&& dfs) -> pair<int, int> {
        for (auto u: adj[v]) if (u != p) {
            auto d = dfs(u, v, dfs);
            if (d > dis[0][v]) swap(d, dis[0][v]);
            if (d > dis[1][v]) swap(d, dis[1][v]);
        }
        return {dis[0][v].first + 1, v};
    }; dfs(0, -1, dfs);

    auto dfs2 = [&](int v, int p, auto&& dfs2) -> void {
        for (auto u: adj[v]) if (u != p) {
            FOR(i, 2) if (u != dis[i][v].second) {
                auto x = dis[i][v]; x.first++;
                if (x > dis[0][u]) swap(x, dis[0][u]);
                if (x > dis[1][u]) swap(x, dis[1][u]);
            }
            dfs2(u, v, dfs2);
        }
    }; dfs2(0, -1, dfs2);

    FOR(i, n) cout << dis[0][i].first << ' '; cout << '\n';
}
