#include<bits/stdc++.h>
using namespace std;

bool wayToSort(int i, int j) { return i > j; }

int knapsack(int n,int wt,int w[],int v[])
{  if(n==0 || wt==0)
     return 0;
   if(w[n-1]>wt)
     return knapsack(n-1,wt,w,v);
   else return max( v[n-1] + knapsack(n-1,wt - w[n-1],w,v),knapsack(n-1,wt,w,v));
}
int main()
{ int n,wt,w[100],v[100];
  cin>>n;
  for(int i=0;i<n;i++)
   { cin>>w[i]>>v[i];}
  cin>>wt;
  //sort(w,w+n,wayToSort);
 // sort(v,v+n,wayToSort);
 cout<< knapsack(n,wt,w,v);
  return 0;
}
 
