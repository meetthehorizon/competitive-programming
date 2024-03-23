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

   queue<int> q;
   vector<int> dis(n, 0), par(n, -1);
   vector<bool> vis(n, false);

   q.push(0);
   while (!q.empty()) {
      int v = q.front(); q.pop();
      for (auto &u: adj[v]) if (!vis[u]) {
         par[u] = v;
         dis[u] = dis[v] + 1;
         vis[u] = true;
         q.push(u);
      }
   }

   if (par[n-1] == -1) {
      cout << "IMPOSSIBLE\n";
   } else {
      vector<int> pth{n-1};
      while (pth.back()) pth.push_back(par[pth.back()]);

      cout << pth.size() << '\n'; reverse(all(pth));
      for (auto &p: pth) cout << ++p << ' ';
   }

}