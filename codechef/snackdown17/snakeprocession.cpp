#include<bits/stdc++.h>
using namespace std;

int main()
{
	long int t;
	cin>>t;
	while(t--) {
		long int n;
		string str;
		cin>>n;
		cin>>str;
		//cout<<str;
		stack<char> s;
		int f=0;
		for(string::iterator c = str.begin(); c != str.end(); ++c) {
		//	cout<<*c;
			if(*c=='H' && s.empty())
			{
			s.push(*c);
			}
			else if( *c=='T' && !s.empty())
				s.pop();		
			else if( *c!='.')
				f=1;
		}
		
		if(s.empty() && f==0) cout<<"Valid\n";
		else cout<<"Invalid\n";
		
	}
	return 0;
}

