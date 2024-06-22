/*
Kshitij Sharma
github: meetthehorizon
     /\_/\
    (= ._.)  ~~meow~~
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
struct TrieNode{
    bool isEnd;
    TrieNode* child[26];
 
    TrieNode(bool isEnd=false): isEnd(false) {
        for (int i = 0; i < 26; ++i)
            child[i] = nullptr;
    }
};
 
void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    string s; cin >> s;
    int n; cin >> n;
 
    TrieNode* root = new TrieNode();
    auto add = [&](string s) {
        auto curr = root;
        for (int i = 0; i < s.size(); ++i) {
            if (!curr->child[s[i]-'a'])
                curr->child[s[i]-'a'] = new TrieNode();
            curr = curr->child[s[i]-'a'];
        }
        curr->isEnd = true;
    };
 
    while(n--) add(next<string>()); n = s.size();
    int dp[n+1] {}; dp[0] = 1;
 
    for (int i = 0; i < n; ++i) {
        auto curr = root;
        for (int j = i; j < n; ++j) {
            if (curr->child[s[j]-'a'])
                curr = curr->child[s[j]-'a'];
            else break;
            if (curr->isEnd) dp[j+1] = (dp[i] + dp[j+1]) % MOD;
        }
    }
    cout << dp[n];
}
