#include<bits/stdc++.h>
using namespace std;

int main() 
{
	long int s;
	cin>>s;
	while(s--)
	{
		long int n;
		cin>>n;
		long int a[n];
		for(long int i=0;i<n;i++)
			cin>>a[i];
		long int f=0,l=n-1;
		int flag=0;
		if(n%2==0) {flag=1;}
		else {
			if(a[n/2 + 1]==a[n/2] || a[n/2]==a[n/2 +2])
				flag=1;
			if(a[0]!=1) flag=1;
			for(int i=0;i<ceil(n/2);i++)
			{
				if(a[i+1]-a[i]!=1)
					flag=1;
				if(a[f]!=a[l])
					flag=1;
				f++;l--;
			}
		}
		if(flag==0) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}
