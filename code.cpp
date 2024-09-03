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
bool test_cases = false;
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; if (test_cases) cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
    return 0;
}

vector<int> Z(string s) {
    int n = s.size(); s.push_back('$');
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        z[i] = min(max(r - i, 0LL), z[i - l]);
        while(s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
}

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    string s; cin >> s;
    int n = s.size();

    auto st = Z(s);
    reverse(s.begin(), s.end());
    auto eu = Z(s);
    reverse(s.begin(), s.end());

    cout << s << '\n';
    for (auto &v: st) cout << v << ' '; cout << '\n';
    for (auto &v: eu) cout << v << ' '; cout << '\n';
    
    for (int i = 1; i < n; ++i) {
        int j = i + st[i];
        cout << i << ' ' << j << '\n';
    }

}