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


void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, x; cin >> n >> x;
    vector<int> dp(x+1); dp[0] = 1;
    vector<int> vec(n); for (auto &v: vec) cin >> v;
    sort(all(vec));

    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j < n && i + vec[j] <= x; ++j) {
            dp[i+vec[j]] += dp[i];
            if (dp[i+vec[j]] >= MOD) dp[i+vec[j]] -= MOD;
        }
    }

    cout << dp.back() << '\n';
}
