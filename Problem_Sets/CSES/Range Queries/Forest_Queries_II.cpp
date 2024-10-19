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

struct FenwickTree2d
{
    int n, m;
    vector<vector<long long>> bit;
    FenwickTree2d(int sz1, int sz2)
    {
        n = sz1, m = sz2;
        bit.assign(n, vector<long long>(m));
    }
    FenwickTree2d(const vector<vector<long long>> &vec) : FenwickTree2d(vec.size(), vec.back().size())
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                add(i, j, vec[i][j]);
    }

    void add(int x, int y, long long val)
    {
        for (int i = x; i < n; i |= (i + 1))
            for (int j = y; j < m; j |= (j + 1))
                bit[i][j] += val;
    }

    void toggle(int x, int y)
    {
        long long val = sum(x, y, x, y);
        add(x, y, (val ^ 1) - val);
    }

    long long psum(int x, int y)
    {
        long long res = 0;
        for (int i = x; i >= 0; i = ((i & (i + 1)) - 1))
            for (int j = y; j >= 0; j = ((j & (j + 1)) - 1))
                res += bit[i][j];
        return res;
    }
    long long sum(int i1, int j1, int i2, int j2)
    {
        if (i2 < i1)
            swap(i1, i2);
        if (j2 < j1)
            swap(j1, j2);

        return psum(i2, j2) - psum(i1 - 1, j2) - psum(i2, j1 - 1) + psum(i1 - 1, j1 - 1);
    }
};

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, q;
    cin >> n >> q;
    vector<vector<long long>> vec(n, vector<long long>(n));
    FOR(i, n)
    FOR(j, n) vec[i][j] = next<char>() == '*';
    FenwickTree2d fin(vec);

    while (q--)
    {
        if (next<int>() - 1)
        {
            int i1, j1, i2, j2;
            cin >> i1 >> j1 >> i2 >> j2;
            cout << fin.sum(--i1, --j1, --i2, --j2) << '\n';
        }
        else
        {
            int l, r;
            cin >> l >> r;
            fin.toggle(--l, --r);
        }
    }
}