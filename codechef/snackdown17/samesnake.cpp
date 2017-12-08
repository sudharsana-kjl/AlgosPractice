#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
int main()
{
        ll t;
        cin>>t;
        while(t--)
        {
                ll x11,y11,x12,y12;
                cin>>x11>>y11>>x12>>y12;
                ll x21,y21,x22,y22;
                cin>>x21>>y21>>x22>>y22;
                
               if(((x21==x11) && (y21==y11)) || ((x21==x12) && (y21==y12)) || ((x22==x11) && (y22==y11)) || ((x22==x12) && (y22==y12)))
                                          {cout<<"yes\n";continue;}
              else if(y11==y12 && y12==y21 && y21==y22)
                { 
                	if(x11==x12 && x12==x21&& x21==x22)
                				{ cout<<"yes\n";continue;}
                	else if((x21>=x11 && x21<=x12)||(x22>=x11 && x22<=x12)||(x21>=x12 && x21<=x11)||(x22>=x12 && x22<=x11)||(x11>=x21 && x11<=x22)||(x12>=x21 && x12<=x22)||(x11>=x22 && x11<=x21)||(x12>=x22 && x12<=x21)) 
                        {cout<<"yes\n"; continue;}
                  else 	{cout<<"no\n";continue;}
                }
              else if(x11==x12&& x12==x21&&x21==x22)
                {// cout<<"l";
//			cout<<(y22>=y11 && y22<=y12);
                  if(y11==y12&& y12==y21&&y21==y22)
                        { cout<<"yes\n";continue;}
                  else if((y21>=y11 && y21<=y12)||(y22>=y11 && y22<=y12)||(y21>=y12 && y21<=y11) || (y22>=y12 && y22<=y11)||(y11>=y21 && y11<=y22)||(y12>=y21 && y12<=y22)||(y11>=y22 && y11<=y21) || (y12>=y22 && y12<=y21))    
                        {cout<<"yes\n"; continue;}
                  else 
                       	{cout<<"no\n";continue;}
                }
              else cout<<"no\n"; 
      }
      return 0;
}
 
 
