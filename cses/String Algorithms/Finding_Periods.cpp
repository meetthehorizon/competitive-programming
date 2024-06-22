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
vector<int> z(string s) {
    int n = s.size(), x = 0, y = 0;
    vector<int> z(n);
    for (int i = 1; i < n; i++) {
        z[i] = max(0LL, min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            x = i, y = i+z[i], z[i]++;
    }
    return z;
}

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    string s; cin >> s;
    int n = s.size();

    vector<int> pi = z(s);

    queue<int> stk;
    for (int i = 0; i < n; ++i) {
        if (pi[i]+i >= n)
            if (stk.empty() || stk.front() != (i)) stk.push(i);
    }

    if (stk.front() != n) stk.push(n);
    while (!stk.empty()) {cout << stk.front() << ' '; stk.pop();}

}
