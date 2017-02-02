#include<iostream>
using namespace std;

int gcdExt(int x,int y,int *a,int *b)
{  if(x==0)
   { *a =0 ; *b =1;
      return y;
   }
   int a1,b1;
   int gcd = gcdExt(y%x,x,&a1,&b1);
   *a = b1 - (y/x)*a1;
   *b = a1;
   return gcd;
}

void modInverse(int x,int y)
{  int a,b;
   int g = gcdExt(x,y,&a,&b);
   if(g!=1) cout<<"Not coprimes";
   else 
   { cout<<a<<" "<<b<<" "<<(a%y + y)%y; }
}

int main()
{  int x,y;
   cin>>x>>y;
   modInverse(x,y);
   return 0;
}
