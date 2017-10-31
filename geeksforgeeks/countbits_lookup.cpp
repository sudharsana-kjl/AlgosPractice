#include<bits/stdc++.h>
using namespace std;

int main()
{ int Table[] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
  int n;
 cin>>n;
 int count = 0;
 for(;n;n>>=4)
	count =count + Table[ n & 0xF];
 cout<<count;
 return 0;
}
