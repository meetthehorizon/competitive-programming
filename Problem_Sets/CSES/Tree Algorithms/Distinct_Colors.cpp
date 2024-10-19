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
    vector<int> vec(n); for (auto &v: vec) cin >> v;

    vector<vector<int>> adj(n);
    FOR(i, n-1) {
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }

    vector<int> ans(n);
    map<int, set<int>*> hash;
    function<void(int, int)> dfs = [&](int v, int p) -> void {
        set<int>* mx = nullptr;
        for (auto &u: adj[v])
            if (p != u) {
                dfs(u, v);
                if (!mx || mx->size() < hash[u]->size())
                    mx = hash[u];
            }

        if (!mx) {
            ans[v] = 1;
            hash[v] = new set<int>({vec[v]});
            return;
        }

        for (auto &u: adj[v]) {
            if (p != u && mx != hash[u]) {
                for (auto c: *hash[u]) {
                    mx->insert(c);
                }
            }
        }

        mx->insert(vec[v]);
        ans[v] = mx->size();
        hash[v] = mx;
    }; dfs(0, 0);

    for (auto &a: ans) cout << a << ' '; cout << '\n';
}
