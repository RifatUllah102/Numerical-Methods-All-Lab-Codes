#include<iostream>
#include<cmath>
#include<cstdio>
#include<windows.h>

using namespace std;

double functionValue(float w,float x,float X[],float Y[]){
    float a,result=0;

    for(int i=0; i<w; i++){
        a=(X[i])*(pow(x,Y[i]));
        result=result+a;
    }
    return result;
}
int main(){
    int term,n;
    float Coefficientarray[100],powerarray[100],Es,NewValue,Ea,Et,OldValue,Change;
    float Xl,Xu,Xr=0,h,y,z;
    double TrueValue,approximateValue=0,sumXl=0,sumXu=0,sumXr=0;

    cout<<"Give The Degree Of The Polynomial: ";
    cin>>n;
    term=n+1;
    cout<<"Input f(x) = \n";
    for(int i=0; i<term; i++){
        cout<<"Coefficient : ";
        cin>>Coefficientarray[i];
        cout<<"Power : ";
        cin>>powerarray[i];
    }

    cout<<"Input the Value of Xl = ";
    cin>>Xl;
    cout<<"Input the Value of Xu = ";
    cin>>Xu;
    cout<<"How Many Step You Need : ";
    cin>>n;
    cout<<"Prespecified Error, Es (%) = ";
    cin>>Es;
    cout<<"\n\n";

    for(int i=0; i<n; i++){
        cout<<i+1<<" Iteration,"<<endl;
        OldValue=Xr;
        sumXl=functionValue(term,Xl,Coefficientarray,powerarray);
        sumXu=functionValue(term,Xu,Coefficientarray,powerarray);

        Xr=Xu-(((sumXu)*(Xl-Xu))/(sumXl-sumXu));

        sumXr=functionValue(term,Xr,Coefficientarray,powerarray);


        Ea=(fabs((Xr-OldValue)/Xr))*100;

        cout<<"Xl : "<<Xl<<endl;
        cout<<"f(Xl): "<<sumXl<<endl;
        cout<<"Xu : "<<Xu<<endl;
        cout<<"f(Xu): "<<sumXu<<endl;
        cout<<"Xr : "<<Xr<<endl;
        cout<<"f(Xr): "<<sumXr<<endl;
        cout<<"Approximate Error : "<<Ea<<"%\n"<<endl;
        cout<<"\n\n";

        if(Xr==0){
            cout<<"Root : "<<Xr;
            break;
        }
        else if((sumXl*sumXr)<0){
            Xu=Xr;
        }
        else if((sumXu*sumXr)<0){
            Xl=Xr;
        }

        if(Ea<Es){
            break;
        }
        Sleep(1000);
    }

    return 0;
}
