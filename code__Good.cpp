/*
Kshitij Sharma
github: meetthehorizon
     /\_/\
    (= ._.)  ~~meow~~
    / >  \>
*/

#include <bits/stdc++.h> 
using namespace std; 

#define int long long
#define MOD 1000000007u
#define INF 10000000000000000
#define FOR(i, n) for (int i = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve(int);
bool test_cases = true;
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; if(test_cases) cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
    return 0;
}


struct FenwickTree {
    int n;
    vector<int> bit;
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve([[maybe_unused]] int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, c; cin >> n >> c;
    vector<int> vec(n), pre{0LL}, prev{0LL};

    map<int, stack<int>> ms;
    FOR(i, n) {
    	cin >> vec[i];

    	ms[vec[i]].push(i);
    	prev.push_back(prev.back() + vec[i]);
    }

    vector<int> ans(n, n-1);

    FenwickTree cnt(n), act(n);
    for (auto itr = ms.rbegin(); itr != ms.rend(); ++itr) {
    	int psum = itr->first * itr->second.size();
    	int pgg = itr->second.size();

    	while (!itr->second.empty()) {
    		psum -= itr->first;
    		pgg--;
    		int idx = itr->second.top();
    		{
    			int uc = c + prev[idx+1];
    			int pg = idx;

    			int s = -1, j = pre.size() - 1;
    			while(j) {
    				do {
    					s += j;
    					if (s >= pre.size() - 1) break;
    					if(uc + pre[s] >= pre[s+1] - pre[s]) break;
    				} while(1);
    				s -= j; j /= 2;
    			} ++s;

    			ans[idx] = min(ans[idx], pg + s);
    		}

    		cnt.add(idx, 1);
    		act.add(idx, itr->first);
    		itr->second.pop();
 			pre.push_back(pre.back() + itr->first);
    	}
    }

    int idx = max_element(all(vec)) - vec.begin();
    if (!idx || (vec[0] + c) < vec[idx]) ans[idx] = 0;
    for (auto &a: ans) cout << a << ' '; cout << '\n';
}
