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


void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, q; cin >> n >> q;
    vector<int> vec(n); FOR(i, n-1) cin >> vec[i+1];
    for (auto &v: vec) --v;

    vector<int> spa[20];
    for (int i = 0; i < 20; ++i) {
        spa[i] = vec;
        vector<int> temp = vec;

        FOR(i, n) temp[i] = (vec[i] != -1 ? vec[vec[i]] : vec[i]);
        swap(vec, temp);
    }

    while (q--) {
        int x, y; cin >> x >> y;
        --x;
        for (int i = 19; i >= 0; --i) {
            if (1<<i&y) {
                x = spa[i][x];
            }
            if (x == -1) break;
        }

        cout << (x == -1 ? x : ++x) << '\n';
    }

}
