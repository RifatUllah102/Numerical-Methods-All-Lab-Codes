#include<iostream>
#include<cmath>
#include<cstdio>
#include<windows.h>

using namespace std;

int main()
{
	int i,j,n,l=1,s;
	float p_x,p_y,p_z,n_x,n_y,n_z,p,q,r,Ea_x,Ea_y,Ea_z;
	float a[3][3],b[3],c[3],d;

	int k=1;
	for(i=0;i<3;i++){
		cout<<"Enter  "<<k<<" No equation"<<endl;
		for(j=0;j<3;j++){
			cout<<endl<<j<<" No coefficient: ";
			cin>>a[i][j];
		}
		cout<<endl<<"constant: "<<endl;
		cin>>b[i];
		k++;
	}
	if(a[0][0]==0){
		for(i=1;i<3;i++){
			if(a[i][0]!=0){
				s=i;
				break;
			}
		}
		for(i=0;i<3;i++){
			c[i]=a[s][i];
			a[s][i]=a[0][i];
			a[0][i]=c[i];
		}
		d=b[s];
		b[s]=b[0];
		b[0]=d;
	}
	float g;
	g=a[0][0];
	for(i=0;i<3;i++){
		a[0][i]=a[0][i]/g;
	}
	b[0]=b[0]/g;

	if(a[1][0]!=0){
		g=a[1][0];
		b[1]=b[1]-(b[0]*g);
		for(i=0;i<3;i++){
			a[1][i]=a[1][i]-(a[0][i]*g);
		}
	}
	if(a[2][0]!=0){
		g=a[2][0];
		b[2]=b[2]-(b[0]*g);
		for(i=0;i<3;i++){
			a[2][i]=a[2][i]-(a[0][i]*g);
		}
	}
	g=a[1][1];
	b[1]=b[1]/g;
	for(i=0;i<3;i++){
		a[1][i]=a[1][i]/g;

	}
	if(a[2][1]!=0){
		g=a[2][1];
		b[2]=b[2]-(b[1]*g);
		for(i=0;i<3;i++){
			a[2][i]=a[2][i]-(a[1][i]*g);
		}
	}
	g=a[2][2];
	b[2]=b[2]/g;
	for(i=0;i<3;i++){
		a[2][i]=a[2][i]/g;
	}

	if(a[1][2]!=0){
		g=a[1][2];
		b[1]=b[1]-(b[2]*g);
		for(i=0;i<3;i++){
			a[1][i]=a[1][i]-(a[2][i]*g);
		}
	}
	if(a[0][2]!=0){
		g=a[0][2];
		b[0]=b[0]-(b[2]*g);
		for(i=0;i<3;i++){
			a[0][i]=a[0][i]-(a[2][i]*g);
		}
	}
	if(a[0][1]!=0){
		g=a[0][1];
		b[0]=b[0]-(b[1]*g);
		for(i=0;i<3;i++){
			a[0][i]=a[0][i]-(a[1][i]*g);
		}
	}

	for(i=0;i<3;i++){
		cout<<endl;
		for(j=0;j<3;j++){
			cout<<a[i][j]<<"  ";
		}
		cout<<"   "<<b[i];
	}
	return 0;
}
