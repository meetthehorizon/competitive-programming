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
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void)
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1;
   if(test_cases) cin >> t;
   for(size_t i = 1; i <= t; i++){
     solve(i);
   }
   return 0;
}

struct LazySegmentTree{
   int n;
   vector<long long> seg;
   vector<long long> lazy;
   LazySegmentTree(int sz) {
      n = 1 << (32 - __builtin_clz(sz - 1));
      seg.assign(2 * n, 0);
      lazy.assign(2 * n, 0);
   }
   LazySegmentTree(const vector<long long>& vec) : LazySegmentTree(vec.size()) {
      for (int i = 0; i < vec.size(); ++i)
         seg[i+n] = vec[i];
      build();
   }
   void update(int a, int b, long long val, int k=1, int x=0, int y=-1) {
      if (y == -1) y += n;
      if (b < x || a > y) return;
      if (x >= a && y <= b) {
         lazy[k] += val;
         return;
      }
      int d = (x + y) / 2;
      update(a, b, val, k<<1, x, d);
      update(a, b, val, k<<1|1, d+1, y);
   }
   long long sum(int a, int b, int k=1, int x=0, int y=-1) {
      if (y == -1) y += n;

      if (b < x || a > y) return 0LL;
      if (x >= a && y <= b) return lazy[k] + seg[k];

      if (k < n) {
         lazy[k<<1] += lazy[k];
         lazy[k<<1|1] += lazy[k];
         seg[k] += lazy[k] * (y - x + 1);
         lazy[k] = 0;
      }

      int d = (x + y) / 2;
      return sum(a, b, k<<1, x, d) + sum(a, b, k<<1|1, d+1, y);
   }
   void build() {
      for (int i = n - 1; i > 0; --i)
         seg[i] = seg[i<<1] + seg[i<<1|1];
   }
};

void solve(int t)
{
   // CHILL BRO
   // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
   int n, q; cin >> n >> q;
   vector<long long> vec(n); for (auto &v: vec) cin >> v;
   LazySegmentTree seg(vec);


   while (q--) {
      int type; cin >> type;
      if (type == 1) {
         int l, r; cin >> l >> r; --l, --r;
         long long val; cin >> val;
         seg.update(l, r, val);
      } else {
         int l; cin >> l; --l;
         cout << seg.sum(l, l) << '\n';
      }
   }
}