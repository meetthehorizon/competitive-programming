/*
Kshitij Sharma
github: meetthehorizon
*/

#include <bits/stdc++.h> 
using namespace std; 

#define MOD 1000000007
#define INF 10000000000000000
// #define FOR(i, n) for (size_t i = 0; (i) < (n); (i)++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

void solve(long long);
vector<long long> foo_vec;
bool test_cases = true;

template <typename T> T next() { T x; cin >> x; return x; }
template <typename T> void foo(T& var) { cin >> var; }
template <typename T> vector<T> vin(vector<T>& vec, long long sz) { 
   vec.resize(sz); for (auto &v: vec) foo(v); return vec;
}
 
int main(void)
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   long long t = 1;
   if(test_cases) cin >> t;
   for(size_t i = 1; i <= t; i++){
     solve(i);
   }
   return 0;
}


void solve(long long t)
{
   // CHILL BRO
   // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
   long long x = next<long long>(), y = next<long long>();
   if (y > x) {
      if (y % 2) cout << y * y - x + 1 << '\n';
      else cout << (y - 1) * (y - 1) + x << '\n';
   } else {
      if (x % 2 == 0) cout << x * x - y + 1 << '\n';
      else cout << (x - 1) * (x - 1) + y  << '\n';
   }
}