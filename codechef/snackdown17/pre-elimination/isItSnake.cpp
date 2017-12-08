#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define G vector<vll >
#define F first
#define S second
#define pll pair<ll,ll>
#define FOR1(i,a) for(i=0;i<=a;i++)
#define FOR2(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
typedef long long ll;


int main()
{
	ll t,i,j,n;cin>>t;
	while(t--)
	{
		string s1,s2;
    		cin>>n;
		cin>>s1>>s2;
		bool start=false,end=false,flag=true;
    		ll count=0;
		
		for(i=0;i<n;i++)
    		{
			

			if(start&&s1[i]=='#'&&s2[i]=='.')
			{
				if(s1[i-1]!='#')
					{cout<<"no"<<endl;flag=false;break;}
			}
			if(start&&s1[i]=='.'&&s2[i]=='#')
			{
				
				if(s2[i-1]!='#')
					{cout<<"no"<<endl;flag=false;break;}
			}
			if(start&&i+1<=n&&s1[i]=='#'&&s2[i]=='#'&&s2[i+1]=='#'&&s1[i+1]=='.'&&s2[i-1]=='#'&&s1[i-1]=='.')
			{
				cout<<"no"<<endl;flag=false;break;
			}
			if(start&&i+1<=n&&s1[i]=='#'&&s2[i]=='#'&&s2[i+1]=='.'&&s1[i+1]=='#'&&s2[i-1]=='.'&&s1[i-1]=='#')
			{
				cout<<"no"<<endl;flag=false;break;
			}
			if(s1[i]=='.'&&s2[i]=='.'&&start)
			{	
				end=true;
			}
			
			if((s1[i]=='#'||s2[i]=='#')&&start==false)
			{	
				start=true;
			}

			if(end&&(s1[i]=='#'||s2[i]=='#'))
			{
				cout<<"no"<<endl;flag=false;break;
			}
	
			if(count==0&&s1[i]=='#'&&s2[i]=='#')
				count++;
      
      			if(s1[i-1]=='#'&&s2[i-1]=='#'&&s1[i]=='#'&&s2[i]=='#')
        			count++;
		}
		//cout<<"c"<<count;
    		if(count>1 && (count & 1)){ cout<<"no"<<endl;continue;}
			if(flag)
				cout<<"yes"<<endl;
    
	}
	
	return 0;
}
