#include<iostream>
using namespace std;

int gcd(int x, int y)
{ while(x = x%y)
  { int t =x;
    x = y;
    y = t;
  }
  return y;
}


int n;
int a[100];
int findgcd(int res,int i)
{  while(i<=n-1) {
   res = gcd(res,gcd(res,a[i++]));
   
}
return res;
}
int main()
{ 
  
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  cout<<findgcd(a[0],0);
 return 0;
}
  
   
