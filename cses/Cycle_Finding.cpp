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

struct Edge {
	int a, b;
	long long w;

	Edge(int a=0, int b=0, long long w=0) : a(a), b(b), w(w) {}
};

void solve(int t)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
	int n, m; cin >> n >> m;
	vector<Edge> edges;

	while (m--) {
		int a, b; cin >> a >> b;
		long long w; cin >> w;
		edges.push_back(Edge(--a, --b, w));
	}

	vector<long long> dis(n, INF); dis[0] = 0;
	vector<long long> par(n, -1);

	int x;
	FOR (i, n) for (auto &e: edges) {
		x = -1;
		if ((dis[e.a] < INF) && (dis[e.b] > (dis[e.a] + e.w))) {
			dis[e.b] = dis[e.a] + e.w;
			par[e.b] = e.a;
			x = e.b;
		}
	}

	if (x == -1) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n"; 
	FOR(i, n) x = par[x];
	vector<int> cycle{x}; 

	while ((cycle.size() == 1) || (cycle[0] != cycle.back())) cycle.push_back(par[cycle.back()]);
	reverse(all(cycle));

	for (auto &c: cycle) cout << ++c << ' ';
}