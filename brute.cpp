#include<bits/stdc++.h>
#include <set>
#include <iostream>
#include <vector> 
#include <iostream>
#include <climits>

#include <map>

#define rp(i,a,n) for(int i=a;i<n;i++)
#define rep(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define ld long double
#define int long long
#define vi vector<ll>
#define mii map<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define nl endl
#define Nl endl
#define f first
#define s second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()
#define lb(a,b) lower_bound((a).begin(),(a).end(),b)
const ll M = 1000000007;
const ll inf =2e18;
using namespace std;

void solve()
{
    int n,k;cin>>n>>k;
    int leftspace=n;
    for (int i = 0; i < k; i++)
    {
        int a,b;cin>>a>>b;
        if (a==b)
        {
            leftspace-=1;
        }else leftspace-=2;
        
    }
    int dp[leftspace+1];
    // cout<<leftspace<<nl;
    for (int i = 0; i <=leftspace; i++)
    {
        dp[i]=0;
    }
    dp[0]=1;

    for (int i = 0; i < leftspace; i++)
    {
        dp[i+1]=(dp[i]+dp[i+1])%M;

        // if(i+1==2)cout<<dp[i]<<nl;
        if((i+2)<=(leftspace)){
            dp[i+2]+=(dp[i]*((i+1)*2))%M;
            dp[i+2]%=M;
        }
        // cout<<dp[3]<<nl;
    }
    // dp[leftspace]=1;
    // for (int i = leftspace; i >=0; i--)
    // {
    //     if(i-1>=0)
    //         dp[i-1]+=dp[i];
    //         if(i-2>=0)
    //         dp[i-2]+=(dp[i])*(i-1);
    // }
    
    // for (int i = 0; i < leftspace; i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    
    
    cout<<dp[leftspace]%M<<nl;
    
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    
    while(t--){
        solve();
    }

    return 0;}