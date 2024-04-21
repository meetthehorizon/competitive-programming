/*
Kshitij Sharma
github: meetthehorizon
   /\_/\
  (= ._.)
  / >  \>
*/

#include <bits/stdc++.h> 
using namespace std; 

#define MOD 1000000007
#define INF 10000000000000000
#define FOR(i, n) for (size_t i = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve(int);
bool test_cases = true;
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; if(test_cases) cin >> t;
    for(size_t i = 1; i <= t; i++)
        solve(i);
    return 0;
}

vector<long long> cache{1};
long long fact(long long n) {
    while (cache.size() <= n)
        cache.push_back(cache.size() * cache.back() % MOD);
    return cache[n];
}
long long minv(long long a) {
    long long y = 1, b = MOD - 2;
    while (b > 0) {
        if (b&1) y = y * a % MOD;
        a = a * a % MOD; b >>= 1;
    }
    return y;
}
long long ncr(long long n, long long r) {
    if (r < 0 || r > n || n < 0)
        return 0LL;
    long long ans = fact(n);
    ans = ans * minv(fact(r)) % MOD;
    ans = ans * minv(fact(n-r)) % MOD;
    return ans;
}

int dp[200000];
void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    long long n, k; cin >> n >> k;
    FOR(i, k) {
        int x, y; cin >> x >> y;
        n -= 2 - (x == y);
    }

    long long ans = 0;
    for (int i = n&1; i <= n; i += 2) {
        long long temp = ncr(n, i);
        temp *= fact(n-i) * minv(fact((n-i)/2)) % MOD;
        ans = (ans + temp) % MOD;
    }

    cout << ans << '\n';
}