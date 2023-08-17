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
vector<long long> foo_vec;
bool test_cases = false;

template <typename T>
T next()
{
    T x;
    cin >> x;
    return x;
}
template <typename T>
void foo(T &var) { cin >> var; }
template <typename T>
vector<T> vin(vector<T> &vec, int sz)
{
    vec.resize(sz);
    for (auto &v : vec)
        foo(v);
    return vec;
}

int main(void)
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

long long biexp(long long a, long long b, long long m = MOD)
{
    long long y = 1;
    while (b > 0)
    {
        if (b & 1)
            y *= a;
        a *= a;
        b >>= 1;
        if (m)
        {
            y %= m;
            a %= m;
        }
    }
    return y;
}

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    cout << biexp(2, next<long long>()) << '\n';
}