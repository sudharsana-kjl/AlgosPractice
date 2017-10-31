#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
        cin>>a[i];
    ll dp[n];
    for(ll i=0;i<n;i++)
        dp[i]=1;
   
    for(ll i=1;i<n;i++){
//	cout<<a[i]<<" ";
        if(a[i]>a[i-1])
            dp[i]=dp[i-1]+1;
        else {
            for(ll j=i-1;j>=0;j--){
                if(a[j]>a[j+1])
                    dp[j]=max(dp[j+1]+1,dp[j]);
                else break;
            }  
        }
    }
    
//      cout<<"end";
    ll sum=0;
    for(ll i=0;i<n;i++)
        sum+=dp[i];
    cout<<sum;
    return 0;
}

