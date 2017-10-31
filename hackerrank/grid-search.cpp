#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0; G_i < R; G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0; P_i < r; P_i++){
           cin >> P[P_i];
        }
        int f=1;
        for(int i=0;i<R;i++){
            int sizet = G[i].find(P[0]);
            if(sizet!= G[i].npos){
                for(int pi=1;pi<r;pi++){
                    for(int pj=0;pj<c;pj++){
                        if(P[pi][pj] != G[i+pi][sizet+pj])
                            f=0;
                    }
                }
            }
               
        }
        if(!f) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}

