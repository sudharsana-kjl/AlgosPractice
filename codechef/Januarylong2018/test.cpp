#include<bits/stdc++.h>
using namespace std;

int main()
{ vector<int>a;
a.push_back(2);
a.push_back(2);
  cout<<*lower_bound(a.begin(),a.end(),3);
return 0;
}
