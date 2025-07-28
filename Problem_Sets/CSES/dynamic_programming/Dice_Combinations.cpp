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
    int n; cin >> n;
    vector<int> dp(n+1); dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = i-1; j >= max(0LL, i-6); --j) {
            dp[i] += dp[j];
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }    

    cout << dp.back();
}
