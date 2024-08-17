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
#define MOD          1000000007
#define INF          10000000000000000
#define all(x)       (x).begin(), (x).end()
#define rall(x)      (x).rbegin(), (x).rend()
#define FOR(i, n)    for (int i = 0; (i) < (n); (i)++)

void solve(int);
bool test_cases = false;
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; if (test_cases) cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}

vector<int> segSieve(int n) {
    int nsq = sqrt(n), s = 1000;
    vector<int> primes;
    vector<char> is_prime(nsq+1, true);

    for (int i = 2; i <= nsq; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i*i; j <= nsq; j += i)
                is_prime[j] = false;
        }
    }

    vector<int> block(s);
    for (int k = 0; k * s <= n; ++k) {
        fill(block.begin(), block.end(), true);
        int start = k * s;

        for (auto p: primes) {
            if (p > nsq) break;
            int mi = (start + p - 1) / p;
            int j = max(mi, p) * p - start;

            for (; j < s; j += p) block[j] = false;
        }

        if (k == 0) block[0] = block[1] = false;
        for (int i = 0; i < s && start + i <= n; ++i)
            if (block[i]) primes.push_back(start + i);
    }
    
    return primes;
}

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    for (auto &p: segSieve(1000)) cout << p << ' ';
}
