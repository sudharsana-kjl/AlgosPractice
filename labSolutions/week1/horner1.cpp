#include <iostream>

#include <cmath>
using namespace std;

int main()
{
	int n,val;
	int x[100];
	cout<<"enter n";
	cin>>n;
	cout<<"enter poly";
	for(int i=0;i<=n;i++)
	{
		cin>>x[i];
	}
	cout<<"enter val";
	cin>>val;
	int res=x[0];
	for(int i=1;i<=n;i++)
	{
		res = res*val + x[i];
	}
	cout<<"result is ";
	cout<<res;
	return 0;
}
