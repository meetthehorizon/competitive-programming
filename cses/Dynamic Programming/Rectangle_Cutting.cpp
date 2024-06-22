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
    int dp[501][501]; memset(dp, -1, sizeof dp);

    auto rec = [&](int a, int b, auto&& rec) {
        if (b > a) swap(a, b);
        if (dp[a][b] != -1) return dp[a][b];
        if (a == b) return dp[a][b] = 0;

        dp[a][b] = INF;
        for (int i = 1; i < a; ++i) 
            dp[a][b] = min(dp[a][b], 1 + rec(i, b, rec) + rec(a - i, b, rec));
        for (int i = 1; i < b; ++i) 
            dp[a][b] = min(dp[a][b], 1 + rec(a, i, rec) + rec(a, b - i, rec));

        return dp[a][b];
    };

    cout << rec(n, m, rec);
}
