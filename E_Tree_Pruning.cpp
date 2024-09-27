/*
Kshitij Sharma
github: meetthehorizon
     /\_/\
    (= ._.)  ~~hoi~~
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
bool test_cases = true;
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

    vector<int> par(n);
    map<int, vector<int>> dtv;

    auto getDepth = [&](int v, int p, int d, auto&& getDepth) -> void {
        dtv[d].push_back(v);
        par[v] = p;
        for (auto &u: adj[v]) if (u != p) {
            getDepth(u, v, d + 1, getDepth);
        }
    };
    getDepth(0, -1, 1, getDepth);

    int ans = n-1;
    for (auto &itr: dtv) {
        int d = itr.first;
        set<int> s; s.insert(0);

        for (auto &v: itr.second) {
            while (!s.count(v)) {
                s.insert(v);
                v = par[v];
            }
        }

        ans = min(ans, n - (int)s.size());
    }

    cout << ans << '\n';
}

