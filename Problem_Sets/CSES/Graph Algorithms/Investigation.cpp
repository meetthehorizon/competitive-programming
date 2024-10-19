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
    vector<vector<pair<int, int>>> adj(n);

    while(m--) {
        int a, b, w; cin >> a >> b >> w;
        adj[--a].push_back({--b, w});
    }

    vector<int> mid(n, -INF), mxd(n, INF), d(n, INF), cnt(n);

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0}); 
    d[0] = 0; cnt[0] = mid[0] = mxd[0] = 1;

    while (!pq.empty()) {
        auto [d_v, v] = pq.top();
        pq.pop();

        if (d_v != d[v]) continue;
        for (auto [u, w]: adj[v]) {
            if (d_v + w < d[u]) {
                cnt[u] = cnt[v];
                mid[u] = mid[v] + 1;
                mxd[u] = mxd[v] + 1;
                d[u] = d_v + w;

                pq.push({d[u], u});
            } else if (d_v + w == d[u]) {
                cnt[u] = (cnt[u] + cnt[v]) % MOD;
                mid[u] = min(mid[v] + 1, mid[u]);
                mxd[u] = max(mxd[v] + 1, mxd[u]);
            }
        }
    }

    cout << d.back() << ' ' << cnt.back() << ' ' << --mid.back() << ' ' << --mxd.back();
}
