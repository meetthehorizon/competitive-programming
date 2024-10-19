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

vector<int> mano(string s) {
    int n = s.size();
    s = "#" + s + "$";
    int l = 1, r = 1;

    vector<int> p(n+2);
    for (int i = 1; i <= n; ++i) {
        p[i] = max(0LL, min(r-i, p[l+r-i]));
        while (s[i-p[i]] == s[i+p[i]]) p[i]++;
        if (r < i+p[i])
            l = i-p[i], r = i+p[i];
    }
    return vector<int>(p.begin()+1, p.end()-1);
}
vector<int> man(string s) {
    string t;
    for (auto c: s) {
        t.push_back('#');
        t.push_back(c);
    } t.push_back('#');

    auto res = mano(t); for (auto &r: res) --r;
    return vector<int>(res.begin()+1, res.end());
}

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    string s; cin >> s;
    vector<int> pal = man(s);
    int mx = max_element(all(pal)) - pal.begin(); 
    cout << string(s.begin() + (mx >> 1) - (pal[mx] >> 1) + !(pal[mx]%2),
                s.begin() + (mx >> 1) + (pal[mx] >> 1) + 1); 
}
