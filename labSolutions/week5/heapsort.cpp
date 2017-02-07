#include<iostream>
using namespace std;

void heapify(int a[],int n,int i){
	int tmp,t=i;
	int l=2*i;
	int r=2*i+1;
	if(l<=n && a[l]>a[t])
	t=l;
	if(r<=n && a[r]>a[t])
	t=r;
	if(t!=i){
		tmp=a[i];
		a[i]=a[t];
		a[t]=tmp;
		heapify(a,n,t);
	}
}
void heapsort(int a[],int n){
	int t,i;
	for(i=n/2;i>=1;i--){
		heapify(a,n,i);
	}
	for(i=n-1;i>=1 ;i--){
		t=a[1];
		a[1]=a[i+1];
		a[i+1]=t;
		heapify(a,i,1);
	}
}
int main(){
	int a[20],i,n;
	cin>>n;
	a[0]=-1;
	for(i=1;i<=n;i++)
	cin>>a[i];
	heapsort(a,n);
	for(i=1;i<=n;i++)
	cout<<a[i];
	return 0;
}
