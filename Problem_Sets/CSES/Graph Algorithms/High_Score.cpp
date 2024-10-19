/*
Kshitij Sharma
github: meetthehorizon
*/

#include <bits/stdc++.h> 
using namespace std; 

#define MOD 1000000007
#define INF LLONG_MAX
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


void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    int n, m; cin >> n >> m;
    vector<long long> dis(n, INF);
    vector<tuple<int, int, long long>> edges;
    vector<vector<int>> adj(n);

    dis[0] = 0;

    while (m--) {
    	int a = next<int>() - 1, b = next<int>() - 1;
    	long long weight = next<long long>();

    	adj[b].push_back(a);
    	edges.push_back({a, b, -weight});
    }

    FOR(_, n - 1) {
		int a, b; long long w;

    	for (auto &e: edges) {
    		tie(a, b, w) = e;
			if (dis[a] != INF)
                dis[b] = min(dis[b], dis[a] + w);
    	}
    }

    vector<bool> mark(n, false);
 	FOR(_, n) {
		int a, b; long long w;
		vector<long long> prev = dis;

    	for (auto &e: edges) {
    		tie(a, b, w) = e;

			if (dis[a] != INF)
                dis[b] = min(dis[b], dis[a] + w);
    	}

    	FOR (i, n) mark[i] = (dis[i] != prev[i]);
    }   

    bool inf = false;
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&] (int v) -> void {
    	if (mark[v]) inf = true;
    	vis[v] = true;

    	for (auto &u: adj[v]) 
    		if (!vis[u]) dfs(u);
    }; dfs(n-1);
    
	if (inf || (dis.back() == INF)) cout << "-1\n";
	else cout << -dis.back() << '\n';
}