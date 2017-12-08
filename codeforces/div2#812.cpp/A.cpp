#include<bits/stdc++.h>
using namespace std;
int main()
{ int a[4][4];
  for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
		cin>>a[i][j];
	}
  
  }
  int f=0;
  for(int i=0;i<4;i++){
  for(int j=0;j<4;j++){
  if(a[i][j]==1 && a[i+1][j]==1 && a[i+2][j]==1 && a[i+3][j]==1)
	{ f=1;break; }
  if(a[i][j]==1 && a[i][j+1]==1 && a[i][j+2]==1 && a[i][j+3]==1)
        { f=1;break; }
  if(a[0][0]==1 && a[1][1]==1 && a[2][2]==1 && a[3][3]==1)
	{ f=1;break;}
  if(a[0][3]==1 && a[1][2]==1 && a[2][1]==1 && a[3][0]==1)
	{ f=1;break;}
  
   
 } }
int g=0;
for(int i=0;i<4;i++){
  for(int j=0;j<4;j++){
    if(a[i][j]!=0)
	g=1;
}}

  if(f==1 || g==0)
	cout<<"YES\n";
else 
	cout<<"NO\n";
  return 0;
}
