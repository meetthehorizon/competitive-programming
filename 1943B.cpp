#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

#define int long long

void Solve() 
{
    int n, q; cin >> n >> q;

    string s; cin >> s;
    auto v = manacher(s);
    for (auto &x : v) x--;

    // we also need to know if all same, and all alternating 
    set <int> s1, s2;
    for (int i = 0; i < n - 1; i++){
        if (s[i] != s[i + 1]) s1.insert(i);
        if (i != n - 1 && s[i] != s[i + 2]) s2.insert(i);
    }

    while (q--){
        int l, r; cin >> l >> r;
        l--;
        r--;

        if (l == r){
            cout << 0 << "\n";
            continue;
        }
        
        int len = r - l + 1;

        int ans;
        auto it = s1.lower_bound(l);
        if (it == s1.end() || (*it) >= r){
            ans = 0;
        } else {
            it = s2.lower_bound(l);
            if (it == s2.end() || (*it) >= r - 1){
                ans = ((len - 1)/ 2) * (((len - 1) / 2) + 1);
            } else {
                ans =  len * (len - 1) / 2 - 1;
            }
        }

        if (v[l + r] < (r - l + 1)) ans += len;

        cout << ans << "\n";
    }
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}