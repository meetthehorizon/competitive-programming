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

void solve(long long);
bool test_cases = false;
template <typename T> T next() { T x; cin >> x; return x; }
 
int main(void)
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   long long t = 1;
   if(test_cases) cin >> t;
   for(size_t i = 1; i <= t; i++){
     solve(i);
   }
   return 0;
}


void solve(long long t)
{
   // CHILL BRO
   // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
   long long n, m; cin >> n >> m;
   vector<vector<pair<long long, long long>>> adj(n);

   while (m--) {
      long long x, y; cin >> x >> y;
      long long w; cin >> w;
      adj[--x].push_back({--y, w});
   }    

   vector<long long> dis(n, INF);
   using pli = pair<long long, long long>;
   priority_queue<pli, vector<pli>, greater<pli>> q;

   q.push({0, 0}); dis[0] = 0;
   while (!q.empty()) {
      long long v = q.top().second;
      long long d_v = q.top().first;
      q.pop();

      if (d_v != dis[v]) continue;
      for (auto &p: adj[v]) {
         long long to = p.first;
         long long len = p.second;

         if (dis[to] > (d_v + len)) {
            dis[to] = d_v + len;
            q.push({dis[to], to});
         }
      }
   }

   for (auto &d: dis) cout << d << ' ';
}