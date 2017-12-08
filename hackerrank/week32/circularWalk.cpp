#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define F first
#define S second
#define pll pair<ll,ll>
#define FOR1(i,a) for(i=0;i<=a;i++)
#define FOR2(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
typedef long long ll;


ll bfs(vll R,vll visited,ll s,ll t,ll n)
{
	vll dist(n);
	queue<ll>q;
	q.push(s);
	dist[s]=0;visited[s]=true;
	while(!q.empty())
	{
		ll v=q.front();q.pop();
		// cout<<"\nV:"<<v;int o;cin>>o;
		//visited[v]=true;
		for(ll k=0;k<=R[v];k++)
		{
			ll u=(v+k)%n;
			// cout<<"\n->"<<R[v];
			if(!visited[u]){
        visited[u]=true;
				// cout<<"\nvisiting:"<<u<<" being at:"<<v;
				dist[u]=dist[v]+1;
				if(u==t){
					// cout<<"\nfrom:"<<u;
					return dist[u];}
				q.push(u);
			}

			ll uu=(n-k+v)%n;
			// cout<<"\nuu->"<<uu<<":"<<v;
      if(uu!=u)
			if(!visited[uu]){
        visited[uu]=true;
				// cout<<"\nvisiting:"<<uu<<" being at:"<<v;
				dist[uu]=dist[v]+1;
				if(uu==t){
					// cout<<"\nfrom:"<<u;
					return dist[uu];}
				q.push(uu);
			}
		}
	}
	return -1;
}

a: 1222333
C: 2222111 
// aabcabc
        ^
int main()
{
  ll i,n,s,t,g,seed,p;
  cin>>n>>s>>t;
	vll R(n),visited(n);
	ll init;
  cin>>init>>g>>seed>>p;
  R[0]=init;

  FOR2(i,1,n-1)
    {
    R[i]=(R[i-1]*g+seed)%p;
  }
  // cout<<endl;
    if((R[s]>=abs(s-t)||R[s]>=(n-t+s))&&t!=s)
  	cout<<"1";
  else
  if(R[s]==0&&t!=s)
  	cout<<"-1";
  else
  if(s!=t)
cout<<bfs(R,visited,s,t,n);
else
cout<<"0";
// cout<<endl;
//   for(auto&k:R)
//     cout<<k<<endl;
// 	return 0;
}
