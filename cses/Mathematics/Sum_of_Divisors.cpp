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
template <typename T>
T next()
{
    T x;
    cin >> x;
    return x;
}

signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    if (test_cases)
        cin >> t;
    for (size_t i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}

long long sum(long long a, long long b)
{
    a %= MOD, b %= MOD;
    a *= (a - 1), b *= (b + 1);
    a %= MOD, b %= MOD;
    b -= a;
    if (b < 0)
        b += MOD;
    return b * 500000004 % MOD;
}

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    long long n = next<long long>();

    long long res = 0LL;
    for (long long i = 1, la; i <= n; i = la + 1)
    {
        la = n / (n / i);
        res += ((n / i) % MOD) * sum(i, la);
        res %= MOD;
    }
    cout << res << '\n';
}