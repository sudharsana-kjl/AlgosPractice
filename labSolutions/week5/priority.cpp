#include <bits/stdc++.h>
using namespace std;
void max_heapify(int heap[],int i,int n)
{	
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<=n && heap[l]>heap[largest])
	{
		largest=l;

	}
	if(r<=n && heap[r]>heap[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		swap(heap[i],heap[largest]);
		max_heapify(heap,largest,n);
	}

}
void insert(int heap[],int i,int n)
{
	
    heap[i]=n;
	while(i>0 && heap[i/2]<heap[i])
		{
			swap(heap[i],heap[i/2]);
			i=i/2;
		}

}
void increase_key(int heap[],int i,int n)
{
	if(n<heap[i])
	{
		cout<<"\n not possible";
		return;
	}
    heap[i]=n;
	while(i>0 && heap[i/2]<heap[i])
		{
			swap(heap[i],heap[i/2]);
			i=i/2;
		}

}
int extract_max(int heap[],int & end)
{
	int max=heap[0];
	swap(heap[end],heap[0]);
	end=end-1;
	max_heapify(heap,0,end);
	return max;

}

int main()
{
	int heap[100];
	char c='y';int n;
	int length=-1;
	int val;
	while(c=='y')
	{
		cout<<"\n enter the value to be inserted";
		cin>>val;
		length=length+1;
		heap[length]=-1;
		insert(heap,length,val);
		cout<<"\n Enter y to continue and n to stop";
		cin>>c;
		

	}
	for(int i=0;i<=length;i++)
	{
		cout<<heap[i]<<" ";
	}
	
	int pos;int key;
	cout<<"Enter the position where you want to increase the key";
	cin>>pos;
	cout<<"Enter the increased key";
	cin>>key;
	increase_key(heap,pos,key);
	for(int i=0;i<=length;i++)
	{
		cout<<heap[i]<<" ";
	}
	
	cout<<"\n Enter the position of the value to be deleted";
	cin>>pos;
	swap(heap[pos],heap[length]);
	length=length-1;
	max_heapify(heap,pos,length);
	for(int i=0;i<=length;i++)
	{
		cout<<heap[i]<<" ";
	}
	cout<<extract_max(heap,length);
	for(int i=0;i<=length;i++)
	{
		cout<<heap[i]<<" ";
	}




	return 0;

}	

