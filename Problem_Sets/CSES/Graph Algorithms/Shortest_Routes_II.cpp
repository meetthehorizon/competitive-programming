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
 
signed main(void)
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
   int n, m, q; cin >> n >> m >> q;
   vector<vector<long long>> adj(n, vector<long long> (n, INF));

   while (m--) {
      int a, b; cin >> a >> b; --a; --b;
      long long w; cin >> w;
      adj[a][b] = adj[b][a] = min(w, adj[a][b]);
   }

   FOR (i, n) adj[i][i] = 0LL;
   FOR(i, n) FOR(j, n) FOR(k, n) 
      adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);


   while (q--) {
      int x, y; cin >> x >> y;
      --x; --y;
      if (adj[x][y] != INF) cout << adj[x][y] << '\n';
      else cout << "-1\n";
   }
}