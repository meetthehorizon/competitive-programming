#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int x[n-1];
        for(int i=0;i<n-1;i++){
            cin>>x[i];
        }
        int a[n];a[0]=x[0]+1;
        for(int i=1;i<n;i++){
            int k=1;
            while(i<n-1 && x[i-1]+a[i-1]*k<=x[i]) k++;
            a[i]=x[i-1]+a[i-1]*k;
        }
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}