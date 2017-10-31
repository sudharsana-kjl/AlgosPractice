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
		vector<ll>::iterator check,check1;
		
		while(quer<q)
		{	
			ll pos;
			//ll kill =0;
//			sort(ls.begin(),ls.end());
		//	it = ls.begin();
			//int f=1;
			while(1)
			{//cout<<"s";
				sort(ls.begin(),ls.end());	
				 check = lower_bound (ls.begin(), ls.end(), qu[quer]);
					pos = check - ls.begin();
				if(*check==qu[quer])
					check--;
				
				check1 = lower_bound(ls.begin(),ls.end(),*check);
				
				if(*check1==*check)
					check1--;
				
			//	cout<<*check<<" ";
                          //      cout<<*check1<<" ";
			//	pos = check - ls.begin()+1;
				cout<<pos;
				if(*check == -1 || *check1 ==-1)
					break;
				else if(*check + 1 == qu[quer])
				{//	pos = check - ls.begin();
				//	pos--;
					cout<<*check;
					cout<<*check1;
					cout<<pos;
				 	*check1 = -1;
					*check=*check+1;
				 }
					else break;
			//f++;
				//if(check - it <0) break;
			
				//count = n -(check - ls.begin());
				//ll pos = check - ls.begin();
				//ll pos1 = check1 - ls.begin();

		// 		cout<<pos<<" "<<pos1<<" ";
		// 		if(pos1 != pos) {
		// 			if(pos1 - pos +1 <=pos1+1)
		// 			{ count = n-pos-1+pos1;
		// 				break;
		// 			}	
		// 		}
				
		// 		if(*check + 1 == qu[quer])
		// 			{
		// 			*check++;it++; }
		// 		else { count = n-pos;break;
		// 		}
	//	pos = check - ls.begin();
		}
		// //`	if(count)
			cout<<n-pos<<"\n";
			//else cout<<n-kill<<"\n";
			quer++;
		}
	}
	return 0;
}	
