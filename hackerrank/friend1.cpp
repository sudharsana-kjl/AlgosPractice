#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        cin >> n >> m;
       bool fm[n+1][n+1];
       for(int i=1;i<n;i++){
        for(int j=1;j<n;j++)
            fm[i][j] = false;
       }
        int total = 0;
        for(int a1 = 0; a1 < m; a1++){
            int x;
            int y;
            cin >> x >> y;
            if(fm[x][y]==false)
                {
                    fm[x][y] = true;
                    fm[y][x] = true;
                }
            for(int i=1;i<n;i++){
                if(i!=y){
                if(fm[x][i]== true)
                   { fm[i][y] = true; fm[y][i] = true;
                    }
                }
                if(i!=x){
                
                if(fm[y][i] == true)
                   { fm[i][x] = true; fm[x][i] = true;
                    }

                }
            }
            int sum = 0;
            for(int i=1;i<n;i++){
                for(int j=1;j<n;j++){
                    //cout<<fm[i][j]<<" ";
                     if(fm[i][j]== true)
                         sum++;
                }
                //cout<<endl;
            }
         //sum = sum*2;
            
        total = total + sum;
        }
        cout<<total;
    }
   
    return 0;
}
