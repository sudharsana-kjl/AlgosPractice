#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

// int main()
// {
// 	int n;
// 	vector<int> a;
// 	vector<int> c;
// 	map<int,int> count;
// 	cin>>n;
// 	for(int i=0;i<n;i++)
// 	{int t;
// 		cin>>t;
// 		a.push_back(t);
// //cout<<"done";
// 		if(count[t])
// 			count[t]++;
// 		else
// 			count[t]=1;
// 		c.push_back(count[t]);
// 	}
// //	for(int i=0;i<n;i++)
// //		cout<<count[a[i]];
// int res = *max_element(c.begin(),c.end());
// cout<<res;
// return 0;

// }
	
int main(){
	int n;
	int a[100];
	int c[100] = {0};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	int max=c[0];
	for(int i=1;i<sizeof(c)/sizeof(c[0]);i++){
		if(c[i]>max)
			max=c[i];
	}
	cout<<max;
	return 0;
}	
 
 
