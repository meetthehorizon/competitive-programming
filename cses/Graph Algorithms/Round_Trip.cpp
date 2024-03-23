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
   vector<vector<int>> adj(n);

   while (m--) {
      int x, y; cin >> x >> y;
      adj[--x].push_back(--y);
      adj[y].push_back(x);
   }

   vector<bool> vis(n, false);
   vector<int> cycle, par(n, -1);

   function<bool(int)> find_cycle = [&] (int v) -> bool {
      vis[v] = true;
      for (auto &u: adj[v]) if (u != par[v]) {
         if (vis[u]) {
            cycle.push_back(v);
            while (cycle.back() != u) cycle.push_back(par[cycle.back()]);
            return true;
         }
         par[u] = v;
         if (find_cycle(u)) return true;
      }
      return false;
   };

   FOR (i, n) if (!vis[i]) if(find_cycle(i)) {
      cycle.insert(cycle.begin(), cycle.back());
      cout << cycle.size() << '\n';
      reverse(all(cycle));
      for (auto &c: cycle) cout << ++c << ' ';
      return;
   }
   cout << "IMPOSSIBLE\n";
}