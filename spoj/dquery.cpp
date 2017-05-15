#include<bits/stdc++.h>
using namespace std;

struct query
{
	long r,l,ans;
}qa[30000];

vector<int> a;
vector<int> answer;
vector<int> cnt;
int rootn, answ;

bool block(query a,query b)
{
    
  if(floor(a.l/rootn)<floor(b.l/rootn))
      return true;
  else if(floor(a.l/rootn)>floor(b.l/rootn))
      return false;
  return a.r<b.r;
}

void insert(int pos)
{
//	cout<<endl<<"add "<<a[pos];
	cnt[a[pos]]++;
 	if(cnt[a[pos]]==1)
		answ++;
	
}
void remove(int pos)
{
//	cout<<endl<<"rem "<<a[pos];
	cnt[a[pos]]--;
	if(cnt[a[pos]] == 0)
		answ--;
}

int main()
{ 
	
	long int i,n,t,q;
	cin>>n;
	answ=0;	
	while(n--&&(cin>>t))
      	a.push_back(t);
//	cout<<"enter q";
	cin>>q;// Read the number of queries
	for(i=0;i<q;i++)
   	{	long ll,rr;
 		cin>>ll>>rr;
		qa[i].l = ll-1;
		qa[i].r = rr - 1;// read all queries
		qa[i].ans = i;
 	}	
	for(i=0;i<q;i++)
	{	cnt.push_back(0);
		answer.push_back(0);
	}
	rootn=pow(a.size(),0.5);// find the number of blocks
//	cout<<"rootn is"<<rootn;
	sort(qa,qa+q,block);// now sort based on which block they belong and  resolve all conflicts by considering index r for each query 
	long currentL=0,currentR=0;
  //	cout<<"after sorting";
//	for(i=0;i<q;i++)
//		cout<<qa[i].l<<" "<<qa[i].r<<" "<<qa[i].ans<<"\n";	
	
	for(i=0;i<q;i++)
  	{
      		while(currentL<qa[i].l)
          	{	remove(currentL);currentL++; }
      		while(qa[i].l<currentL)
          	{	insert(currentL-1);currentL--; }
      		while(currentR<=qa[i].r)
           	{	insert(currentR);currentR++; }
      		while(currentR>qa[i].r+1)
          	{	remove(currentR-1);
			currentR--;
		}

      		answer[qa[i].ans]=answ;
  	}
	for(long i=0;i<q;i++)
		cout<<answer[i]<<endl;
	return 0;
}


