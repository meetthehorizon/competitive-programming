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
 
signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    if(test_cases) cin >> t;
    for(size_t i = 1; i <= t; i++){
    solve(i);
    }
return 0;
}


vector<long long> dijakstra(vector<vector<pair<int, long long>>> &adj, int s) {
	int n = adj.size();

	vector<long long> dis(n, INF); 
	using pli = pair<long long, long long>;
    priority_queue<pli, vector<pli>, greater<pli>> q;
	
	q.push({0LL, s}); dis[s] = 0;
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

	return dis;
}

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, m; cin >> n >> m;
    vector<vector<pair<int, long long>>> adj1(n), adj2(n);

    while (m--) {
    	int a, b; cin >> a >> b;
    	long long w; cin >> w;
    	adj1[--a].push_back({--b, w});
    	adj2[b].push_back({a, w});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    vector<long long> dis1 = dijakstra(adj1, 0), dis2 = dijakstra(adj2, n - 1);
    

	long long ans = INF;
	FOR (a, n) {
		for (auto &p: adj1[a]) {
			int b = p.first; long long w = p.second;
			ans = min(ans, dis1[a] + dis2[b] + (w >> 1));
		}
	}
	cout << ans << '\n';
}