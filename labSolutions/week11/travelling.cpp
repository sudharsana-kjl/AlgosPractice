#include<bits/stdc++.h>
using namespace std;

int sort_weight(bool mst[],int key[],int V)
{	
	int min=INT_MAX;
	int minindex;
	
	for(int i=0;i<V;i++)
	{
		if(key[i]<min && mst[i]==false)
			min=key[i],minindex=i;

	}
	return minindex;
}

void MST(int g[][20],int V)
{
	int parent[100];
	int key[100];
	bool mst[100];
	for(int i=0;i<V;i++)
		key[i]=INT_MAX,mst[i]=false;
	key[0]=0;
	int count;
	parent[0]=-1;
	count=V-1;
	for(int k=1;k<=count;k++)
	{
		int u=sort_weight(mst,key,V);
		mst[u]=true;
		for(int i=0;i<V;i++)
		{
			if(g[u][i] && mst[i]==false && g[u][i]<key[i])
				key[i]=g[u][i],parent[i]=u;
		}

	}

	int m[20][20];
	for(int i=1;i<V;i++)
	{

		m[parent[i]][i] = 1;
                m[i][parent[i]]=1;
	}
       
        int c[10],d[V];
        int mm=0;
        c[0]=mm;
        stack<int> st;
        st.push(mm);
        cout<<c[mm]<<" ";
        int top=0,h=0;    
        for(int i=0;i<V;i++)
         if(i!=mm)
           d[i]=0;
 	   d[mm]=1;
        int i;
        while(!st.empty())
        { int y = st.top();
          for(i=0;i<V;i++)
            if(m[y][i]>0&&d[i]==0)
              { h=1; break; }
          if(h==0)
           st.pop();
          else
          { st.push(i);
            cout<<i<<" ";
            d[i]=1;
          }
          h=0;
       }
	  cout<<mm;
         
}

int main()
{ int a[20][20];
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>a[i][j];
  MST(a,n);
  return 0;
}
