#include<stdio.h>
#include<limits.h>
#define inf INT_MAX
void youngify(int y[][4],int i,int j);
int extractmin(int y[][4]){
	int x;
	x=y[0][0];
	y[0][0]=inf;
	youngify(y,0,0);
	return x;
}
void youngify(int y[][4],int i,int j){
	int si=i;
	int sj=j;
	int tmp;
	if(i+1<4 && y[si][sj]>y[i+1][j])
	{
	si=i+1;
	sj=j;
	}
	if(j+1<4 && y[si][sj]>y[i][j+1]){
		si=i;
		sj=j+1;
	}
	if(si!=i||sj!=j){
		tmp=y[si][sj];
		y[si][sj]=y[i][j];
		y[i][j]=tmp;
		youngify(y,si,sj);
	}
}
int main(){
	int r,i,j,y[4][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
	r=extractmin(y);
	printf("result...%d\n",r);
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(y[i][j]==inf)
			printf("%d ",-1);
			else
			printf("%d ",y[i][j]);
		}
		printf("\n");
	}
	return 0;
}
