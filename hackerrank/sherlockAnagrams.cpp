#include<bits/stdc++.h>
using namespace std;

/*int findanagram(string a, string b,int len){
    int count = 0;
    sort(a.begin(),a.end());
    for(int i=0;i<b.size()-len-1;i++){
        string sub = b.substr(i,len);
        sort(sub.begin(),sub.end());
        if(a.compare(sub)==0)
            count++;
    }
    return count;
}

int anagram(string s){
    int count = 0;
     cout<<"hello ";
    for(int i=0;i<s.size();i++){
        for(int j=1;j<s.size()-i;j++){
            //count += findanagram(s.substr(i,j),s.substr(i+1),j);
           
        }
    }
    return count;
}*/

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    while(t--){
        string s;
        cin>>s;
        cout<<s;
        //int ans = anagram(s);
    }
    return 0;
}

