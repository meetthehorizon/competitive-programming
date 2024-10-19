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
    int n, x; cin >> n >> x;
    vector<pair<int, int>> vec(n);

    for (auto &v: vec) cin >> v.first;    
    for (auto &v: vec) cin >> v.second;    

    vector<int> dp(x+1); dp[0] = 0;
    for (auto &v: vec) {
        for (int i = x; i >= 0; --i) {
            if (i + v.first <= x) {
                dp[i+v.first] = max(dp[i+v.first], v.second + dp[i]);
            }
        }
    }

    cout << *max_element(all(dp)) << '\n';
}
