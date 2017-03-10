#include<bits/stdc++.h>
using namespace std;

void activityselection(int s[],int f[],int n)
{  int i=0;
    cout<<i<<" ";
   for(int j=0;j<n;j++)
   { if(s[j]>=f[i])
     { cout<<j<<" ";
       i=j;
     }
   }
}   

int main()
{ int s[100],f[100];
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>s[i]>>f[i];
  activityselection(s,f,n);
  return 0;
}
