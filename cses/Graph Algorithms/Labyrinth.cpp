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
 
 
void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, m; cin >> n >> m;
    vector<string> lab(n);
    for (auto &f: lab) cin >> f;
    
    pair<int, int> a, b;
    FOR(i, n) FOR(j, m) {
        if (lab[i][j] == 'A') a = {i, j};
        if (lab[i][j] == 'B') b = {i, j};
    }
 
    map<pair<int, int>, char> par;
    map<pair<int, int>, bool> vis;
    queue<pair<int, int>> q;
 
    auto valid = [&](pair<int, int> p) {
        if (p.first < 0 || p.second < 0 || p.first >= n || p.second >= m || lab[p.first][p.second] == '#' || vis[p]) return false;
        return true;
    };
 
    q.push(a); vis[a] = true;
    while (!q.empty()) {
        auto top = q.front(); q.pop();
        for (auto &c: {'L', 'D', 'R', 'U'}) {
            auto child = top;
            child.first -= (c == 'D') - (c == 'U');
            child.second -= (c == 'R') - (c == 'L');
 
            if (valid(child)) {
                vis[child] = true;
                par[child] = c;
                q.push(child);
            }
        }
    }
 
    if (!vis[b]) { cout << "NO\n"; return; }
    string path;
 
    while (b != a) {
        path.push_back(par[b]);
        if (par[b] == 'L') b.second--;
        else if (par[b] == 'R') b.second++;
        else if (par[b] == 'U') b.first--;
        else b.first++;
    }
 
    reverse(all(path));
    for (auto &c: path) {
        if (c == 'L') c = 'R';
        else if (c == 'D') c = 'U';
        else if (c == 'R') c = 'L';
        else c = 'D';
    }
 
    cout << "YES\n" << path.size() << '\n' << path << '\n';
 
 
}
