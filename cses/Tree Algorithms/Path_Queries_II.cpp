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

class SegmentTree {
public:
    int n;
    long long id = -INF;
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
    long long op(long long a, long long b) { return max(a, b); }
};

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, q; cin >> n >> q;

    vector<int> vec(n); for (auto &v: vec) cin >> v;
    vector<vector<int>> adj(n);    

    FOR(i, n-1) {
        int x, y; cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }

    int ptr = 0;
    SegmentTree seg(n);
    vector<int> par(n), heavy(n, -1), dep(n), pos(n), head(n);

    auto dfs = [&](int v, auto&& dfs) -> int {
        int sz = 1, mx_sz = 0;
        for (auto u: adj[v]) if (u != par[v]) {
            par[u] = v;
            dep[u] = dep[v] + 1;
            int x = dfs(u, dfs);

            if (mx_sz <= x) {
                heavy[v] = u;
                mx_sz = x;
            }
            sz += x;
        }
        return sz;
    }; 

    auto dec = [&](int v, int h, auto&& dec) -> void {
        head[v] = h;
        seg.update(pos[v] = ptr++, vec[v]);
        if (heavy[v] != -1) {
            dec(heavy[v], h, dec);
        }

        for (auto u: adj[v]) if (u != par[v] && u != heavy[v]) {
            dec(u, u, dec);
        }
    };

    auto query = [&](int a, int b) -> int {
        int ret = seg.id;
        for (; head[a] != head[b]; b = par[head[b]]) {
            if (dep[head[a]] > dep[head[b]]) swap(a, b); // NOTE THIS LINE
            ret = seg.op(ret, seg.query(pos[head[b]], pos[b]));
        }
        if (dep[a] > dep[b]) swap(a, b);
        return seg.op(ret, seg.query(pos[a], pos[b]));
    };

    dfs(0, dfs); dec(0, 0, dec);

    while(q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x;
            seg.update(pos[--s], x);
        } else {
            int a, b; cin >> a >> b;
            cout << query(--a, --b) << ' ';
        }
    }
}
