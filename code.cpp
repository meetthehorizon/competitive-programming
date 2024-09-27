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
    int n; cin >> n;
    vector<int> vec(n); for (auto &v: vec) cin >> v;
    vector<int> dp[1+n]; FOR(i, 1+n) dp[i].assign(3, INF);

    dp[0][0] = 0;
    if (n == 1) {
        cout << vec[0] << '\n';
        return; 
    }

    for (int i = 0; i < n; ++i) {
        dp[i+1][0] = 
        min(dp[i+1][0], (!!vec[i]) + min({dp[i][0], dp[i][2], dp[i][3]}));
            
        if (vec[i] <= 2) {
            dp[i+1][1] = min(dp[i+1][1], 1 + min(dp[i][0], dp[i][2]));
            dp[i+1][0] = min(dp[i+1][0], dp[i][1]);
        } else {
            if (i+1 < n) dp[i+2][0] = min(dp[i+2][0], dp[i][0] + 2);
            dp[i+1][1] = min(dp[i+1][1], dp[i][2] + 1);
            dp[i+1][2] = min(dp[i+1][2], dp[i][1] + 1);
        }
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
}   