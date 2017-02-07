#include<iostream>
using namespace std;

void heapify(int a[],int n, int i){
	int tmp,t=i;
	int l=2*i;
	int r=2*i+1;
	if(l<=n && a[l]>a[t])
	t=l;
	if(r<=n && a[r]>a[t])
	t=r;
	if(t!=i){
		tmp=a[t];
		a[t]=a[i];
		a[i]=tmp;
		heapify(a,n,t);
	}
}
void buildheap(int a[],int n){
	int i;
	for(i=n/2;i>=1;i--)
	heapify(a,n,i);
}
int heapextmax(int a[],int *hs){
	int max;
	if((*hs)<1)
	cout<<"Heap underflow";
	int hsize=(*hs);
	max=a[1];
	a[1]=a[hsize];
	hsize-=1;
	*hs=hsize;
	heapify(a,hsize,1);
	return max; 
}
void heapinckey(int a[],int pos,int key){
	int tmp;
	if(a[pos]>key)
	{
		cout<<"New key is smaller";
		return ;
	}
	a[pos]=key;
	int i=pos;
	while(i>1 && a[i/2]<a[i]){
		tmp=a[i];
		a[i]=a[i/2];
		a[i/2]=tmp;
		i=i/2;
	}
}
void maxheapins(int a[],int k,int n){
	a[n]=-9999;
	heapinckey(a,n,k);
}
int main(){
	int a[20],ins,len,pos,key,i,n;
	cin>>n;
	len=n;
	a[0]=-1;
	for(i=1;i<=n;i++)
	cin>>a[i];
	buildheap(a,n);
	for(i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<"Heap max.."<<a[1];
	cout<<"Heap max..."<<heapextmax(a,&n);
	for(i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<"Enter no to increase pos and key....";
	cin>>pos>>key;
	heapinckey(a,pos,key);
	for(i=1;i<=n;i++)
	cout<<a[i]<<" ";
	cout<<"Enter no to ins...";
	cin>>ins;
	n+=1;
	maxheapins(a,ins,n);
	for(i=1;i<=n;i++)
	cout<<a[i]<<" ";
	return 0;
}
