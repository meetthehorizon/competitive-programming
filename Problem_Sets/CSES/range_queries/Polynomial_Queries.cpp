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

struct op;
struct monoid {
    int l, r;
    int val;

    // default should be identity element of monoid
    monoid(int l=-1, int r=-1) : val(0LL), l(l), r(r) {} 
    monoid(int l, int r, int val) : monoid(l, r) { this->val = val; }

    monoid operator+(const monoid& other) {
        // combines two monoids togethor
        return monoid(l, other.r, val + other.val);
    }

    void push(op&, op&, op&);
};

struct op {
    int l, r;
    int a, d;
    
    // define identity operation to be default
    op(int l=-1, int r=-1, int a=0, int d=0) : l(l), r(r), a(a), d(d) { }

    monoid apply(monoid node) {
        // returns a new aggregate monoid after op application
        int n = r - l + 1;
        node.val += n * (2 * a + (n - 1) * d) / 2;
        return node;
    }
    op operator+(const op& other) {
        // adds two operator togethor
        return op(l, r, a + other.a + (l - other.l) * other.d, d + other.d);
    }
};

void monoid::push (op& self, op& left, op& right) {
    *this = self.apply(*this);
    left = left + self, right = right + self;
    self = op(self.l, self.r);
}

struct GenSegmentTree{
public:
    int n;
    vector<monoid> seg;
    vector<op> fxn;

    GenSegmentTree(int sz) {
        n = 1 << (32 - __builtin_clz(sz - 1));
        seg.assign(2*n, monoid());
        fxn.assign(2*n, op());

        for (int i = 0; i < n; ++i)
            fxn[i+n].l = fxn[i+n].r = seg[i+n].l = seg[i+n].r = i;
        build();
    }    
    GenSegmentTree(vector<int>& vec) : GenSegmentTree(vec.size()) {
        for (int i = 0; i < vec.size(); ++i)
            seg[i+n].val = vec[i];

        build();
    }
    int query(int a, int b) {
        return _query(a, b, 1, 0, n - 1).val;
    }
    void fun(int a, int b, int x, int y) {
        op func = op(a, b, x, y); // modify this call
        _fun(a, b, func, 1, 0, n - 1);
    }
private:
    monoid _query(int a, int b, int k, int x, int y) {
        if (a > y || b < x) return monoid(x, y);
        if (a <= x && y <= b) {
            return fxn[k].apply(seg[k]);
        }

        if (k < n) 
            seg[k].push(fxn[k], fxn[k<<1], fxn[k<<1|1]);
 
        int d = (x + y) / 2;
        return _query(a, b, k<<1, x, d) + _query(a, b, k<<1|1, d + 1, y);
    }
    void _fun(int a, int b, op& func, int k, int x, int y) {
        if (a > y || b < x) return;
        if (a <= x && y <= b) {
            fxn[k] = fxn[k] + func;
            return;
        }

        if (k < n) 
            seg[k].push(fxn[k], fxn[k<<1], fxn[k<<1|1]);

        int d = (x + y) / 2;
        _fun(a, b, func, k << 1, x, d);
        _fun(a, b, func, k<<1|1, d+1, y);

        seg[k] = fxn[k<<1].apply(seg[k<<1]) + fxn[k<<1|1].apply(seg[k<<1|1]);
    }    
    void build() {
        for (int i = n - 1; i > 0; --i) {
            seg[i] = seg[i<<1] + seg[i<<1|1];
            fxn[i].l = seg[i].l, fxn[i].r = seg[i].r;
        }
    }
};

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, q; cin >> n >> q;
    vector<int> vec(n); for (auto &v: vec) cin >> v;

    GenSegmentTree seg(vec);
    while(q--) {
        if (next<int>() == 1) {
            int l, r; cin >> l >> r;
            seg.fun(--l, --r, 1, 1);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.query(--l, --r) << '\n';
        }
    }
}
