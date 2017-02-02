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
        vector<int> count(n+1,0);
        vector<int> people[n+1];
        int total = 0;
        for(int a1 = 0; a1 < m; a1++){
            int x;
            int y;
            cin >> x >> y;
      
            if(find(people[x].begin(),people[x].end(),y)==people[x].end())
              people[x].push_back(y);
            if(find(people[y].begin(),people[y].end(),x)==people[y].end())
              people[y].push_back(x);
              sort(people[x].begin(),people[x].end());
              sort(people[y].begin(),people[y].end());
            //vector<int> c;
           for(int i=1;i<n+1;i++){
              // if(i==x || i==y)
              //     continue;
            sort(people[i].begin(),people[i].end());
           
          
  std::vector<int> c(n+1);                      // 0  0  0  0  0  0  0  0  0  0
 std::vector<int>::iterator it;

               if(find(people[i].begin(),people[i].end(),x)!=people[i].end()){
                   
                   
                    it=std::set_union(people[i].begin(),people[i].end(),people[x].begin(),people[x].end(),c.begin());
                   c.resize(it-c.begin());
                   c.erase(std::remove(c.begin(), c.end(), i), c.end());
                 
                 people[i] = c;
                   // for(int j=0;j<people[i].size();j++)
                     //   cout<<people[i][j];
                    //cout<<endl;
                    
         
                
            }
            else  if(find(people[i].begin(),people[i].end(),y)!=people[i].end()){
             
                  
                    it=std::set_union(people[i].begin(),people[i].end(),people[y].begin(),people[y].end(),c.begin());
                   c.resize(it-c.begin());
                    c.erase(std::remove(c.begin(), c.end(), i), c.end());

                   people[i] = c;
                    //for(int j=0;j<people[i].size();j++)
                      //  cout<<people[i][j];
                    //cout<<endl;
         
            }
          
            // cout<<" "<<i<<" : "; 
            // for(int j=0;j<people[i].size();j++)
            //             cout<<people[i][j]<<" ";
            //   cout<<endl; 
            count[i] = people[i].size();    
           }
           // count[x] = people[x].size();
           //  count[y] = people[y].size();
             int sum =0;
    for(int i=0; i<n;i++)
       sum = sum + count[i];
        total = total + sum;
        }
        cout<<total;
    }
   
    return 0;
}
