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
bool test_cases = true;
template <typename T> T next() { T x; cin >> x; return x; }
 
int main(void)
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


long long biexp(long long a, long long b, long long m = 0) {
     long long y = 1;
     while (b > 0) {
         if (b&1) y *= a;
         a *= a; b >>= 1;
         if (m) { y %= m; a %= m; }
     }
     return y;
 } 

long long dig(long long n) { return (n == 0) ? 0 : 1 + dig(n / 10); }
string tost(long long n) {
   string res;
   while (n) {
      res.push_back(n%10+'0');
      n /= 10;
   } reverse(all(res));
   return res;
}

long long get(long long n) {
   long long res = 0LL;
   int d = dig(n);
   for (int i = 1; i < d; ++i)
      res += 9 * i * biexp(10, i - 1);
   res += (n - biexp(10, d-1) + 1) * d;
   return res;
}

void solve(int t)
{
   // CHILL BRO
   // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
   long long n = next<long long>();
   long long s = 1, j = 1e15;
   while(j) {
      do {
         if (get(s += j) >= n) break;
      } while(1);
      s -= j; j /= 2;
   }   

   string res = tost(s + 1); res.insert(res.begin(), tost(s).back());
   cout << res[n - get(s)] << '\n';
}
