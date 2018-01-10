#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll bsearch(vector<ll> a,ll low,ll high,ll key){
	
	while(low<=high){
		ll m = low + (high-low)/2;
//		cout<<m<<" "; 
		if(a[m] > key) high--;
		else if(a[m]<key && a[m+1] >= key || a[m]<key && m== a.size()-1){
			return a[m];
		}
		else low++;
	}
	return -1;
}

ll bsearchUtil(vector<ll> a,ll left,ll right,ll key){
	ll index = bsearch(a,left,right,key);
	if(index==-1){
		if(a[0]<key)
			index = a[0];
		else if(a[a.size()-1]<key)
			index = a[a.size()-1];
	}
	return index;
}

int main()
{
	
ll t;
cin>>t;
while(t--){

	ll n;
	cin>>n;
	vector<vector<ll> >arr(n);
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			ll t;
			cin>>t;
			arr[i].push_back(t);
		}
	}
	for(ll i=0;i<n;i++)
		sort(arr[i].begin(),arr[i].end());
	ll prev= arr[n-1][n-1];
	ll sum = prev;
	int f=0;
	ll num=0;
	for(int i=n-2;i>=0;i--){
		//num = *upper_bound(arr[i].begin(),arr[i].end(),prev);
//		cout<<"p"<<prev<<"n"<<num<<"s"<<sum<<" ";	
		//
		if(arr[i][n-1] < prev)
			num=arr[i][n-1];
		else
			num = bsearch(arr[i],0,n-1,prev);
		//cout<<"p"<<prev<<"n"<<num<<"s"<<sum<<" "; 
//		cout<<bsearchUtil(arr[i],0,n-1,prev);
		if(num==-1 && arr[i][0] < prev)
			num = arr[i][0];
	
		if(num==-1){
			f=1;break;
		}
		else{
			sum += num;
			prev = num;
		}
	}
	if(f==1) cout<<-1<<endl;
	else cout<<sum<<endl;
}		
return 0;
}
