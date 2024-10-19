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
   string s = next<string>();
   map<char, int> m; for (auto &c: s) m[c]++;
   int codd = 0; for (auto &itr: m) codd += itr.second % 2;

   if (codd > 2 || (codd && !(s.size()%2))) cout << "NO SOLUTION\n";
   else {
      string a = "", b = "";
      for (auto &itr: m) 
         if (itr.second%2) b += string(itr.second, itr.first);
         else a += string(itr.second >> 1, itr.first);

      for (auto &c: a) cout << c;
      for (auto &c: b) cout << c;
      for (int i = a.size() - 1; i >= 0; --i) cout << a[i];
   }
}