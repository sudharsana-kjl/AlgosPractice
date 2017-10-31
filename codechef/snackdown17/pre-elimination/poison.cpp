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

struct snake
{
	ll idx,x1,y1,x2,y2,len,clenh,clenv;
};

bool vertical(ll x1,ll y1,ll x2,ll y2)
{
	if(y1==y2)
		return true;
	return false;
}
bool horizontal(ll x1,ll y1,ll x2,ll y2)
{
	if(x1==x2)
		return true;
	return false;
}
ll len(ll x1,ll x2)
{
	ll max,min;
	if(x1>x2)
		max=x1,min=x2;
	else max=x2,min=x1;
	return (max-min+1);
}
ll coverlen(ll p1,ll p2,ll k1,ll k2)
{
	// cout<<p1<<" "<<p2<<" "<<k1<<" "<<k2<<endl;
	if(k1<=p1&&p2<=k2)
		return (p2-p1+1);
	if(p1<=k1&&k2<=p2)
		return (k2-k1+1);
	if(p1<=k1&&k1<=p2&&p2<=k2)
		return (p2-k1+1);
	if(k1<=p1&&p1<=k2&&k2<=p2)
		return (k2-p1+1);
	return 0;
}
ll cx1,cx2,cy1,cy2;

ll coverangev(ll p1,ll p2,ll k1,ll k2)
{
	// cout<<p1<<" "<<p2<<" "<<k1<<" "<<k2<<endl;
	if(k1<=p1&&p2<=k2)
		cx1=p1,cx2=p2;
	if(p1<=k1&&k2<=p2)
		cx1=k1,cx2=k2;
	if(p1<=k1&&k1<=p2&&p2<=k2)
		cx1=k1,cx2=p2;
	if(k1<=p1&&p1<=k2&&k2<=p2)
		cx1=p1,cx2=k2;
	return 0;
}

ll coverangeh(ll p1,ll p2,ll k1,ll k2)
{
	// cout<<p1<<" "<<p2<<" "<<k1<<" "<<k2<<endl;
	if(k1<=p1&&p2<=k2)
		cy1=p1,cy2=p2;
	if(p1<=k1&&k2<=p2)
		cy1=k1,cy2=k2;
	if(p1<=k1&&k1<=p2&&p2<=k2)
		cy1=k1,cy2=p2;
	if(k1<=p1&&p1<=k2&&k2<=p2)
		cy1=p1,cy2=k2;
	return 0;
}

bool inRange(ll p1,ll p2,ll k1,ll k2)
{
	// cout<<p1<<" "<<p2<<" "<<k1<<" "<<k2<<endl;
	if((p1<k1&&p2<k1)||(k2<p1&&k2<p2))
		return false;
	else return true;
}

bool clencmph(snake one,snake two)
{
	if(one.y1==two.y1)
		return one.y2<two.y2;
	return one.y1<two.y1;
}

bool clencmpv(snake one,snake two)
{
	if(one.x1==two.x1)
		return one.x2<two.x2;
	return one.x1<two.x1;
}

ll Hy1,Hy2,Vx1,Vx2;
ll kx1,kx2,ky1,ky2;
bool updateH(ll y1,ll y2,ll ky1,ll ky2)
{
	if(Hy1==0&&Hy2==0)
		{Hy1=y1,Hy2=y2;return true;}
	
	if(ky1<=y1&&y1<=Hy1&&Hy2<=y2&&y2<=ky2)
		{Hy1=y1;Hy2=y2;return true;}
	
	if(ky1<=y1&&y1<=Hy1)
		{Hy1=y1;return true;}
	
	if(Hy2<=y2&&y2<=ky2)
		{Hy2=y2;return true;}
	return false;
}
bool updateV(ll x1,ll x2,ll kx1,ll kx2)
{
	if(Vx1==0&&Vx2==0)
		{Vx1=x1,Vx2=x2;return true;}
	
	if(kx1<=x1&&x1<=Vx1&&Vx2<=x2&&x2<=kx2)
		{Vx1=x1;Vx2=x2;return true;}
	
	if(kx1<=x1&&x1<=Vx1)
		{Vx1=x1;return true;}
	
	if(Vx2<=x2&&x2<=kx2)
		{Vx2=x2;return true;}
	return false;
}

