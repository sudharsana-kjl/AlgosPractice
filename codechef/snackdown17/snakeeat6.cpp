#include <iostream>
#include <algorithm>
 
#define ll long long
 
using namespace std;
 
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
 
int main() {
	ll t;
	cin>>t;
	while(t--) {
		ll n, q;
		cin>>n>>q;
		int a[n];
		for(ll i=0; i<n; i++)
			cin>>a[i];
		sort(a, a+n);
		while(q--) {
			ll k, c=0, z, sc = 0;
			cin>>k;
			ll p = findPos(a, k, n);
			//cout<<"P"<<p<<" ";
			c += (n-p);
			for(ll i=p-1; i>=0; i--) {
				if(a[i] == 1) {
					c += ((i-sc+1)/k);
					break;
				}
				z = k-a[i];
				if(z > i-sc)
					break;
				c++;
				sc += z;
			}
			cout<<c<<endl;
		}
	}
} 

