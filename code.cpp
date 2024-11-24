/*
Kshitij Sharma
github: meetthehorizon
     /\_/\
    (= ._.)  ~~hoi~~
    / >  \>
*/

#include <bits/stdc++.h> 
using namespace std; 

#define int          long long
#define INF          10000000000000000
#define all(x)       (x).begin(), (x).end()
#define rall(x)      (x).rbegin(), (x).rend()
#define FOR(i, n)    for (int i = 0; (i) < (n); (i)++)

void solve(int);
long long MOD = 1000000007;
bool test_cases = true;
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; if (test_cases) cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}

vector<int> spf, primes;
void linSieve(int n) {
    spf.assign(n+1, 0); 

    for (int i = 2; i <= n; ++i) {
        if (!spf[i]) primes.push_back(spf[i] = i);
        for (int j: primes) {
            if (j * i > n) break;
            spf[i * j] = j;
            if (spf[i] == j) break;
        }
    }
}

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    cout << "Hoi! I am horizon\n";
}
