//link to the problem: https://www.hackerrank.com/contests/world-codesprint-9/challenges/grading

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
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int grade;
        cin >> grade;
        // your code goes here
        if(grade%5 !=0)
        { if(grade<38)
            cout<<grade<<endl;
         else {
          if(5 - grade%5 < 3)
          {
           if(grade + 5 - grade%5<=100)
             {  grade = grade + 5 - grade%5;
               
             }
          }  
          cout<<grade<<endl;
         }
        }
        else cout<<grade<<endl;
        
        
    }
    return 0;
}

