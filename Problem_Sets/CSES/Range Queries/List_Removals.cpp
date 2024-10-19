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
struct FenwickTree {
   int n;
   vector<long long> bit;
   FenwickTree (int sz) {
     n = sz;
     bit.assign(n, 0);
   }
   FenwickTree (vector<long long> const &vec) : FenwickTree(vec.size()) {
     for (int i = 0; i < n; ++i) {
         bit[i] += vec[i];
         int r = i | (i + 1);
         if (r < n) bit[r] += bit[i];
     }
   }
   void add(int idx, long long val) {
     for (; idx < n; idx |= idx + 1) 
         bit[idx] += val;
   }
   void update(int idx, long long val) {
     add(idx, val - sum(idx, idx));
   }
   long long psum(int idx) {
     long long ret = 0;
     for (; idx >= 0; idx = (idx & (idx + 1)) - 1) 
         ret += bit[idx];
     return ret;
   }
   long long sum(int l, int r) {
     return psum(r) - psum(l - 1);
   }
};

void solve(int t)
{
   // CHILL BRO
   // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
   int n = next<int>();
   vector<long long> vec(n); for (auto &v: vec) cin >> v;
   FenwickTree fin(n+1);

   FOR(_, n) {
      int pos = next<int>();
      int s = 0, j = n;

      while(j) {
         do{
            s += j;
            if ((s > n) || ((s - fin.psum(s)) >= pos)) break;
         }while(1);
         s -= j; j /= 2;
      }

      ++s; fin.add(s, 1);
      cout << vec[--s] << ' ';
   }

}