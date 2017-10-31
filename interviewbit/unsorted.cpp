#include<bits/stdc++.h>
using namespace std;

int main(){
vector<int>A; //1, 2, 3, 5, 6, 13, 15, 16, 17, 13, 13, 15, 17, 17, 17, 17, 17, 19, 19 ]
A.push_back(1);
A.push_back(2);
A.push_back(3);
A.push_back(5);
A.push_back(6);
A.push_back(13);
A.push_back(15);
A.push_back(16);
A.push_back(17);
A.push_back(13);
A.push_back(13);
A.push_back(15);
A.push_back(17);
A.push_back(17);
A.push_back(17);
A.push_back(17);
A.push_back(17);
A.push_back(19);
A.push_back(19);

int n = A.size();
//cout<<n<<" ";
    int s,e;
    for(int i=0;i<n;i++){
        if(A[i]>A[i+1]){
            s = i;
            break;
        }
    }
    if(s==n-1){
	cout<< -1;
	return 0;
}
    for(int i=n-1;i>=0;i--){
        if(A[i-1]>A[i]){
            e = i;
            break;
        }
    }
    int max_e = *max_element(A.begin()+s,A.begin()+e);
    int min_e = *min_element(A.begin()+s,A.begin()+e);
    for(int i=0;i<s;i++){
        if(A[i]>min_e){
            s = i;
            break;
        }
    }
    int ec = e;
    for(int i=ec+1;i<n;i++){
        if(A[i]<max_e){
            e = i;
            
        }
    }
    cout<<s<<" "<<e;
	return 0;
}
