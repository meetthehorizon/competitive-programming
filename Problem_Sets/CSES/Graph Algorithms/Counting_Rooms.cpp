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
   int n, m; cin >> n >> m;
   vector<bool> vis(n*m);
   FOR (i, vis.size()) {
      char c; cin >> c; vis[i] = c == '#';
   }
   int count = 0;

   function<void(int)> dfs = [&] (int s) -> void {
      vis[s] = true;
      if (s - m >= 0) if (!vis[s-m]) dfs(s-m);
      if (s + m < n*m) if (!vis[s+m]) dfs(s+m);
      if (s % m != m - 1) if (!vis[s + 1]) dfs(s + 1);
      if (s % m != 0) if (!vis[s - 1]) dfs(s - 1);
   };

   FOR (i, n*m) if (!vis[i]) if (++count) dfs(i);
   cout << count << '\n';
}