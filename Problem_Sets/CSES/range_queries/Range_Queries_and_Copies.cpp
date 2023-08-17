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

class SegmentTree {
public:
    int n;
    long long id = 0LL;
    vector<long long> seg;
    SegmentTree(int sz=0) {
        n = 1 << (32 - __builtin_clz(sz - 1));
        seg.assign(n << 1, id);
    }
    SegmentTree(vector<long long> vec) : SegmentTree(vec.size()) {
        for (int i = 0; i < vec.size(); ++i) seg[i+n] = vec[i];
        build();
    }
    void update(int idx, long long val) {
        for (seg[idx += n] = val; idx > 1; idx >>= 1) seg[idx>>1] = op(seg[idx], seg[idx^1]);
    }
    long long query(int l, int r) {
        long long res = id;
        for (l += n, r += n; r >= l; l >>= 1, r >>= 1) {
            if (r%2 == 0) res = op(res, seg[r--]);
            if (l%2 == 1) res = op(res, seg[l++]);
        }
        return res;
    }
    void build() {
        for (int i = n - 1; i > 0; --i) seg[i] = op(seg[i<<1], seg[i<<1|1]);
    }
    long long op(long long a, long long b) { return (a + b); }
};

struct Persistent{
    int op;
    vector<int> qidx;
    vector<Persistent*> next;

    Persistent() : op(-1), qidx({}), next({}) { }
};

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, q; cin >> n >> q;
    vector<int> vec(n); for (auto &v: vec) cin >> v;
    SegmentTree seg(vec);

    vector<pair<int, int>> ops;
    vector<Persistent*> seg_trees{new Persistent()};
    auto root = seg_trees[0];

    while(q--) {
        int t, k; cin >> t >> k;
        auto node = seg_trees[--k];

        if (t == 3) {
            node->next.push_back(new Persistent());
            seg_trees.push_back(node->next.back());
        }

        else if (t == 2) {
            int l, r; cin >> l >> r;
            node->qidx.push_back(ops.size());
            ops.push_back({--l, --r});
        }
        else {
            int a, x; cin >> a >> x;
            node->next.push_back(new Persistent());
            seg_trees[k] = node->next.back();
            node = node->next.back();
            node->op = ops.size();
            ops.push_back({--a, x});
        }
    }

    vector<int> res(ops.size());
    function<void(Persistent*)> dfs = [&](Persistent* node) -> void{
        pair<int, int> inv;
        if (node->op != -1) {
            inv = ops[node->op];
            inv.second = seg.query(inv.first, inv.first);
            seg.update(ops[node->op].first, ops[node->op].second);
        }

        for (auto &q: node->qidx) 
            res[q] = seg.query(ops[q].first, ops[q].second);

        for (auto child: node->next) dfs(child);
        if (node->op != -1) seg.update(inv.first, inv.second);
    }; dfs(root);

    for (auto &v: res) if (v) cout << v << '\n'; 
}
    