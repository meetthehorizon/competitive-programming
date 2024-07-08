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
    int n, m;
    cin >> n >> m;

    vector<int> dis(n, INF), par(n, -1);
    vector<tuple<int, int, int>> edges;

    while(m--) {
        int u, v, w;
        cin >> u >> v >> w;

        if (u == v) {
            if (w < 0) {
                cout << "YES\n" << u << ' ' << u;
                return;
            }
        }

        edges.push_back({--u, --v, w});
    }

    auto relax = [&]() -> int {
        int any = -1;
        for (auto &[u, v, w]: edges) {
            if (dis[u] < INF && dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                par[v] = u;
                
                any = v;
            }
        }
        
        return any;
    };


    int v = -1;
    for (int i = 0; i < n; ++i) {
        if (dis[i] == INF) {
            dis[i] = 0;
            for (int i = 0; i < n; ++i) {
                if ((v = relax()) == -1) break;
            }
        }

        if (v != -1) break;
    }

    if (v == -1) {
        cout << "NO\n";
        return;
    }

    else {
        for (int i = 0; i < n; ++i) v = par[v];
        vector<int> cycle;
        do {
            cycle.push_back(v);
            v = par[cycle.back()];
        } while (cycle.size() == 1 || cycle.back() != cycle[0]);
        
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (auto& v: cycle) cout << ++v << ' ';
    }
}
