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
    vector<int> vec;

    FOR(i, n) {
        string row; cin >> row;
        vec.push_back(count_if(all(row), [](char x) { return x == '1'; }));
    }

    while (!vec.back()) vec.pop_back();
    while (!vec[0]) vec.erase(vec.begin());
 
    bool ans = 0;
    if (vec.size() != 1 && vec[0] != vec[1]) ans = 1;

    cout << (ans ? "TRIANGLE\n" : "SQUARE\n");
}