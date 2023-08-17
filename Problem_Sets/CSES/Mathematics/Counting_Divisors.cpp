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
bool test_cases = true;
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

vector<int> linear_sieve(int n)
{
    vector<int> lp(n + 1);
    vector<int> pr;

    for (int i = 2; i <= n; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }

        for (int j = 0; i * pr[j] <= n; ++j)
        {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i])
                break;
        }
    }

    return lp;
}

vector<int> lp;
void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    if (lp.empty())
        lp = linear_sieve(1000005);
    map<int, int> prfact;

    int x = next<int>();
    while (x != 1)
    {
        prfact[lp[x]]++;
        x /= lp[x];
    }

    long long res = 1;
    for (auto &p : prfact)
        res *= ++p.second;

    cout << res << '\n';
}