#include<bits/stdc++.h>
using namespace std;
 
class graph
{ int v;
  list <int> *adj;
  public:
    graph(int v);
    void addEdge(int v,int w);
    void printvertexcover();
};

graph:: graph(int v)
 { this->v = v;
   adj = new list<int>[v];
 }

void graph:: addEdge(int v,int w)
{ adj[v].push_back(w);
  adj[w].push_back(v);
}

void graph:: printvertexcover()
{ bool visited[v];
  for(int i=0;i<v;i++)
    visited[i]=false;
  list<int>::iterator i;
  for(int u=0;u<v;u++)
   if(visited[u]==false)
    for(i=adj[u].begin();i!=adj[u].end();i++)
    { int vv = *i;
      if(visited[vv]==false)
      { visited[vv]=true;
        visited[u]=true;
        break;
      }
   }
   for(int i=0;i<v;i++)
     if(visited[i])
       cout<<i<<" ";
}

int main()
{ 
  int a[10][2];
  int n,m;
  cout<<"enter no of vertices ";
  cin>>m;
  graph g(m);
  cout<<"enter no of edges ";
  cin>>n;

  cout<<"enter edges ";
  
  for(int i=0;i<n;i++)
    for(int j=0;j<2;j++)
     cin>>a[i][j];
  for(int i=0;i<n;i++)
    g.addEdge(a[i][0],a[i][1]);  
     
   
  g.printvertexcover();
  return 0;
}
