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
   long long id = -INF;
   vector<long long> seg;
   SegmentTree(int sz=0) {
      n = 1 << (32 - __builtin_clz(sz - 1));
      seg.assign(n << 1, id);
   }
   SegmentTree(vector<long long> vec) : SegmentTree(vec.size() - 1) {
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

void solve(int t)
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

    vector<int> par(n), head(n), dep(n), pos(n), heavy(n);
    function<int(int)> dfs = [&](int v) -> int {
        int sz = 1, mx = 0, c = -1;

        for (auto u: adj[v]) if (u != par[v]) {
            par[u] = v, dep[u] = dep[v]+1;
            int tsz = dfs(u);
            sz += tsz;
            if (tsz > mx)
                mx = tsz, c = u;
        }

        heavy[v] = c;
        return sz;
    }; dfs(0); cout << '\n';

    int ptr = 0;
    function<void(int, int)> hld = [&](int v, int h) {
        head[v] = h; pos[v] = ptr++;

        if (heavy[v] != -1) hld(heavy[v], h);
        for (auto u: adj[v]) 
            if (u != par[v] && u != heavy[v]) {
                hld(u, u);
            }
    }; hld(0, 0);

    SegmentTree seg(n);
    FOR(i, n) seg.update(pos[i], vec[i]);

    auto query = [&](int a, int b) {
        int res = -INF;
        for (; head[a] != head[b]; b = par[head[b]]) {
            if (dep[head[a]] > dep[head[b]])
                swap(a, b);

            res = max(res, seg.query(pos[head[b]], pos[b]));
        }

        if (dep[a] > dep[b]) swap(a, b);
        return max(res, seg.query(pos[a], pos[b]));
    };

    while (q--) {
        if (next<int>() == 2) {
            int a, b; cin >> a >> b;
            cout << query(--a, --b) << ' ';
        } else {
            int v, x; cin >> v >> x;
            seg.update(pos[--v], x);
        }
    }
}   
