#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;

// *****using vectors*****
//int main()
//{
//	vector<int> a;
//	int n,x;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		int t;
//		cin>>t;
//		a.push_back(t);
//	}
//	cin>>x;
//	for(int i=0;i<n;i++)
//	{ for(int j=0;j<n;j++)
//	  { if(a[i]+a[j]==x)
//		cout<<"\n"<<a[i]<<" "<<a[j];
//	  }
//	}
	
//return 0;

//}

//******using arrays****

struct res {
  int pair1;
  int pair2;
};

void merge(int a[],int L,int m, int R)
{  int i,j,k;
  int n1 = m-L+1;
  int n2 = R-m;
  int l[n1],r[n2];
  for(i=0;i<n1;i++)
   l[i] = a[L+i];
  for(j=0;j<n2;j++)
   r[j] = a[m+1+j];
  i=0; j=0; k=L;
  while(i<n1 && j<n2)
  { if(l[i]<=r[j])
    { a[k] = l[i];
      i++;
    }
    else 
    { a[k] = r[j];
      j++;
    }
    k++;
  }
  while(i<n1)
  { a[k] = l[i];
    i++; k++;
  }
  while(j<n2)
  { a[k] = r[j];
   j++;k++;
  }
}

void mergesort(int a[],int l, int r)
{  if(l<r)
   { int m = (l + r)/2;
      mergesort(a,l,m);
      mergesort(a,m+1,r);
      merge(a,l,m,r);
   }
}

int main()
{  int a[100],n,x;
  struct res re[100];
  cin>>n;
  int j=0;
  for(int i=0;i<n;i++)
  { cin>>a[i];}
  cin>>x;
  mergesort(a,0,n-1);
  int l =0;
  int r  = n-1;
int res1=0;
int res2=0;
  while(l<r)
  { if(a[l]+a[r] == x) 
    {res1 = a[l];res2 = a[r];
      //cout<<a[l]<<a[r]<<"\n";break;
      re[j].pair1 = a[l];
      re[j].pair2 = a[r];
      j++;
    }
    else if(a[l]+a[r]<x) l++;
    else r--;
  }
 for(int i=0;i<n;i++)
 cout<<a[i];
 for(int k=0;k<j;k++)
  cout<<re[k].pair1<<" "<<re[k].pair2<<"\n";
//cout<<"\n"<<res1<<" "<<res2;

return 0;
} 

