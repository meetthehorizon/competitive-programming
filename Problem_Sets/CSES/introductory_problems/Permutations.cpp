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
vector<long long> foo_vec;
bool test_cases = false;

template <typename T> T next() { T x; cin >> x; return x; }
template <typename T> void foo(T& var) { cin >> var; }
template <typename T> vector<T> vin(vector<T>& vec, int sz) { 
   vec.resize(sz); for (auto &v: vec) foo(v); return vec;
}
 
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


void solve(int t)
{
   // CHILL BRO
   // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
   int n = next<int>();
   if (n == 1) {
      cout << 1; return;
   } else if (n == 2 || n == 3) {
    cout << "NO SOLUTION\n"; return;
   } else if (n == 4) {
    cout << "2 4 1 3\n"; return;
   } else if (n == 5) {
    cout << "4 2 5 3 1\n"; return;    
   }

   if (n % 2) cout << n << ' ';
   FOR (i, n / 2) cout << i + 1 << ' ' << i + n / 2 + 1 << ' ';
} 