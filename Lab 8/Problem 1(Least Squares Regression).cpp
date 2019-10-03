#include<iostream>
#include<cmath>
#include<cstdio>
#include<windows.h>

using namespace std;

int main(){
    int term,n;
    float Coefficientarray[100],powerarray[100],Es,NewValue,Ea,Et,OldValue,Change,X[100],Y[100];
    float X0,Xi=0,h,y,z,Sy=0;
    double a0=0,a1=0,TrueValue,MeanX=0,MeanY=0,SumXiYi=0,SumYi=0,SumXi=0,SqureXi=0,SumsqureXi=0,Sr=0,R=0,St=0,Syx=0,r=0;



    cout<<"How Many Value You Need To Input : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Input the Value of X"<<i+1<<" = ";
        cin>>X[i];
        cout<<"Input the Value of Y"<<i+1<<" = ";
        cin>>Y[i];
    }
    for(int i=0;i<n;i++){
        SumXi=SumXi+X[i];
        SumYi=SumYi+Y[i];
        SumXiYi=SumXiYi+(X[i]*Y[i]);
        SumsqureXi=SumsqureXi+(pow(X[i],2));
    }
    MeanX=SumXi/n;
    MeanY=SumYi/n;
    SqureXi=pow(SumXi,2);
    cout<<"Summation of Xi = "<<SumXi<<"\n";
    cout<<"Summation of Yi = "<<SumYi<<"\n\n";
    cout<<"Summation of XiYi = "<<SumXiYi<<"\n\n";
    cout<<"Squre of Xi = "<<SqureXi<<"\n\n";
    cout<<"Summation-Squre of Xi = "<<SumsqureXi<<"\n\n";

    a1=((n*SumXiYi)-(SumXi*SumYi))/((n*SumsqureXi)-SqureXi);
    a0=MeanY-(MeanX*a1);
    cout<<"Value of a1 = "<<a1<<"\n";
    cout<<"Value of a0 = "<<a0<<"\n";

    for(int i=0;i<n;i++){
        Sr=Sr+pow((Y[i]-a0-(a1*X[i])),2);
        St=St+pow((Y[i]-MeanY),2);
    }
    R=Sr/(n-2);
    Syx=pow(R,0.5);
    r=pow(((St-Sr)/St),0.5);
    Sy=pow((St/(n-1)),0.5);
    cout<<"Standard Error Estimate = "<<Syx<<"\n";
    cout<<"Correlation of Coefficient = "<<r<<"\n\n";
    if(Syx<Sy){
        cout<<"There Is Improvement.\n";
    }
    else if(r==1){
        cout<<"Perfect Line.\n";
    }
    else{
        cout<<"No Improvement.\n";
    }

return 0;
}
