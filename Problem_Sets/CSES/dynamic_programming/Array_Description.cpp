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
    int n, m; cin >> n >> m;
    vector<int> dp(m+1, 1); dp[0] = 0;

    while(n--) {
        int x; cin >> x;

        if (x) {
            int t = dp[x];
            dp.assign(m+1, 0);
            dp[x] = t;
        }
        if (!n) break; 
        auto temp = dp;
        for (int i = 1; i <= m; ++i) {
            temp[i] += dp[i-1];
            if (i+1 <= m) temp[i] += dp[i+1];
        }
        dp = temp;

        for (auto &d: dp) d %= MOD;
    }

    int ans = 0;
    for (auto &d: dp) {
        ans += d;
        while (ans >= MOD) ans -= MOD;
    }

    cout << ans << '\n';
}
