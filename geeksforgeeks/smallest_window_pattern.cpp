#include<bits/stdc++.h>
using namespace std;

int c1[256];
int c2[256];
void fillc2(string s2)
{
     for(int i=0;i<s2.length();i++)
    {
        c2[s2[i]]++;
    }
}
int smallestWindow(string s1,string s2)
{
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    fillc2(s2);
    int l2=s2.length(),l1=s1.length();
    int prev=0,curr=0;
    int len=0,minlen=INT_MAX;
    int c=0;  //for count
    while(c<l2 && curr<l1)
        {
            if(c2[s1[curr]]>0){
                c++;
                c2[s1[curr]]--;
            }
            c1[s1[curr]]++;
            curr++;
        }
    fillc2(s2);
    while(curr<l1)
    {
        len=curr-prev;
        if(len<minlen)
            minlen=len;
        while(curr<l1 && s1[curr]!=s1[prev]){
           c1[s1[curr]]++;
           curr++;
        }
        if(curr>=l1)
            break;
        else
        {
            c1[s1[curr++]]++;
        }
         while(c2[s1[prev]]<c1[s1[prev]]){
           c1[s1[prev]]--;
             prev++;
         }
    }
    return minlen;
}
// driver program to test above function
int main()
{	//it gives 13 for this input but actual answer is 6
    string s1="Ty name is Tanmay";
    string s2="Tanmay";
    int l=smallestWindow(s1,s2);
    cout<<l<<"\n";
    return 0;
}



