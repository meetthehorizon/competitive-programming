/*
Kshitij Sharma
github: meetthehorizon
   /\_/\
  (= ._.)
  / >  \>
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
   SegmentTree(string vec, bool odd=false) : SegmentTree(vec.size()) {
      for (int i = !odd; i < vec.size(); i += 2) seg[i+n] = 1LL << (vec[i] - 'a');
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
   long long op(long long a, long long b) { return (a|b); }
};

long long biexp(long long a, long long b=MOD-2, long long m=MOD) {
    long long y = 1;
    while (b > 0) {
        if (b&1) y *= a;
        a *= a; b >>= 1;
        if (m) { y %= m; a %= m; }
    }
    return y; 
} 

vector<long long> manacher_odd(string s) {
    long long n = s.size();
    s = "$" + s + "^";
    vector<long long> p(n + 2);
    long long l = 1LL, r = 1LL;
    for(long long i = 1LL; i <= n; i++) {
        p[i] = max(0LL, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<long long>(begin(p) + 1LL, end(p) - 1LL);
}

vector<long long> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<long long>(begin(res) + 1LL, end(res) - 1LL);
}

long long ap(long long a, long long l, long long d) {
	if (l < a) return 0;
	long long n = (l - a) / d + 1LL;

	return n * (2 * a + (n - 1LL) * d) / 2;
}
void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
   	int n, q; cin >> n >> q;
   	string s = next<string>();

   	SegmentTree eve(s, false), odd(s, true);    
   	vector<long long> pal = manacher(s); pal.push_back(1LL);   
	for (auto &p: pal) --p;
   	function<bool(long long, long long)> query = [&] (long long l, long long r) {
    	long long mid = (l + r) >> 1LL, len = r - l + 1LL;

    	return pal[2 * mid + 1LL - len%2] >= len;
    };

   	while (q--) {
   		int l, r; cin >> l >> r; --l, --r;
   		int k = r - l + 1;
   		int val = k * !query(l, r), o = odd.query(l, r), e = eve.query(l, r);
   		int bo = __builtin_popcount(o), be = __builtin_popcount(e);

   		if (!((bo == 1) && (be == 1)))
   			if (k&1) val += ap(3, k-2, 2);
   			else val += ap(3, k-1, 2);

   		if (!((o == e) && (bo == 1)))
   			if (k&1) val += ap(2, k-1, 2);
   			else val += ap(2, k-2, 2);
   			
   		cout << val << '\n';
   	}
}