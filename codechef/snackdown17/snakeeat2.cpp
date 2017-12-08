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
		vector<ll>::iterator check,check1,check2;
		
		while(q--)
		{	ll query;
		     	cin>>query;
			ll pos;
			sort(ls.begin(),ls.end());
			check = lower_bound (ls.begin(), ls.end(), query);
     			ll count;
     			 pos = check - ls.begin();
			ll num;
			if(check==ls.end())
          		  { cout<<"0\n"; break;}
		
			while(1)
			{
				check1 = upper_bound (ls.begin(),ls.end(),*(check-1));
				check2 = lower_bound (ls.begin(),ls.end(),*(check-1));
			
				count = check1 - check2;

				num = (pos- count)/(query - *(check-1));

				if(num==0)
				{	if( count!=1){
						if((query - *(check-1))==1)
						{
							pos =pos - 2*(count/2);
                                		        check = check - count/2;
							break;
						}
						else{
							pos = pos - count/(query - *(check-1));
							check = check - count/(query - *(check-1));
						}
					}
					else break;
				}
				else if(num < (pos - count))
				{	pos =pos - num - num*(query - *(check-1));
					check = check - num;
				
				}
				else { pos = pos - count*(query - *(check-1))-count;
					check = check - count;
				}
				if(pos<=0)
					break;
				
     				
     			 }
			
			cout<<n-(check-ls.begin())<<"\n";
			
		}
	}
	return 0;
}	
