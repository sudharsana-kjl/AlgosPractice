//link to the qn: https://www.hackerrank.com/contests/world-codesprint-9/challenges/weighted-uniform-string

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
    string s;
    cin >> s;
    vector<long long int> count;
    int c=1;
    count.push_back((int)s[0]-96);
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1])
            c++;
        else c=1;
        count.push_back(((int)s[i]-96)*c);
        
    }
   // for(int j=0;j<count.size();j++)
   //     cout<<count[j];
    long long int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        long long int x;
        cin >> x;
        if(find(count.begin(),count.end(),x)!=count.end())
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        // your code goes here
       
    }
    return 0;
}

