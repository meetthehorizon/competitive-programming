#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define nl "\n"
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<pair<ll,ll>> vpll;
#define pb push_back 
#define Sort(a) sort(a.begin(),a.end())
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9+7;
vvi child,edges;
vll dp;
ll ans;
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res%m;
}

ll modinv(ll a,ll m){
    return binpow(a,m-2,m);
}

void dfs1(int x){
    // cout<<child[x].size()<<nl;
    for(int y:child[x]){
        dp[y]=(dp[x]*modinv(child[x].size(),MOD))%MOD;
        dfs1(y);
        // cout<<y<<nl;
    }
}

void dfs2(int x,vi &curr){

    vi path=curr;
    reverse(all(path));
    int n2=path.size();
    for(int i=0;i<n2;i+=2){
        ll v=dp[path[i]];
        ll u=dp[path[i/2]];
        ans+=(u*modinv(v,MOD))%MOD;
        ans%=MOD;
    }
    for(int y:child[x]){
        curr.pb(y);
        dfs2(y,curr);
        curr.erase(find(all(curr),y));
    }
}
void edgestochild(int x,int par){
    for(int y:edges[x]){
        if(y!=par){
            child[x].pb(y);
            edgestochild(y,x);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    child=vvi(n+1);
    edges=vvi(n+1);
    for(int i=2;i<=n;i++){
        int u,v;
        cin>>u>>v;
        
        edges[u].pb(v);
        edges[v].pb(u);
    }
    edgestochild(1,0);
    dp=vll(n+1,-1);
    ans=0;
    vi curr;
    dp[1]=1;
    dfs1(1);
    curr.pb(1);
    dfs2(1,curr);
    cout<<ans<<nl;
}                     
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout<<modinv(2,MOD)<<nl;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}