#include<iostream>
#include<cmath>
#include<cstdio>
#include<windows.h>

using namespace std;

double FunctionValue(int w,float Xi,float X[],float Y[]){
	float a,result=0;
	for(int i=0; i<w; i++){
		a=X[i]*(pow(Xi,Y[i]));
		result=result+a;
	}
	return result;
}

int main(){
	int n,Count1=0,Count2=0;
	float Coefficient[1000],Power[1000],Xl,Xu,Xi,Xr=0,Xi1=0,approximateValue=0,OldValue,Old,New[1000],New1[1000],term;
	float Ea1,Ea2,Es,q,sumXu=0,sumXl=0,sumXr=0,sumXi=0,sumXd=0,sumXi1=0;
	cout<<"Enter The Degree Of Polynomial Function : ";
	cin>>n;
	term=n+1;
	cout<<"Enter The Function: "<<endl;
	for(int i=0; i<term; i++){
		cout<<"Coefficient : ";
		cin>>Coefficient[i];
		cout<<"Power : ";
		cin>>Power[i];
	}
	cout<<"Enter The Value Of Xl : ";
	cin>>Xl;

	cout<<"Enter The Value Of Xu : ";
	cin>>Xu;

	cout<<"Enter The Value Of X0 : ";
	cin>>Xi;

	cout<<"Enter Prespecified Error(%) : ";
	cin>>Es;
	cout<<"How Many Step You Need : ";
	cin>>q;

	for(int i=0; i<term; i++){
		New[i]=Coefficient[i]*Power[i];
		New1[i]=Power[i]-1;
	}
	cout<<"\n\nFalse Position Method\n\n\n";
	for(int i=0; i<q; i++){
		cout<<"\n"<<i+1<<" Iteration,"<<"\n";
		cout<<"___________________________________________________________________________\n";
		OldValue=Xr;

		sumXu=FunctionValue(term,Xu,Coefficient,Power);
		sumXl=FunctionValue(term,Xl,Coefficient,Power);
		Xr=Xu-((sumXu*(Xl-Xu))/(sumXl-sumXu));
		sumXr=FunctionValue(term,Xr,Coefficient,Power);

		Ea1=(fabs((Xr-OldValue)/Xr))*100;

		cout<<"Approximate Error : "<<Ea1<<"%"<<endl;
		cout<<"Xl = "<<Xl<<"\n";
		cout<<"f(Xl) = "<<sumXl<<"\n";
		cout<<"Xu = "<<Xu<<"\n";
		cout<<"f(Xu) = "<<sumXu<<"\n";
		cout<<"Xr = "<<Xr<<"\n";
		cout<<"f(Xr) = "<<sumXr<<"\n";

		if((sumXu*sumXr)<0){
			Xl=Xr;
		}
		else if((sumXl*sumXr)<0){
			Xu=Xr;
		}
		else if (Xr==0){
			cout<<"Root : "<<Xr;
			break;
		}

		if(Ea1<Es){
			Count1=i;
			break;
		}
		Sleep(1000);
	}
	cout<<"\n\nNewton Rapshon Method\n\n\n";
	for(int i=0;i<q;i++){
		cout<<"\n"<<i+1<<" Iteration,"<<"\n";
		cout<<"___________________________________________________________________________\n";
		Old=Xi1;
		sumXi=FunctionValue(term,Xi,Coefficient,Power);
		sumXd=FunctionValue(term,Xi,New,New1);

		Xi1=Xi-(sumXi/sumXd);

		sumXi1=FunctionValue(term,Xi1,Coefficient,Power);
		Ea2=(fabs((Xi1-Old)/Xi1))*100;
		cout<<"Approximate Error : "<<Ea2<<"%"<<endl;
		cout<<"Xi = "<<Xi<<"\n";
		cout<<"f(Xi) = "<<sumXi<<"\n";

		cout<<"Xi+1 = "<<Xi1<<"\n";
		cout<<"f(Xi+1) = "<<sumXi1<<"\n";

		if(Xr==0){
		cout<<"Root : "<<Xi1<<"\n";
			break;
		}
		Xi=Xi1;

		if(Ea2<Es){
			Count2=i;
			break;
		}
		Sleep(1000);
	}
	if(Count1<Count2){
		cout<<"False Position Is Better Then Newton Rapshon Method.\n";
	}
	else{
		cout<<"Newton Rapshon Is Better Then False Position Method.\n";
	}
	return 0;
}

