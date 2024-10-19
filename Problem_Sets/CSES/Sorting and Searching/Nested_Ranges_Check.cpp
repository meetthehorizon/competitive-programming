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


void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n; cin >> n;
    vector<array<int, 3>> vec(n);

    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        vec[i] = {l, -r, i};
    }

    vector<int> in(n), out(n);
    sort(vec.begin(), vec.end());

    int mx = -1;
    for (int i = 0; i < n; ++i) {
        if (mx >= -vec[i][1])
            in[vec[i][2]] = 1;

        mx = max(mx, vec[i][1] *= -1);
    }

    int mi = INF;
    for (int i = n-1; i >= 0; --i) {
        if (mi <= vec[i][1])
            out[vec[i][2]] = 1;
        
        mi = min(mi, vec[i][1]);
    }

    for (auto &o: out) cout << o << ' '; cout << '\n';
    for (auto &i: in) cout << i << ' '; cout << '\n';
}
