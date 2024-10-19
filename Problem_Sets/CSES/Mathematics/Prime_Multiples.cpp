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


void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
	long long n; cin >> n;
	int k; cin >> k;
	vector<long long> vec(k); for (auto &v: vec) cin >> v;

	long long ans = 0;
	double ln = log(n) + 0.0001;
	for (int mask = 1; mask < (1 << k); ++mask) {
		bool odd = __builtin_popcount(mask)%2;
		double rn = 0;

		long long prod = 1;
		for (int i = 0; i < k; ++i) if ((1 << i) & mask) {

			rn += log(vec[i]);
			prod *= vec[i];
		}

		if (ln > rn)
			ans += (odd ? 1 : -1) * (n / prod);
	}

	cout << ans << '\n';
}