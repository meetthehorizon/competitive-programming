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
/* credits: dmkz (codeforces) */
int gen_base(const int before, const int after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed);
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}
using ull = unsigned long long;

struct PolyHash {
    static const int mod = (int)1e9+123; 
    static std::vector<int> pow1;        
    static std::vector<ull> pow2;        
    static int base;                     

    static inline int diff(int a, int b) { 
        return (a -= b) < 0 ? a + mod : a;
    }
 
    std::vector<int> pref1; 
    std::vector<ull> pref2;

    PolyHash(const std::string& s)
        : pref1(s.size()+1u, 0)
        , pref2(s.size()+1u, 0)
    {
        assert(base < mod);
        const int n = s.size(); 
        while ((int)pow1.size() <= n) {
            pow1.push_back(pow1.back() * base % mod);
            pow2.push_back(pow2.back() * base);
        }
        for (int i = 0; i < n; ++i) { 
            assert(base > s[i]);
            pref1[i+1] = (pref1[i] + 1LL * s[i] * pow1[i]) % mod;
            pref2[i+1] = pref2[i] + s[i] * pow2[i];
        }
    }
 
    inline std::pair<int, ull> operator()(const int pos, const int len, const int mxPow = 0) const {
        int hash1 = pref1[pos+len] - pref1[pos];
        ull hash2 = pref2[pos+len] - pref2[pos];
        if (hash1 < 0) hash1 += mod;
        if (mxPow != 0) {
            hash1 = 1LL * hash1 * pow1[mxPow-(pos+len-1)] % mod;
            hash2 *= pow2[mxPow-(pos+len-1)];
        }
        return std::make_pair(hash1, hash2);
    }
};
 
std::vector<int> PolyHash::pow1{1};
std::vector<ull> PolyHash::pow2{1};
int PolyHash::base = gen_base(256, PolyHash::mod);    

void solve(int test_num)
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    string s; cin >> s;
    int n = s.size(), mx = 0; s.append(s);

    PolyHash hash_s(s);
    for (int i = 1; i < n; ++i) {
        int l = 0, j = n;
        while(j) {
            do {
                l += j;
                if (l > n) break;

                if (hash_s(mx, l, n<<1) != hash_s(i, l, n<<1)) break;
            } while(1);
            l -= j, j >>= 1;
        }
        if (l != n) {
            mx = (s[mx+l] > s[i+l] ? i : mx);
        }
    }

    FOR(j, n) cout << s[mx+j];
}
