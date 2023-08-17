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
vector<int> kmp(string s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1, j = pi[i-1]; i < n; ++i) {
        while (j && s[i] != s[j]) j = pi[j-1];
        pi[i] = j += (s[i] == s[j]);
    }
    return pi;
}

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    string s; cin >> s;
    vector<int> pi = kmp(s);

    stack<int> stk;
    int j = pi.back();  
    while (j) {
        stk.push(j);
        j = pi[j-1];
    }

    while (!stk.empty()) {
        cout << stk.top() << ' '; stk.pop();
    }
}
