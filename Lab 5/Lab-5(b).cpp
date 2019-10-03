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
    float Coefficientarray[100],powerarray[100],Es,NewValue,Ea,Et,OldValue,Change,New[100],New1[100];
    float Xl,X0,Xi=0,h,y,z;
    double TrueValue,approximateValue=0,sumX0=0,sumXp=0,sumXi=0;

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
    cout<<"Input the Value of X-1 = ";
    cin>>Xl;
    cout<<"Input the Value of X0 = ";
    cin>>X0;
    cout<<"How Many Step You Need : ";
    cin>>n;
    cout<<"Prespecified Error, Es (%) = ";
    cin>>Es;
    cout<<"\n\n";

    for(int i=0; i<n; i++){
        cout<<i+1<<" Step,"<<endl;
        OldValue=X0;
        sumX0=functionValue(term,X0,Coefficientarray,powerarray);
        sumXp=functionValue(term,Xl,Coefficientarray,powerarray);

        Xi=X0-((sumX0*(Xl-X0))/(sumXp-sumX0));

        sumXi=functionValue(term,Xi,Coefficientarray,powerarray);

        Ea=(fabs((Xi-OldValue)/Xi))*100;

        cout<<"Xi-1 : "<<Xl<<endl;
        cout<<"f(Xi-1): "<<sumXp<<endl;
        cout<<"X0 : "<<X0<<endl;
        cout<<"f(X0): "<<sumX0<<endl;
        cout<<"Xi+1 : "<<Xi<<endl;
        cout<<"f(Xi+1): "<<sumXi<<endl;
        cout<<"Approximate Error : "<<Ea<<"%\n"<<endl;
        cout<<"\n\n";

        if(Xi==0){
            cout<<"Root : "<<Xi;
            break;
        }

        Xl=X0;
        X0=Xi;

        if(Ea<Es){
            break;
        }
        Sleep(1000);
    }

    return 0;
}
