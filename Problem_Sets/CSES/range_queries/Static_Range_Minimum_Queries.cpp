/*
Kshitij Sharma
github: meetthehorizon
*/

#include <bits/stdc++.h> 
using namespace std; 

#define MOD 1000000007
#define INF 10000000000000000
#define FOR(i, n) for (size_t i = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve(int);
bool test_cases = false;
template <typename T> T next() { T x; cin >> x; return x; }
 
signed main(void)
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1;
   if(test_cases) cin >> t;
   for(size_t i = 1; i <= t; i++){
     solve(i);
   }
   return 0;
}


void solve(int t)
{
   // CHILL BRO
   // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
   int n, q; cin >> n >> q;
   vector<long long> vec(n); for (auto &v: vec) cin >> v;

   int sz = (32 - __builtin_clz(n - 1));
   vector<vector<long long>> sparse(sz + 1, vector<long long> (n));
   sparse[0] = vec;

   for (int i = 1; i <= sz; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
         sparse[i][j] = min(sparse[i-1][j], sparse[i-1][j + (1 << (i - 1))]);
      }
   }  

   while (q--) {
      int l, r; cin >> l >> r;
      --l; --r;
      int p = 0;
      while ( (1 << p) <= (r-l+1)) ++p; --p;
      cout << min(sparse[p][l], sparse[p][r-(1<<p)+1]) << '\n';
   }

}
