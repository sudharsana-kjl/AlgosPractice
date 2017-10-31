#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define vll vector<ll>
#define G vector<vll >
#define F first
#define S second
#define pll pair<ll,ll>
#define RFOR(i,a,b) for(i=a;i>=b;i--)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define endl '\n'
#define clr(a) memset(a,0,sizeof(a))
#define all(x) x.begin(),x.end()
#define rll read_ll();
#define gc getchar
#define pc putchar

typedef int ll;
template<class T> inline T lcm(T a,T b){
        return a/gcd(a,b)*b;
}

ll read_ll(){char c=gc();while((c<'0'||c>'9')&&c!='-')c=gc();ll ret=0;int neg=0;if(c=='-')neg=1,c=gc();while(c>='0'&&c<='9'){ret=10*ret+c-48;c=gc();}return neg?-ret:ret;}

void make_set(vector<ll> &id, vector<ll> &rank, ll n) {
    for(ll i=1; i<=n; i++) {
        id[i] = i;
        rank[i] = 1;
    }
}

ll find_set(vector<ll> &id, ll p) {
    ll root = p;
    //find the root
    while(root != id[root]) {
        root = id[root];
    }
    //perform path compression
    while(p != root) {
        ll newp = id[p];
        id[p] = root;
        p = newp;
    }
    return root;
}

void merge_set(vector<ll> &id, vector<ll> &rank, ll x, ll y) {
    x = find_set(id, x);
    y = find_set(id, y);
    if(rank[x] > rank[y])
        id[y] = x;
    else
        id[x] = y;
    if(rank[x] == rank[y])
        rank[y] += 1;
}

void lps(vll s,ll n)
{
	ll i,j,l;
	ll dp[n][n];
	clr(dp);
	FOR(i,0,n-1)
		dp[i][i]=1;

	FOR(l,2,n)
	FOR(i,0,n-l+1)
	{
		j=i+l-1;
			if(s[i]==s[j]&&l==2)
				dp[i][j]=2;
			if(s[i]==s[j])
				dp[i][j]=dp[i+1][j-1]+2;
			else
				dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
		
	}
	cout<<dp[0][n-1];
}
int main()
{
	ll n,k,m,i;
	n=rll k=rll m=rll
	vector<ll> rank(n+1), id(n+1);
	make_set(id,rank,n);
	FOR(i,0,k-1)
	{
		ll u,v;
		u=rll v=rll
		if(find_set(id,u)!=find_set(id,v))
		merge_set(id,rank,u,v);
	}
	vll s;ll root,t;
	FOR(i,1,m)
	{
		cin>>t;
		root=find_set(id,t);
		s.pb(root);
	}
	lps(s,m);

	return 0;
}
