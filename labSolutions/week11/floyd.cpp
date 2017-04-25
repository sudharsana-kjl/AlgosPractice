#include<bits/stdc++.h>
using namespace std;

int main()
{ int a[20][20],b[20][20],n;
  cin>>n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    { cin>>a[i][j];
      b[i][j]=a[i][j];
    }
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      { if(b[i][k] + b[k][j] <=b[i][j])
          b[i][j] = b[i][k]+b[k][j];
      }
  cout<<"distances are \n";
  for(int i=0;i<n;i++)
    { for(int j=0;j<n;j++)
     cout<<" "<<b[i][j];
     cout<<endl;
    }
  return 0;
} 
