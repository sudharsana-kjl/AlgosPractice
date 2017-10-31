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
	ll t,i;cin>>t;
	while(t--)
	{
		string s;cin>>s;
		ll mc=0,sc=0;
		ll eaten=0;
		ll n=s.length();
		FOR1(i,n-1)
		{
			if(s[i]=='m')
			{
				mc+=1;
				if(i-1>=0&&s[i-1]=='s')
					eaten+=1;
				else if(i+1<=n-1&&s[i+1]=='s')
					eaten+=1;
			}
			else
			{
				sc+=1;
			}
		}
		sc=sc-(eaten);
		if(sc>mc)
			cout<<"snakes";
		else if (sc<mc)
			cout<<"mongooses";
		else
			cout<<"tie";
		cout<<endl;
	}
	return 0;
}

