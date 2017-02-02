#include<bits/stdc++.h>
using namespace std;

int main()
{ int t,c,d,l;
  vector<int> s;
  cin>>t;
  for(int i=0;i<t;i++)
  { cin>>c>>d>>l;
    if(l%4==0 && (c+d)*4>=l && ((c+d)*4-l)<=d*8)
      s.push_back(1);
    else s.push_back(0);
  }
  for(int j=0;j<s.size();j++)
    if(s[j])
      cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  return 0;
}
