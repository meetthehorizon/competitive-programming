/*
Kshitij Sharma
github: meetthehorizon
     /\_/\
    (= ._.)  ~~hoi~~
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
bool test_cases = true;
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; if (test_cases) cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}


void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n; cin >> n;
    vector<int> l(n, -1), r(n, -1), cnt(n);
    vector<int> pre(n+1);

    FOR(i, n) {
        int x; cin >> x;
        r[--x] = i; if (l[x] == -1) l[x] = i;
        cnt[x]++;
    }

    int sl = n+1, sr = -1;
    
    for (int i = 0; i < n; ++i) {
        if (l[i] == -1) continue;
        sl = min(sl, l[i]);
        sr = max(sr, r[i]);

        // cout << sl << ' ' << sr << '\n';

        if (sr - sl > i) {
            cout << "0\n";
            return;
        }

        pre[max(0LL, sr - i)] += cnt[i];
        pre[min(n-1, sl+i) + 1] -= cnt[i];

        // if (i == 2) break;
    }

    for (int i = 0; i < n; ++i) pre[i+1] += pre[i];
    cout << count_if(pre.begin(), pre.end(), [&](int x) { return x == n; }) << '\n';
    
    // for (auto &p: pre) cout << p << ' '; cout << '\n';
}
