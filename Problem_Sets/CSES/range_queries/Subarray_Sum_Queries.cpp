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

struct node{
	long long sum, pre, suf, ans;

	node(long long val = 0LL) {
		sum = val;
		pre = suf = ans = max(0LL, val);
	}
	node(long long sum, long long pre, long long suf, long long ans) : sum(sum), pre(pre), suf(suf), ans(ans) {}

	node operator+(const node& other) {
		return node(
			sum + other.sum,
			max(pre, sum + other.pre),
			max(suf + other.sum, other.suf),
			max({
				ans,
				other.ans,
				suf + other.pre
			})
		);
	}
};
struct NodeSegmentTree{
	int n;
	vector<node> seg;
	NodeSegmentTree(const vector<long long>& vec) {
		n = 1 << (32 - __builtin_clz(vec.size() - 1));
		seg.assign(2*n, node());

		for (int i = 0; i < vec.size(); ++i)
			seg[i+n] = node(vec[i]);
		build();
	}
	node query(int a, int b, int k=1, int x=0, int y=-1) {
		if (y == -1) y += n;
		
		if (a > y || b < x) return node(0);
		if (a <= x && y <= b) return seg[k];

		int d = (x+y)>>1;
		return query(a, b, k<<1, x, d) + query(a, b, k<<1|1, d+1, y);
	}
	void update(int idx, long long val) {
		for (seg[idx += n] = node(val); idx > 1; idx >>= 1) {
			seg[idx>>1] = seg[~1&idx] + seg[idx|1];
		}
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
    NodeSegmentTree seg(vec);

    while (q--) {
    	int idx = next<int>() - 1;
    	long long val = next<long long>();
    	seg.update(idx, val);

    	cout << seg.query(0, n - 1).ans << '\n';
    }
} 			