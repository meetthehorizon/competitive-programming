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


long long biexp(long long a, long long b, long long m) {
    long long y = 1;
    while (b > 0) {
        if (b&1) y *= a;
        a *= a; b >>= 1;
        if (m) { y %= m; a %= m; }
    }
    return y;
}

long long num_div(vector<pair<int, int>> vec) {
	long long res = 1;
	for (auto &p: vec) res = res * (1 + p.second) % MOD;
	return res;
}

long long sum_div(vector<pair<int, int>> vec) {
	long long res = 1;
	for (auto &p: vec) {
		long long temp = biexp(p.first, 1 + p.second, MOD) - 1;
		if (temp < 0) temp += MOD;
		temp = temp * biexp(p.first - 1, MOD - 2, MOD) % MOD;
		res = res * temp % MOD;
	}
	return res;
}

long long prod_div(vector<pair<int, int>> vec) {
	bool all_even = true;
	long long prod = 1, res = 1;

	for (auto &p: vec) {
		res *= (1 + p.second);
		if (all_even && (p.second&1)) {
			all_even = false;
			res >>= 1;
		}
		res %= (MOD - 1);
	}

	for (auto &p: vec) {
		if (all_even) p.second >>= 1;
		prod = prod * biexp(p.first, p.second * res % (MOD - 1), MOD) % MOD;
	}

	return prod;
}

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n = next<int>();
    vector<pair<int, int>> vec(n);
    for (auto &p: vec) cin >> p.first >> p.second;

    cout << num_div(vec) << ' ' << sum_div(vec) << ' ' << prod_div(vec);
}