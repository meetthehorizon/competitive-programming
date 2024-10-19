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
   vector<vector<bool>> pos(8, vector<bool> (8));
   FOR(i, 8) FOR(j, 8) pos[i][j] = (next<char>() == '*');
   vector<bool> col(8, false), dg1(16, false), dg2(16, false);

   long long count = 0;
   function<void(int)> search = [&] (int y) -> void {
      if (y == 8) { ++count; return; }
      FOR (x, 8) {
         if (pos[x][y] || col[x] || dg1[x + y] || dg2[x - y + 7]) continue;
         col[x] = dg1[x + y] = dg2[x - y + 7] = 1;
         search(y + 1);
         col[x] = dg1[x + y] = dg2[x - y + 7] = 0;
      }
   }; search(0);
   cout << count << '\n';
}