/*
Kshitij Sharma
github: meetthehorizon
     /\_/\
    (= ._.)  ~~meow~~
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

class FenwickTree {
public:
    FenwickTree(int n) {
        this->n = n;
        bit.resize(n);
    }

    FenwickTree(const vector<int>& vec)
    : FenwickTree(vec.size()) {
        for (int i = 0; i < n; ++i) {
            bit[i] += vec[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }
private:
    int n;
    vector<int> bit;
public:
    void add(int i, int v) {
        for (; i < n; i |= i + 1)
            bit[i] += v;
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];

        return ret;
    }

    int  sum(int l, int r) { return sum(r) - sum(l - 1); }
    void set(int i, int v) { add(i, v - sum(i, i)); }
};

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, q; cin >> n >> q;
    vector<int> vec(n); for (auto &v: vec) cin >> v;
    FenwickTree ftree(vec);

    while(q--) {
        int t; cin >> t;
        if (t == 2) {
            int l, r; cin >> l >> r;
            cout << ftree.sum(--l, --r) << '\n';
        } else {
            int i, v; cin >> i >> v;
            ftree.set(--i, v);
        }
    }
}
        