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
		sort(ls.begin(),ls.end());
		while(q--)
		{	ll query;			     	
			cin>>query;
			ll pos,count,num;
			
			check = lower_bound (ls.begin(), ls.end(), query);
			if(check==ls.end()&& ls[n-1]+pos<query)
          		  { 
          		  	cout<<"0\n"; 
          		  	continue;
          		  }
 
      		pos = check - ls.begin();
      		while(1)
  			{
  				if(check==ls.begin())
					break;
 
  				check1 = upper_bound (ls.begin(),ls.end(),*(check-1));
				check2 = lower_bound (ls.begin(),ls.end(),*(check-1));			
				count = check1 - check2;
 
				if(pos-count > count*(query-*(check-1)))
				{
					pos = pos - count - count*(query-*(check-1));
					check = check - count;
				}
				else 
				 {	if(pos-count!=0)
	         		{
	           			check = check - (pos-count)/(query - *(check-1));
						pos = pos - ((pos - count)/(query - *(check-1)))*	(query - *(check-1)+1);
	            }
					 	check = check - pos/(query - *(check-1) + 1);
         // pos=0;
				 //	pos = pos - pos/(query - *(check-1) + 1) - pos/(query - *(check-1) + 1)*(query - *(check-1));
				// 	if(pos==count)
				// 	{
				// 		if(query-*(check-1)==1)
				// 		{
				// 			pos =pos - (count-(count/2));
    //            		        check = check - count/2;
				// 		}
				// 		else 
				// 		{
				// 			pos = pos -( count/(query - *(check-1)) + (count/(query-*(check-1)))*(query -*(check-1)));
				// 			check = check1 -(count/(query-*(check-1)));
				// 		}
				// 	}
 
				// 	while( pos-1>=(query-*(check-1)))
				// 	{
				// 	// {	cout<<"s";
				// 		pos = pos - 1 - (query-*(check-1));
				// 		check = check - 1;
 
					//}
					break;
				}
 
				// if(pos<=0 || pos<count*(query-*(check-1)))
				// {
				// 	break;
				// }
  			}
			
			
			cout<<n-(check-ls.begin())<<"\n";
			
		}
	}
	return 0;
}	
	 