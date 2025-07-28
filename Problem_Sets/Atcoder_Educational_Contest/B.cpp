/*
Kshitij Sharma
github: meetthehorizon
problem: 
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<pair<long long, long long>> vpll;

#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define PB push_back
#define PP pop_back
#define MOD 1000000007
#define INF 10000000000000000
#define F first
#define S second
#define MP make_pair

void print_vec(vector<ll> vec){for (auto &itr : vec) cout << itr << ' '; cout << '\n';}
ll maxll(ll a, ll b) {if(a>b) return a; return b;}
ll minll(ll a, ll b) {if(a>b) return b; return a;}
vll input_vec(ll n){vll vec(n); FOR(i, n) cin>>vec[i]; return vec;}
ll gcd(ll a, ll b) {if (a == 0) return b; return gcd(b % a, a);}
void yes() {cout<<"YES"<<'\n';}
void no() {cout<<"NO"<<'\n'; }
int next_2(int v){v--;v|=v>>1;v|=v>>2;v|=v>>4;v|=v>>8;v|=v>>16;v++;v+=(v==0);return v;}

void solve()
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    ll n, k;
    cin>>n>>k;
    vll h = input_vec(n);

    vll dp(n, INF); dp[0] = 0;

    FOR(i, n){
        FOR(j, k+1){ 
            if(i+j < n){
                dp[i+j] = minll(dp[j+i], dp[i] + abs(h[i] - h[j+i]));
            }
        }
    }

    cout<<dp.back();
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin>>t;
    for(ll i = 1; i <= t; i++){
        // cout<<"TEST CASE#"<<i<<'\n';
        solve();
    }
    return 0;
}
