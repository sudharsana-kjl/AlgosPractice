#include<bits/stdc++.h>
using namespace std;

void sum(int a[][2],int b[][2],int c[][2])
{	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		c[i][j] = a[i][j]+b[i][j];
	}
}

void diffe(int a[][2],int b[][2],int c[][2])
{	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		c[i][j] = a[i][j]-b[i][j];
	}
}

void prod(int a[][2],int b[][2],int c[][2])
{	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		{	c[i][j]=0;
			for(int k=0;k<2;k++)
				c[i][j] = c[i][j]+ a[i][k]*b[k][j];
		}
	}
}

int main()
{	int a[20][20],b[20][20],c[20][20];
    	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{ for(int j=0;j<n;j++)
 		cin>>a[i][j];
	}
	for(int i=0;i<m;i++)
	{ for(int j=0;j<m;j++)
		cin>>b[i][j];
	}
	int a11[2][2],a12[2][2],a21[2][2],a22[2][2],b11[2][2],b12[2][2],b21[2][2],b22[2][2],c11[2][2],c12[2][2],c21[2][2],c22[2][2];
	int p1[2][2],p2[2][2],p3[2][2],p4[2][2],p5[2][2],p6[2][2],p7[2][2];
	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		{	a11[i][j]=a[i][j];
			b11[i][j]=b[i][j];
		}
	}
	for(int i=2;i<4;i++)
	{ for(int j=0;j<2;j++)
		{	a21[i-2][j]=a[i][j];
			b21[i-2][j]=b[i][j];
		}
	}
	for(int i=0;i<2;i++)
	{ for(int j=2;j<4;j++)
		{	a12[i][j-2]=a[i][j];
			b12[i][j-2]=b[i][j];
		}
	}
	for(int i=2;i<4;i++)
	{ for(int j=2;j<4;j++)
		{	a22[i-2][j-2]=a[i][j];
			b22[i-2][j-2]=b[i][j];
		}
	}
	cout<<endl;
	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		cout<<a11[i][j]<<" ";
		cout<<endl;
	}
		cout<<endl;
	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		cout<<a12[i][j]<<" ";
		cout<<endl;
	}	cout<<endl;
	
	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		cout<<a21[i][j]<<" ";
		cout<<endl;
	}	cout<<endl;
	
	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		cout<<a22[i][j]<<" ";
		cout<<endl;
	}	cout<<endl;
	
	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		cout<<b11[i][j]<<" ";
		cout<<endl;
	}	cout<<endl;
	
	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		cout<<b12[i][j]<<" ";
		cout<<endl;
	}	cout<<endl;
	
	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		cout<<b21[i][j]<<" ";
		cout<<endl;
	}	cout<<endl;
	
	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
		cout<<b22[i][j]<<" ";
		cout<<endl;
	}	cout<<endl;
	
	int temp1[2][2];
	int temp2[2][2];

	diffe(b12,b22,temp1);
	prod(a11,temp1,p1);

	sum(a11,a12,temp1);
	prod(temp1,b22,p2);

	sum(a21,a22,temp1);
	prod(temp1,b11,p3);

	diffe(b21,b11,temp1);
	prod(temp1,a22,p4);

	sum(a11,a22,temp1);
	sum(b11,b22,temp2);
	prod(temp1,temp2,p5);

	diffe(a12,a22,temp1);
	sum(b21,b22,temp2);
	prod(temp1,temp2,p6);

	diffe(a11,a21,temp1);
	sum(b11,b12,temp2);
	prod(temp1,temp2,p7);

	sum(p5,p4,temp1);
	diffe(temp1,p2,temp2);
	sum(temp2,p6,c11);

	sum(p1,p2,c12);

	sum(p3,p4,c21);

	sum(p1,p5,temp1);
	diffe(temp1,p3,temp2);
	diffe(temp2,p7,c22);

	for(int i=0;i<2;i++)
	{ for(int j=0;j<2;j++)
	  { c[i][j] = c11[i][j];
 	    c[i+2][j] = c21[i][j];
	    c[i][j+2] = c12[i][j];
            c[i+2][j+2] = c22[i][j];
	  }
	}

	for(int i=0;i<4;i++)
	{ for(int j=0;j<4;j++)
	    cout<<c[i][j]<<" ";
 	    cout<<endl;
	} 	
	return 0;
}


