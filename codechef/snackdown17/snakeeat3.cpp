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
		{	ll query;			     	cin>>query;
			ll pos;
			sort(ls.begin(),ls.end());
			check = lower_bound (ls.begin(), ls.end(), query);
     			ll count;
     			 pos = check - ls.begin();
			ll num;
//			cout<<ls[n-1];
			if(check==ls.end()&& ls[n-1]+pos<query)
          		  { cout<<"0\n"; break;}
		
			while(1)
			{
				check1 = upper_bound (ls.begin(),ls.end(),*(check-1));
				check2 = lower_bound (ls.begin(),ls.end(),*(check-1));
			
				count = check1 - check2;
				if(check==ls.begin())
					break;
				if(query - *(check-1)==1 && check2!=ls.begin()&&(pos-count > count))
					num=1*count;
				else if(query-*(check-1)==1 && pos-count<=count)
					num=0;
				else
				num = (pos- count)/(query - *(check-1));

				if(num==0)
				{	if( count!=1){
						if((query - *(check-1))==1)
						{
							pos =pos - (count-(count/2));
                                		        check = check - count/2;
						//	cout<<pos<<*check;
							break;
						}
						else{  if((query - *(check-1)) < pos)
							{ pos = pos -( count/(query - *(check-1)) + (count/(query-*(check-1)))*(query -*(check-1)));
							 check = check1 -(count/(query-*(check-1)));// count/(query - *(check-1));                                                   
							 break;
							}
							else break;
						}
					}
					else {
						if(pos-count<=count)
						{	pos =  pos =pos - (count-(count/2));
                                                        check = check - count/2;
							break;
						}
						else break;
					}
				}
				else if(num==1)
				{	pos = pos -(num+(query-*(check-1)));
                                        check = check-1;
					 if(pos<=0) break;
				}
				else if (num < (count))
				{	pos =pos - (num + num*(query - *(check-1)));
					check = check - num;//num*(query - *(check - 1));
					break;
				
				}
				else { pos = pos -(count+ count*(query - *(check-1)));
					check = check2;
					if(pos<=0) break;
				}
				
				if(pos<=0)
				{check = check1;break;}
				
     				
     			 }
			
			cout<<n-(check-ls.begin())<<"\n";
			
		}
	}
	return 0;
}	
