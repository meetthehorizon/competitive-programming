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


void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n; cin >> n;
    vector<int> vec(n); for (auto &v: vec) cin >> v;

    sort(all(vec));
    int64_t sad = 1;

    for (int i = 0; i < n; ++i) {
        sad = lcm(vec[i], sad);
        if (sad > vec.back()) {
            cout << n << '\n';
            return;
        }
    }

    set<int> div;
    for (int i = 1; i * i <= sad; ++i) if(!(sad%i)) {
        div.insert(i);
        div.insert(sad / i);
    }

    int ans = 0;
    for (auto &d: div) {
        if (binary_search(all(vec), d)) continue;
        int cnt = 0, lcm2 = 1;
        for (auto &v: vec) {
            if (!(d%v)) {++cnt;
                        lcm2 = lcm(lcm2, v);}
        }
        if (lcm2 == d) ans = max(ans, cnt);
    }

    cout << ans << '\n';
}