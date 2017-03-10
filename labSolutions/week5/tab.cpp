#include <bits/stdc++.h>
using namespace std;
int extract_min(int a[100][100],int m,int n)
{
	int min=a[0][0];
	int cr=0;
	int cc=0;
	int nr,nc;
	a[cr][cc]=INT_MAX;
	int smallest;
	int inf=INT_MAX;
	while(true)
	{
		if(cr+1<m &&cr+1>=0 && a[cr+1][cr]<inf)
		{
			nr=cr+1;
			nc=cc;
			smallest=a[nr][nc];
		}
		else
		{
			smallest=inf;
		}
		if(cc+1<n && cc+1>=0 && a[cr][cc+1]<smallest )
		{
			nr=cr;
			nc=cc+1;
			smallest=a[nr][nc];

		}
		if(smallest==inf)
		{
			a[cr][cc]=inf;
			break;
		}

		swap(a[cr][cc],smallest);
		cr=nr;
		cc=nc;
	}
	return min;
}

int main()
{
	int m;
	int n;
	cin>>m;
	cin>>n;
	int a[100][100];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<extract_min(a,m,n)<<"\n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
