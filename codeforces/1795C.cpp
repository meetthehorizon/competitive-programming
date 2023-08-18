/*
Kshitij Sharma
github: meetthehorizon
problem: 1795C


Editorial:
    bascially notice that each tea can have drinkers in the range 
    of its position i to some position i+x only.
    This means apply binary search to find that x for each tea.
    Rest is implementation
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<vector<long long>> vvll;
typedef pair<long long, long long> pll;
typedef map<long long, long long> mll;
typedef map<char, long long> mcll;

#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define FORP(i, a, b) for (ll(i) = (a); (i) <= (b); (i)++)
#define FORN(i, a, b) for (ll(i) = (a); (i) >= (b); (i)--)
#define PB push_back
#define PP pop_back
#define MOD 1000000007
#define F first
#define S second
#define MP make_pair

void print_vec(vector<ll> vec)
{
    for (auto &itr : vec)
    {
        cout << itr << ' ';
    }
    cout << '\n';
}
void print_vecpll(vector<pair<ll,ll>> vec){
    for(auto &itr:vec){
        cout<<itr.first<<':'<<itr.second<<' ';
    }
    cout<<'\n';
}
void update_max(ll &a, ll &b){
    if(b>a) a=b;
}
void update_min(ll &a, ll &b){
    if(a>b) a=b;
}
ll maxll(ll a, ll b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
ll minll(ll a, ll b)
{
    if (a > b)
    {   
        return b;
    }
    return a;
}
vpll input_vpll(ll n)
{
    vpll vec;
    FOR(i, n)
    {
        ll x, y;
        cin >> x >> y;
        vec.PB(MP(x, y));
    }
    return vec;
}
ll modular_inverse(ll x, ll M, ll y = -1)
{
    if (y == -1)
    {
        y = M - 2;
    }
    if (y == 0)
    {
        return 1;
    }
    ll p = modular_inverse(x, M, y / 2) % M;
    p = (p * p) % M;

    return (y % 2 == 0) ? p : (x * p) % M;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void yes() { cout << "YES" << '\n'; }
void no() { cout << "NO" << '\n'; }
void print_map(map<ll, ll> data)
{
    for (auto &itr : data)
    {
        cout << itr.first << ':' << itr.second << '\n';
    }
}
void print_set(set<ll> data)
{
    for (auto &itr : data)
    {
        cout << itr << '\n';
    }
    cout << '\n';
}
vector<long long> input_vec(long long n)
{
    vector<long long> vec;
    for (long long i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        vec.push_back(temp);
    }
    return vec;
}
long long binary_expo(long long a, long long b)
{
    ll ans = 1;
    for (ll i = 0; i < (log(b) / log(2)) + 1; i++)
    {
        if ((1 << i) & b)
        {
            ans *= a;
            ans%=MOD;
        }
        a *= a;
        ans%=MOD;
        a%=MOD;
    }
    return ans;
}
// Use Below Code to include nCr, also dont forget to add create_fac before cases loop starts

/*
const int N=100000000;
ll fact[N];
void create_fac(){
    for(ll i=0;i<N;i++){
        fact[i]=(fact[i-1]*(i+1))%MOD;
    }
}
ll combi(ll n,ll r){
    if(r>n){return 0;}
    ll ans=1;
    ans*=fact[n];
    ans*=modular_inverse(fact[r],MOD);
    ans%=MOD;
    ans*=modular_inverse(fact[r],MOD);
    ans%=MOD;
    return ans;
}*/


void solve()
{
    // CHILL BRO
    // I ASSUME YOU ARE HERE BECAUSE YOU HAVE A COMPLETE ALGORITHIM?
    ll n;
    cin>>n;
    vll tea = input_vec(n);
    vll peep = input_vec(n);
    FOR(i, n) if(i) peep[i] += peep[i-1];
    vll q(n, 0), r(n, 0);
    FOR(i, n){
        ll x = tea[i];
        if(i>0) x += peep[i-1];
        ll y = upper_bound(peep.begin(), peep.end(), x) - peep.begin();
        q[i]++;
        if(y<n) q[y]--;
        if(y<n) r[y] += x - (y>0?peep[y-1]:0);
    }
    FOR(i, n) if(i) q[i] += q[i-1];
    FOR(i, n) r[i] += q[i]*(peep[i] - (i>0?peep[i-1]:0));
    print_vec(r);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    FORP(cases, 1, t){
        // cout<<"TEST CASE#"<<cases<<'\n';
        solve();
    }
    return 0;
}
