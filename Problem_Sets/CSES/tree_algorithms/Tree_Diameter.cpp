    /*
    Kshitij Sharma
    github: meetthehorizon
       /\_/\
      (= ._.)
      / >  \>
    */

    #include <bits/stdc++.h> 
    using namespace std; 

    #define int long long
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
        int t = 1; if(test_cases) cin >> t;
        for(size_t i = 1; i <= t; i++)
            solve(i);
        return 0;
    }


    void solve(int t)
    {
        // CHILL BRO
        // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
        int n; cin >> n;
        vector<vector<int>> adj(n);

        FOR(i, n-1) {
            int x, y; cin >> x >> y;
            adj[--y].push_back(--x);
            adj[x].push_back(y);
        }

        int diam = 0;
        vector<bool> vis(n, false);
        function<int(int)> dfs = [&](int v) -> int {
            vis[v] = true;
            int x = 0, y = 0;

            for (auto u: adj[v]) if (!vis[u]) {
                int tmp = dfs(u);
                if (tmp > x) swap(tmp, x);
                if (tmp > y) swap(tmp, y);
            }

            diam = max(diam, 1 + x + y);
            return 1 + max(x, y);
        }; dfs(0);

        cout << --diam;
    }
