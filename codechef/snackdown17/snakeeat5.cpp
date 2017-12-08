#include<bits/stdc++.h>
using namespace std;

#define ll long long int


ll findPos(int a[], ll k, ll n) {
	ll p = n, l=0, r=n-1, mid;
	while(l <= r) {
		mid = l + (r-l)/2;
		if(a[mid] == k) {
			if((mid != 0 && a[mid-1] != k) || mid == 0) {
				return mid;
			}
			r = mid-1;
			p = r;
		}
		else if(a[mid] > k) {
			p = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return p;
}

int main()
{ 
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		int ls[n];
		for(ll i=0;i<n;i++)
		{	
			cin>>ls[i];	
			//ls.push_back(t);
		}
		//vector<ll>::iterator check,check1,check2;
		sort(ls,ls+n);
		while(q--)
		{	ll query;			     	
			cin>>query;
			ll pos,count=0,needed,killed=0;
			
			//check = lower_bound (ls.begin(), ls.end(), query);
			//pos = check - ls.begin();
			pos = findPos(ls,query,n);
			
			count = n - pos;
			for(ll i=pos-1;i>=0;i--){
				if(ls[i]==1){
					count = count + ((i-killed+1)/query);
					break;
				}
				else {
					needed = query - ls[i];
					if(needed > (i-killed))
						break;
					count++;
					killed = killed + needed;
				}
			}
  			cout<<count<<"\n";
			
		}
	}
	return 0;
}	
	