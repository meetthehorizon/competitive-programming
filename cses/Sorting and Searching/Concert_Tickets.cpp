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


void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, k; cin >> n >> k;
    multiset<int> ms;

    while(n--) ms.insert(next<int>());
    while(k--) {
        int x = next<int>();
        auto it = ms.upper_bound(x);

        if (it == ms.begin()) cout << "-1\n";
        else {
            cout << *(--it) << '\n';
            ms.erase(it);
        }
    }
}
