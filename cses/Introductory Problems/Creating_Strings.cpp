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
   string choices = next<string>(), perm = "";
   int n = choices.size();

   vector<bool> chosen(n, false);
   set<string> res;

   function<void(void)> search = [&] () -> void {
      if (perm.size() == n) {
         res.insert(perm);
         return;
      }

      for (int i = 0; i < n; ++i) if (!chosen[i]) {
         chosen[i] = true;
         perm.push_back(choices[i]);
         search();

         chosen[i] = false;
         perm.pop_back();
      }
   }; search();

   cout << res.size() << '\n';
   for (auto &r: res) cout << r << '\n';
}