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


void solve(int t)
{
   // CHILL BRO
   // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
   int n, m, a; cin >> n >> m;
   vector<bool> block(n*m);
   vector<int> dis(n*m, INT_MAX);
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

   FOR (i, n*m) {
      char c = next<char>();

      if (c == 'M') { dis[i] = 0; q.push({0, i}); }
      else if (c == '#') block[i] = true;
      else if (c == 'A') a = i;
   }

   while (!q.empty()) {
      int v = q.top().second, d_v = q.top().first;
      q.pop();

      if (d_v != dis[v]) continue;
      vector<int> adj;

      if (v-m >= 0 && !block[v-m]) adj.push_back(v-m);
      if (v+m < m*n && !block[v+m]) adj.push_back(v+m);
      if (v%m && !block[v-1]) adj.push_back(v-1);
      if ((v%m != m-1) && !block[v+1]) adj.push_back(v+1);

      for (auto &u: adj) if (dis[u] > d_v + 1) {
         dis[u] = d_v + 1;
         q.push({dis[u], u});
      }
   }

   queue<int> p; 
   vector<bool> vis(n*m, false);
   vector<int> disa(n*m, INT_MAX), par(n*m, -1);
   p.push(a); vis[a] = true; disa[a] = 0;

   while (!p.empty()) {
      int v = p.front(); p.pop();

      vector<int> adj;
      if (v-m >= 0 && !block[v-m]) adj.push_back(v-m);
      if (v+m < m*n && !block[v+m]) adj.push_back(v+m);
      if (v%m && !block[v-1]) adj.push_back(v-1);
      if ((v%m != m-1) && !block[v+1]) adj.push_back(v+1);

      for (auto &u: adj) if (!vis[u]) {
         vis[u] = true;
         disa[u] = disa[v] + 1;
         par[u] = v;
         p.push(u);
      }
   }

   FOR (i, n*m) {
      if (i/m == 0 || i/m == n-1 || i%m == 0 || i%m == m-1) {
         if (!block[i] && disa[i] < dis[i]) {
            vector<int> path{(int) i};
            while (path.back() != a) 
               path.push_back(par[path.back()]);

            cout << "YES\n";
            cout << path.size() - 1 << '\n';
            for (int i = path.size() - 2; i >= 0; --i) {
               if (path[i+1] - path[i] == 1) cout << 'L';
               if (path[i+1] - path[i] == -1) cout << 'R';
               if (path[i+1] - path[i] == m) cout << 'U';
               if (path[i+1] - path[i] == -m) cout << 'D';
            }  

            return;
         }
      }
   }
   cout << "NO\n";
}