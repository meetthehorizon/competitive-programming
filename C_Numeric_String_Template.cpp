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
    vector<int> vec(n); for (auto &v: vec) cin >> v;
    int q; cin >> q;

    while (q--) {
        string s; cin >> s;
        map<int, char> ms;

        string t;
        if (s.size() != n) {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (ms.find(vec[i]) == ms.end())
                ms[vec[i]] = s[i];
            t.push_back(ms[vec[i]]);
        }

        vector<bool> used(26);
        for (auto &itr: ms) if (used[itr.second-'a']) t = ""; else used[itr.second-'a'] = 1;

        cout << ((s == t) ? "YES\n" : "NO\n");
    }
}
