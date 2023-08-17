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
   vector<int> col(n, -1);
   bool flag = true;

   vector<vector<int>> adj(n);
   while (m--) {
      int x, y; cin >> x >> y;
      adj[--x].push_back(--y);
      adj[y].push_back(x);
   }
   
   function<void(int)> dfs = [&] (int v) -> void {
      if (col[v] == -1) col[v] = 0;
      for (auto &u: adj[v]) {
         if (col[u] == -1)
            col[u] = col[v]^1, dfs(u);
         else if (col[u]^col[v]) ;
         else flag = false;
      }
   }; 

   FOR (i, n) if (-1 == col[i]) dfs(i);
   if (!flag) cout << "IMPOSSIBLE\n";
   else {
      FOR(i, n) cout << ++col[i] << ' ';
   }
}
