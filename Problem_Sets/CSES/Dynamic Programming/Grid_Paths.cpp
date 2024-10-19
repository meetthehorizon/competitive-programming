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
    int n; cin >> n;
    vector<string> grid(n);
    for(auto &x : grid) cin >> x;

    vector<vector<int>> dp(n, vector<int> (n));
    dp[0][0] = grid[0][0] != '*';

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            while (dp[i][j] >= MOD) dp[i][j] -= MOD;
            if (i+1 < n && grid[i+1][j] != '*') dp[i+1][j] += dp[i][j];
            if (j+1 < n && grid[i][j+1] != '*') dp[i][j+1] += dp[i][j];
        }
    }

    cout << dp[n-1][n-1] << '\n';
}
