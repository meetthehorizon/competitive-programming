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
    int n, k; cin >> n >> k;
    vector<int> vec(n); for (auto &v: vec) cin >> v;

    int ans = 1, mx = *max_element(vec.begin(), vec.end()), sm = accumulate(vec.begin(), vec.end(), 0LL);
    for (int i = 1; i <= n; ++i) {
        int del = mx + max((sm - mx * i + i - 1) / i, 0LL);
        del *= i;
        if (del - sm <= k) ans = i;
    }

    cout << ans << '\n';
}
