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
  int s=0;
  float fv=0.0;
  for(int i=0;i<n;i++)
  { if(s + b[i].w <=wt)
    { s += b[i].w;
      fv +=b[i].v;
    }
    else
    { fv +=b[i].v*((float)(wt-s)/b[i].w);
      break;
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
