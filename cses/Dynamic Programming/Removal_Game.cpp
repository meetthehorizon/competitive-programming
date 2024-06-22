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
    vector<vector<int>> dp(n, vector<int> (n, -1));
    vector<int> vec(n); for (auto &v: vec) cin >> v;

    auto rec = [&](int i, int j, auto&& rec) {
        if (i > j) return 0LL;

        if (dp[i][j] != -1) return dp[i][j];
        if (i == j) return dp[i][j] = vec[i];

        return dp[i][j] = max({
            min(rec(i+1, j-1, rec), rec(i+2, j, rec)) + vec[i],
            min(rec(i+1, j-1, rec), rec(i, j-2, rec)) + vec[j]
        });
    };

    cout << rec(0, n-1, rec);
}
