/*
Kshitij Sharma
github: meetthehorizon
   /\_/\
  (= ._.)
  / >  \>
*/

#include <bits/stdc++.h> 
using namespace std; 

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


struct Edge{
    int a, b, w;
    Edge(int a=0, int b=0, int w=0) : a(a), b(b), w(w) { }
};

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, m; cin >> n >> m;
    vector<int> d(n, INT_MAX), p(n, -1); 
    d[0] = 0;

    vector<Edge> edges;
    while (m--) {
        int a, b, w; cin >> a >> b >> w;
        edges.push_back(Edge(--a, --b, w));
    }

    int flag;
    for (int i = 0; i < n; ++i) {
        flag = -1;

        for (auto &e: edges) {
            if (d[e.a] < INT_MAX) {
                if (d[e.a] + e.w < d[e.b]) {
                    d[e.b] = max(-INT_MAX, d[e.a] + e.w);
                    p[e.b] = e.a;
                    flag = e.b;
                }
            }
        }

        if (flag == -1) break;
    }

    if (flag == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        flag = p[flag];

        vector<int> cycle;
        for (int v = flag; ; v = p[v]) {
            cycle.push_back(v);
            if (v == flag && cycle.size() - 1)
                break;
        }

        reverse(cycle.begin(), cycle.end());

        for (auto v: cycle) cout << ++v << ' ';
            cout << endl;
    }


}