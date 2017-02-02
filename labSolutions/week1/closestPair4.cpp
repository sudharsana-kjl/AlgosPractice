#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{ vector<int> a;
  vector<int> diff;
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  { int t;
     cin>>t;
     a.push_back(t);
  } 
  sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++)
  { diff.push_back(a[i+1]-a[i]);}
    int min = min_element(diff.begin(),diff.end()) - diff.begin() ;
  cout<<"\n"<<a[min]<<" "<<a[min+1];
 // cout<<min;
//for(int i=0;i<n-1;i++)
  //cout<<diff[i];
return 0;
}
    
