#include<bits/stdc++.h>
using namespace std;

struct block
{ int w;
  int v;
};

bool compare(block a,block b)
{ return ((float)a.v/a.w) > ((float)b.v/b.w); }

float fracknapsack(int n,int wt,block b[])
{
  sort(b,b+n,compare);
  for(int i=0;i<n;i++)
    cout<<b[i].w<<" "<<b[i].v<<endl;
  int s=0;
  int fv=0;
  for(int j=0;j<n;j++)
   {
  if(s+b[j].w<=wt){

//  for(int i=0;i<n;i++)
  while(s+b[j].w<=wt)
  { //if(s + b[i].w <=wt)
   // {
       s += b[j].w;
      fv +=b[j].v;
   // }
    //else
   // { // fv +=b[i].v*((float)(wt-s)/b[i].w);
//      break;
   // }
  }
}
  }
  return fv;
}


int main()
{ int n,wt;
  block b[100];

   cin>>n;
   for(int i=0;i<n;i++)
   { cin>>b[i].w>>b[i].v;
   }
   cin>>wt;
  cout<<fracknapsack(n,wt,b);
  return 0;
}

