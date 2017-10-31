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
		ll qu[q];
		for(ll i=0;i<n;i++)
		{	ll t;
			cin>>t;	
			ls.push_back(t);
		}
		for( ll i=0;i<q;i++)
		{	
			cin>>qu[i];
		}
		ll quer=0;
		vector<ll>::iterator it,check,check1;
		
		while(quer<q)
		{	
			ll count=0;
			ll kill =0;
			sort(ls.begin(),ls.end());
			it = ls.begin();
			int f=1;
			while(f)
			{
				 check = lower_bound (it, ls.end(), qu[quer]);
				if(*check==qu[quer])
					check--;
				check1 = upper_bound(it,ls.end(),*check);
					check1--;
				
				if(check - it <0) break;
			
				//count = n -(check - ls.begin());
				ll pos = check - ls.begin();
				ll pos1 = check1 - ls.begin();
				cout<<pos<<" "<<pos1<<" ";
				if(pos1 != pos) {
					if(pos1 - pos +1 <=pos1+1)
					{ count = n-pos-1+pos1;
						break;
					}	
				}
				
				if(*check + 1 == qu[quer])
					{
					*check++;it++; }
				else { count = n-pos;break;
				}
			}
		//`	if(count)
			cout<<count<<"\n";
			//else cout<<n-kill<<"\n";
			quer++;
		}
	}
	return 0;
}	
