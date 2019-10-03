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
    float Xl,Xu,X1,X2,h,y,z,d,R;
    double TrueValue,approximateValue=0,sumX1=0,sumX2=0,sumXi=0;

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

    R=((-1+2.2361)/2);

    for(int i=0; i<n; i++){
        cout<<i+1<<" Step,"<<endl;
        d=R*(Xu-Xl);
        X1=Xl+d;
        X2=Xu-d;

        sumX1=functionValue(term,X1,Coefficientarray,powerarray);
        sumX2=functionValue(term,X2,Coefficientarray,powerarray);

        cout<<"Xl : "<<Xl<<endl;
        cout<<"Xu : "<<Xu<<endl;
        cout<<"X1 : "<<X1<<endl;
        cout<<"f(X1): "<<sumX1<<endl;
        cout<<"X2 : "<<X2<<endl;
        cout<<"f(X2): "<<sumX2<<endl;


        if(sumX1>sumX2){
            Xl=X2;
            cout<<"Xopt : "<<X1<<endl;
            cout<<"f(Xopt): "<<sumX1<<endl;

            Ea=(1-R)*(fabs((Xu-Xl)/X1))*100;
            cout<<"Approximate Error : "<<Ea<<"%\n"<<endl;
            cout<<"\n\n";
            //X2=X1;
            if(Ea<Es){
                break;
            }
        }
        else if (sumX2>sumX1){
            Xu=X1;
            cout<<"Xopt : "<<X2<<endl;
            cout<<"f(Xopt): "<<sumX2<<endl;

            Ea=(1-R)*(fabs((Xu-Xl)/X2))*100;
            cout<<"Approximate Error : "<<Ea<<"%\n"<<endl;
            cout<<"\n\n";
            //X1=X2;
            if(Ea<Es){
                break;
            }
        }
        Sleep(1000);
    }

    return 0;
}
