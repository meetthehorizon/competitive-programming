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

int biexp(int a, int b, int m=0) {
    int y = 1;
    while (b > 0) {
        if (b&1) y *= a;
        a *= a; b >>= 1;
        if (m) { y %= m; a %= m; }
    }
    return y; 
} 

void solve([[maybe_unused]] int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n; cin >> n;
    int sm = n * (1 + n) / 2;

    if (sm % 2) {
        cout << 0;
        return;
    }

    vector<int> dp(sm+1); dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = sm; j >= 0; --j) {
            if (i + j <= sm) {
                dp[i+j] += dp[j];
                while (dp[i+j] >= MOD) dp[i+j] -= MOD;
            }
        }
    }
    
    cout << dp[sm>>1] * biexp(2, MOD-2, MOD) % MOD;
}