ll funch(snake S[],ll n,ll X,ll Y)
{
	ll i,x,y,t,px,py,count=0;
	for(i=0;i<n;)
	{
		x=S[i].y1,y=S[i].y2;
		// cout<<"\nX:"<<X<<" "<<" Y:"<<Y;
		// cout<<endl<<x<<" "<<y;
		bool flag=false;
		while(x<=X&&X<=y&&i<n)
		{
			flag=true;
			px=x,py=y;
			// cout<<"\nintersects "<<x<<" "<<y;
			i+=1;
			x=S[i].y1,y=S[i].y2;
			cin>>t;
		}
		if(flag){
				count+=1;
				X=py+1;
				// cout<<"update X:"<<X;
			}
			else
			{
				i+=1;
			}
			if(X>Y)
				break;
		cin>>t;
	}
	// cout<<"LAST:"<<X;
	Hy2=X;
	return count;
}
ll funcv(snake S[],ll n,ll X,ll Y)
{
	ll i,x,y,py,px,t,count=0;
	for(i=0;i<n;)
	{
		x=S[i].x1,y=S[i].x2;
		// cout<<"\nX:"<<X<<" "<<" Y:"<<Y;
		// cout<<endl<<x<<" "<<y;
		bool flag=false;
		while(x<=X&&X<=y&&i<n)
		{
			flag=true;
			px=x,py=y;
			// cout<<"\nintersects "<<x<<" "<<y;
			i+=1;
			x=S[i].x1,y=S[i].x2;
			// cin>>t;
		}
		if(flag){
				count+=1;
				X=py+1;
				// cout<<"update X:"<<X;
			}
			else
			{
				i+=1;
			}
			if(X>Y)
				break;
		// cin>>t;

	}
	// cout<<"LAST:"<<X;
	Vx2=X;
	return count;
}

int main()
{
	ll t,i;cin>>t;
	while(t--)
	{
		ll N,K,M,snakecount;
		ll x1,x2,y1,y2;
		map<ll,ll>h;
		cin>>N>>K>>M;
		
		kx1=ky1=((N-K)/2+1);
		kx2=kx1+(K-1);ky2=ky1+(K-1);

		snake VS[M],HS[M];
		ll vsc=-1,hsc=-1;

		FOR1(i,M-1)
		{
			cx1=cx2=cy1=cy2=0;
			cin>>x1>>y1>>x2>>y2;
			// cout<<kx1<<" "<<kx2;
			if(inRange(x1,x2,kx1,kx2)||inRange(y1,y2,ky1,ky2))
			{
					coverangev(x1,x2,kx1,kx2);
					coverangeh(y1,y2,ky1,ky2);
				if(vertical(x1,y1,x2,y2))
				{	
					++vsc;
					// cout<<"V"<<" cx1:"<<cx1<<" cx2:"<<cx2<<" cy1:"<<cy1<<" cy2:"<<cy2<<" clenv:";
					VS[vsc].x1=cx1;VS[vsc].x2=cx2;
					VS[vsc].y2=cy2;VS[vsc].y1=cy1;
					VS[vsc].len=len(x1,x2);
					VS[vsc].clenv=coverlen(x1,x2,kx1,kx2);
					VS[vsc].clenh=coverlen(y1,y2,ky1,ky2);
					VS[i].idx=i;
					// cout<<VS[vsc].clenv<<" :"<<VS[vsc].clenh<<endl;
				}
				if(horizontal(x1,y1,x2,y2))
				{   ++hsc;
					// cout<<"H"<<" cx1:"<<cx1<<" cx2:"<<cx2<<" cy1:"<<cy1<<" cy2:"<<cy2<<" clenh:";
					HS[hsc].y2=cy2;HS[hsc].y1=cy1;
					HS[hsc].x1=cx1;HS[hsc].x2=cx2;
					HS[hsc].len=len(y1,y2);
					HS[hsc].clenh=coverlen(y1,y2,ky1,ky2);
					HS[hsc].clenv=coverlen(x1,x2,kx1,ky2);
					HS[i].idx=i;
					// cout<<HS[hsc].clenh<<" :"<<HS[hsc].clenv<<endl;
				}
			}

		}
		hsc+=1,vsc+=1;
		// cout<<"\nsnakes-V:"<<vsc<<" H:"<<hsc<<"\n";
		// cout<<"horizontal\n";
		// for(i=0;i<hsc;i++)
		// 	cout<<HS[i].len<<endl;

		// cout<<"vertical\n";
		// for(i=0;i<vsc;i++)
		// 	cout<<VS[i].len<<endl;

		sort(HS,HS+hsc,clencmph);
		sort(VS,VS+vsc,clencmpv);
		ll u,v;
		snakecount=0;
		snakecount+=funch(HS,hsc,kx1,kx2);
		// cout<<"\n------------------------\n";
		snakecount+=funcv(VS,vsc,ky1,ky2);
		// cout<<"-1 "<<Vx2<<" "<<kx2<<" "<<Hy2<<" "<<ky2<<endl;
		if(Vx2>kx2&&Hy2>ky2)
			cout<<"snakes:"<<snakecount<<endl;
		else
			cout<<"-1";
	}
	return 0;
}
