/*
Kshitij Sharma
github: meetthehorizon
*/

#include <bits/stdc++.h> 
using namespace std; 

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
    int t = 1;
    if(test_cases) cin >> t;
    for(size_t i = 1; i <= t; i++){
    solve(i);
    }
return 0;
}
vector<long long> fact{1};
long long biexp(long long a, long long b, long long m = 0) {
    long long y = 1;
    while (b > 0) {
        if (b&1) y *= a;
        a *= a; b >>= 1;
        if (m) { y %= m; a %= m; }
    }
    return y;
}

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
	FOR (i, 1e6) fact.push_back(fact.back() * (i + 1) % MOD);

    string s; cin >> s;
    vector<int> vec(26); 
    for (auto &c: s)
    	vec[c-'a']++;

    long long ans = fact[accumulate(all(vec), 0LL)];
    for (auto &v: vec) ans = ans * biexp(fact[v], MOD-2, MOD) % MOD;

    cout << ans << '\n';
}