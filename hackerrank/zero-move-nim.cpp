#include <bits/stdc++.h>
using namespace std;


int main(){
    int g;
    cin >> g;
    for(int a0 = 0; a0 < g; a0++){
        int n;
        cin >> n;
        vector<int> p(n);
       
       
        for(int p_i = 0;p_i < n;p_i++){
           cin >> p[p_i];
        }
        // your code goes here
         long int res;
        if(p[0]==0)
            res =0;
        else if(p[0]%2==0)
            res = p[0]-1;
            else res=p[0]+1;
        for(int i=1;i<n;i++) {
            if(p[i]==0)
                res = (int)(res^0);
            else if(p[i]%2==0) {
                res = (int)(res^(p[i]-1));
            }
                else res = (int)(res^(p[i]+1));
            }
        if(res==0) cout<<"L\n";
        else cout<<"W\n";
        }
        
        
    
    return 0;
}

