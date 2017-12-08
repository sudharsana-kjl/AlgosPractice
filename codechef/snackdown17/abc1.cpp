#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
int main()
{ 
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q;
		cin>>n>>q;
		vector<ll> ls;
		for(ll i=0;i<n;i++)
		{	ll t;
			cin>>t;	
			ls.push_back(t);
		}
		vector<ll>::iterator check;
		sort(ls.begin(),ls.end());
		while(q--)
		{	ll query;
     	cin>>query;
			ll pos;
			
			check = lower_bound (ls.begin(), ls.end(), query);
			if(check==ls.begin())
			{ cout<<n;continue;}
     
      
			if(check==ls.end() && ls[n-1]+pos<query)
            { cout<<"0\n";continue;}
			else if(check==ls.end())
				check--;
			else check--;
			pos = check - ls.begin();		
			while(1)
			{
//			cout<<pos;
     		pos = pos -(query - *(check));
     			if(pos>=0) {check--;//pos--;
     			}
 
				if(pos<0){ check++;break;}
      }
			
			cout<<n-(check-ls.begin())<<"\n";
			
		}
	}
	return 0;
}	
