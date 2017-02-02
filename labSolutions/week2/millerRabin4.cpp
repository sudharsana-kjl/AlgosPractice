#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

bool millerTest(int n,int d)
{  int a = 2 + rand()%(n-4);
   int x = pow(a,d);
    x=x%n;
   cout<<x<<" ";
   if(x==1 || x==n-1)
     return true;
   while(d!=n-1)
   { x = x*x;
     x = x%n;
     d=d*2;
     if(x==1) return false;
     if(x==n-1) return true;
   }
  return false;
} 

bool isPrime(int n, int a)
{ if(n<3)
  { if(n==1) { cout<<"Neither Prime nor Composite";return false; }
    if(n==2) return true;
  }
  else
  {  if(n%2 ==0)
       return false;
     int d = n-1;
     while(d%2 == 0)
       d=d/2;
     for(int i=0;i<a;i++)
       if(millerTest(d,n) == false)
          return false;
     return true;
  }
}


int main()
{ int n,a;
  cin>>n>>a;
  if(isPrime(n,a))
    cout<<"It's a prime number";
  else cout<<"It's not a prime number";
  return 0;
}
