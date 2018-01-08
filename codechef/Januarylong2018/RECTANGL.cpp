#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
int main()
{ 
	int n;
	cin>>n;
	while(n--){
		int arr[4];
		int f = -1;
		for(int i=0;i<4;i++){
			cin>>arr[i];
		}
		sort(arr,arr+4);
			if(arr[0]==arr[1] && arr[2]==arr[3] )
				f=1;
			else f=0;
		if(f==1)
			cout<<"YES"<<endl;
		else if(f==0) cout<<"NO"<<endl;
	}
	return 0;
}
