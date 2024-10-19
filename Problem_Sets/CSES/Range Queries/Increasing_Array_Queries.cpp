/*
Kshitij Sharma
github: meetthehorizon
     /\_/\
    (= ._.)
    / >  \>
*/

#include <bits/stdc++.h> 
using namespace std; 

#define int long long
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
    int t = 1; if(test_cases) cin >> t;
    for(size_t i = 1; i <= t; i++)
        solve(i);
    return 0;
}

struct SegmentTree{
    int n;
    vector<int> ops;
    vector<vector<int>> seg, pre;
    SegmentTree(const vector<int>& vec) {
        n = 1 << (__builtin_clzll(0) - __builtin_clzll(vec.size() - 1));

        ops.assign(n<<1, 0);
        seg.assign(n<<1, {INF}); pre.resize(n<<1);
        for (int i = 0; i < vec.size(); ++i) seg[i+n] = pre[i+n] = {vec[i]};

        for (int i = n-1; i > 0; --i) {
            ops[i] = ops[i<<1] + ops[i<<1|1];
            seg[i] = seg[i<<1];
            seg[i].insert(seg[i].end(), seg[i<<1|1].begin(), seg[i<<1|1].end());

            for (int j = (seg[i].size() >> 1); j < seg[i].size(); ++j) {
                ops[i] += max(seg[i][j], seg[i][j-1]) - seg[i][j];
                seg[i][j] = max(seg[i][j], seg[i][j-1]);
            }

            pre[i] = seg[i];
            for (int j = 1; j < pre[i].size(); ++j)
                pre[i][j] += pre[i][j-1];
        }
    }

    int query(int l, int r) {
        vector<int> pos;
        _query(l, r, 0, n-1, 1, pos);
        int ans = ops[pos[0]], mx = seg[pos[0]].back();

        for (int i = 1; i < pos.size(); ++i) {
            ans += ops[pos[i]];
            int idx = lower_bound(all(seg[pos[i]]), mx) - seg[pos[i]].begin();

            if (idx) {
                ans += (idx--) * (mx);
                ans -= pre[pos[i]][idx];
            }
            mx = max(mx, seg[pos[i]].back());
        }

        return ans;
    }

    void _query(int a, int b, int x, int y, int k, vector<int>& pos) {
        if (x > b || y < a) return;
        if (a <= x && y <= b) {
            pos.push_back(k); return;
        }

        int d = (x + y) >> 1;
        _query(a, b, x, d, k<<1, pos);  
        _query(a, b, d+1, y, k<<1|1, pos);
    }
};

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, q; cin >> n >> q;
    vector<int> vec(n); for (auto &v: vec) cin >> v;
    SegmentTree seg(vec);

    while(q--) {
        int l, r; cin >> l >> r;
        cout << seg.query(--l, --r) << '\n';
    }
}
