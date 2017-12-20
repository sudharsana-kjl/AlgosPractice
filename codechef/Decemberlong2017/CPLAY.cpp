#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll movesleft1(ll i){
	ll m=0;
	ll j;

	for(j=i+1;j<10;j++)
		if(j%2==0) m++;
	return m;
}

ll movesleft2(ll i){
	ll m=0;
        for(ll j=i+1;j<10;j++)
                if(j%2!=0) m++;
        return m;
}


int main()
{
	string str;
	while(getline(cin,str)){
		//cout<<str;
		ll score1=0;
		ll  score2=0;
		ll res=0;
		ll count=0;
		ll i=0;
	//	cout<<str[0]<<str[1]<<" ";
/*		for(i=0;i<10;i++){
			if( i%2==0 && str[i]=='1') score1++;
			if( i%2!=0 && str[i]=='1') score2++;
			if((abs(score1 - score2) >=3 && i>=5) || ((score2-score1) >1 && i>=6) || ((score1 - score2)>1 && i>=7) ||((score2-score1)>0 && i>=8)){
				if(score1>score2){ res=1;count=i+1;break; }
				else { res=2;count=i+1;break; }
			}
//			cout<<score1<<score2<<i<<" ";
		}
		if(abs(score1 - score2) && res==0 ){
			if(score1 > score2) res=1;
			else res=2;
		}*/
		for(i=0;i<10;i++){
			if(i%2==0 && str[i]=='1') score1++;
			if(i%2!=0 && str[i]=='1') score2++;
			if((score1 > score2) && movesleft2(i) <(score1 - score2)) { res=1;count=i+1;break;}
			if((score2 > score1) && movesleft1(i) < (score2 - score1)) { res=2;count=i+1;break;}
//			cout<<score1<<"::"<<score2<<"::"<<i<<"::"<<movesleft1(i)<<"::"<<movesleft2(i)<<" ";
		}
		if(score1 > score2 && !res) {res=1;count=10;break;}
		if(score2 > score1 && !res) {res=2;count=10;break;}
		if(!res){
		
		//cout<<score1<<" "<<score2<<" ";		
		for(i=10;i<20;i++){
			if(i%2==0 && str[i]=='1') score1++;
                        if(i%2!=0 && str[i]=='1') score2++;
                        if(abs(score1 - score2) > 0 && i%2!=0){
                                if(score1>score2){ res=1;count=i+1;break; }
                                else { res=2;count=i+1;break; }
                        }
			if(abs(score1 - score2) >=2){
                                if(score1>score2){ res=1;count=i+1;break; }
                                else { res=2;count=i+1;break; }
                        }
//			cout<<score1<<score2<<i<<" ";
                }
		}

		if(res==1) cout<<"TEAM-A "<<count<<endl;
		else if(res==2) cout<<"TEAM-B "<<count<<endl;
		else cout<<"TIE"<<endl;
	}
	return 0;
}

