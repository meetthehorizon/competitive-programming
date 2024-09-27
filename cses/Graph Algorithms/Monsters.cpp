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

void bfs(int m, vector<char>& grid, vector<int>& src, vector<int>& d, vector<bool>& vis, vector<int>& p) {
    int n = grid.size() / m;
    queue<int> q;
    for (auto &s: src) q.push(s), d[s] = 0, vis[s] = true;

    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (grid[v] == '#') {vis[v] = false;  continue; }

        vis[v] = true;
        if (v % m != m-1 && !vis[v+1]) q.push(v+1), d[v+1] = d[v] + 1, p[v+1] = v, vis[v+1] = true;
        if (v % m != 0 && !vis[v-1]) q.push(v-1), d[v-1] = d[v] + 1, p[v-1] = v, vis[v-1] = true;
        if (v / m != n-1 && !vis[v+m]) q.push(v+m), d[v+m] = d[v] + 1, p[v+m] = v, vis[v+m] = true;
        if (v / m != 0 && !vis[v-m]) q.push(v-m), d[v-m] = d[v] + 1, p[v-m] = v, vis[v-m] = true;
    }
}

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, m; cin >> n >> m;
    vector<char> grid(n*m);
    FOR(i, n*m) cin >> grid[i];

    int s = find(grid.begin(), grid.end(), 'A') - grid.begin();

    vector<int> per { s }, mon;
    FOR(i, n*m) if (grid[i] == 'M') mon.push_back(i);

    vector<int> pp(n*m), pm(n*m);
    vector<int> dp(n*m, -1), dm(n*m, -1);
    vector<bool> vp(n*m), vm(n*m);

    bfs(m, grid, per, dp, vp, pp);
    bfs(m, grid, mon, dm, vm, pm);

    int t = -1;
    FOR(i, n*m) if ((i % m == 0 || i % m == m-1 || i / m == 0 || i / m == n-1) && vp[i])
        if (!vm[i] || (dm[i] > dp[i])) t = i;

    if (t == -1) cout << "NO\n";
    else {
        cout << "YES\n";

        string path;
        while (t != s) {
            int d = pp[t] - t;
            if (d == -1) path.push_back('R');
            if (d == 1) path.push_back('L');
            if (d == m) path.push_back('U');
            if (d == -m) path.push_back('D');

            t = pp[t];
        }
        reverse(path.begin(), path.end());

        cout << path.size() << '\n';
        for (auto &p: path) cout << p;
    }
}
