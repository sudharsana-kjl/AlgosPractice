#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll sumcheck(ll n){
	ll odd=0;
	ll even=0;
	while(n){
		if((n%10)%2) odd += n%10;
		else even += n%10;
		n=n/10;
	}
	return abs(even-odd);
}

int main(){
	cout<<sumcheck(3216);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll res=0;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				cout<<sumcheck(i+j)<<" ";
				res += sumcheck(i+j);
			}
			cout<<"::"<<res<<"::"<<endl;
		}
		cout<<res;
	}
	return 0;
}

