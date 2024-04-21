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
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    if(test_cases) cin >> t;
    for(size_t i = 1; i <= t; i++){
    solve(i);
    }
return 0;
}

class SegmentTree {
public:
   int n;
   long long id = INF;
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
   long long op(long long a, long long b) { return min(a, b); }
};
struct sol {
	int n;
	SegmentTree seg1, seg2;
	sol(const vector<long long>& vec) {
		seg1 = SegmentTree(vec.size());
		seg2 = SegmentTree(vec.size());
		n = seg1.n;

		for (int i = 0; i < vec.size(); ++i)
			seg1.update(i, vec[i] + i), seg2.update(i, vec[i] - i);
	}
	void update(int idx, long long val) {
		seg1.update(idx, val + idx), seg2.update(idx, val - idx);
	}
	long long query(int a) {
		return min({
			seg1.query(a, n - 1) - a,
			seg2.query(0, a) + a
		});
	}
};

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
	int n, q; cin >> n >> q;
	vector<long long> vec(n); for (auto &v: vec) cin >> v;
	sol seg(vec);

	while (q--) {
		if (next<int>() - 1) {
			int idx = next<int>() - 1;
			cout << seg.query(idx) << '\n';
		}
		else {
			int idx = next<int>() - 1;
			long long val = next<long long>();
			seg.update(idx, val);
		}
	}
}