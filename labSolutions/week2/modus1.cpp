#include<iostream>
using namespace std;
int main()
{
	int a,x,n;
	cin>>a>>x>>n;
	int res = 1;
	a=a%n;
	for(int i=x;i>0;i=i/2){
	  if(i & 1)
 	    res = (res*a)%n;
 	  a = (a*a)%n;
 
	}
	cout<<res;
	return 0;
}
		
	
