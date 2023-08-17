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
    int n, q; cin >> n >> q;
    vector<int> par(n); 
    for (auto &v: par) cin >> v, --v;
    
    vector<int> sparse[30]; sparse[0] = par;
    for (int i = 1; i < 30; ++i) {
        sparse[i].resize(n);
        for (int j = 0; j < n; ++j)
            sparse[i][j] = sparse[i-1][sparse[i-1][j]];
    }

    auto query = [&](int v, int k) {
        for (int i = 0; i < 30 && v != -1; ++i, k >>= 1) {
            if (k&1) v = sparse[i][v];
        }
        return v;
    };

    while(q--) {
        int x, k; cin >> x >> k;  
        cout << query(x-1, k) + 1 << '\n';
    }
}
