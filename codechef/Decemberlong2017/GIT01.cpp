#include<bits/stdc++.h>

using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		char a[m][n];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		}
		int T[m][n];
		T[0][0]='R';
		for(int i=1;i<m;i++){
			if(T[i-1][0]=='R') T[i][0]='G';
			else T[i][0]='R';
		}
		for(int i=0;i<m;i++){
			for(int j=1;j<n;j++){
				if(T[i][j-1]=='R') T[i][j]='G';
				else T[i][j]='R';
			}
		}
		int cost1=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(a[i][j] != T[i][j]){
					if(a[i][j]=='R') cost1 += 5;
					else cost1 += 3;
				}
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(T[i][j]=='R') T[i][j]='G';
				else T[i][j]='R';
			}
		}
		int cost2=0;
		for(int i=0;i<m;i++){
                        for(int j=0;j<n;j++){
                                if(a[i][j] != T[i][j]){
                                        if(a[i][j]=='R') cost2 += 5;
                                        else cost2 += 3;
                                }
                        }
                }
		cout<<min(cost1,cost2)<<endl;
	}
	return 0;
}

