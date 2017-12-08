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

bool visited[1005][1005];
ll n,m;
int starti,startj,ti,tj;
vector<vector<char> >g(1005);

char adj[]={'L','R','U','D'};

bool can_go(char dir,ll si,ll sj)
{
	if(dir=='L'&&(sj-1)>=0)
		return true;
	if(dir=='R'&&(sj+1)<m)
		return true;
	if(dir=='U'&&(si-1)>=0)
		return true;
	if(dir=='D'&&(si+1)<n)
		return true;
	return false;
}

ll dfs(ll si,ll sj,char dir,ll turns)
{
	queue<pair<pll,pair<char,ll> > >q;
	q.push(mp(mp(si,sj),mp(dir,turns)));
	while(!q.empty())
	{
		pair<pll,pair<char,ll> > s=q.front();q.pop();
		si=s.F.F,sj=s.F.S;
		turns=s.S.S;
		dir=s.S.F;
		if(g[si][sj]=='T')
		{
			if(turns<=2&&turns>=0)
				{cout<<"YES";exit(0);}
		}
		ll nturns;
		// cout<<"\nAT: "<<si<<" "<<sj<<" "<<g[si][sj]<<" tns:"<<turns<<" cdir:"<<dir<<endl;ll t;cin>>t;
		
		for(auto&newdir:adj)
		{
			if(newdir!=dir)
				nturns=turns+1;
			else 
				nturns=turns;
			
			if(dir=='I')nturns=turns;

			if(can_go(newdir,si,sj))
			{
				// cout<<"going to "<<newdir<<" ntns:"<<nturns;
				if(newdir=='L'&&g[si][sj-1]!='*'&&!visited[si][sj-1])
					visited[si][sj-1]=true,q.push(mp(mp(si,sj-1),mp(newdir,nturns)));
	
				if(newdir=='R'&&g[si][sj+1]!='*'&&!visited[si][sj+1])
					visited[si][sj+1]=true,q.push(mp(mp(si,sj+1),mp(newdir,nturns)));

				if(newdir=='U'&&g[si-1][sj]!='*'&&!visited[si-1][sj])
					visited[si-1][sj]=true,q.push(mp(mp(si-1,sj),mp(newdir,nturns)));

				if(newdir=='D'&&g[si+1][sj]!='*'&&!visited[si+1][sj])
						visited[si+1][sj]=true,q.push(mp(mp(si+1,sj),mp(newdir,nturns)));
			}
		}
	}
}

int main()
{
	ll i,j;
	cin>>n>>m;
	char s;
	int starti,startj,ti,tj;
	FOR1(i,n-1)
	FOR1(j,m-1)
	{
		cin>>s;
		g[i].pb(s);
		if(s=='S')
			starti=i,startj=j;
		else if(s=='T')
			ti=i,tj=j;
	}
	visited[starti][startj]=true;

	dfs(starti,startj,'I',0);


	cout<<"NO";

	return 0;
}
