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
    int n, sum = 0; cin >> n;
    vector<int> vec(n); for (auto &v: vec) cin >> v;

    auto upd = [&]() {
        set<int> s1, s2 { 0 };
        vector<int> b;
        for (auto &v: vec) {
            if (s1.count(v)) s2.insert(v);
            else s1.insert(v);
            b.push_back(*--s2.end());
        }
        swap(vec, b);
    };

    for (auto &v: vec) cout << v << ' '; cout << '\n';
    while (vec.back()) {
        sum += accumulate(vec.begin(), vec.end(), 0LL); upd();
        for (auto &v: vec) cout << v << ' '; cout << '\n';
    }
    cout << sum << '\n';
}
