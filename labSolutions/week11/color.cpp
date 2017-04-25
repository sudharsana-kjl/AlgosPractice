#include<bits/stdc++.h>
using namespace std;

int main()
{ int a[20][20],b[20],n,c[20];
  cin>>n;
  for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
     cin>>a[i][j];
  cout<<"enter color sequence ";
  for(int i=0;i<n;i++)
   { cin>>b[i];c[i]=-1; }
  int x,h,d[20],j,p=0;
  while(p<n)
  { x=b[p],h=0;
    for(j=0;j<n;j++)
      d[j]=0;
    for(int i=0;i<n;i++)
      if(a[x][i] > 0 && c[i]>=0)
        d[c[i]] = 1;
      for(j=0;j<n;j++)
       if(d[j]==0)
          break;
        c[x]=j;
        p++;
  }
  cout<<endl; 
  for(int i=0;i<n;i++)
   cout<<c[i]<<" ";
  return 0;
}   

  
