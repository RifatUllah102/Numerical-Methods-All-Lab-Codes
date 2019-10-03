#include<iostream>
#include<cstdio>
#include<cmath>
#include<windows.h>

using namespace std;

long long Factorial(int n)
{
    if(n==0)
        return 1;
    else
        return n*Factorial(n-1);
}

double functionValue(float w,float x,float X[],float Y[]){
    float a,result=0;

    for(int i=0; i<w; i++){
        a=(X[i])*(pow(x,Y[i]));
        result=result+a;
    }
    return result;
}

/*double Differentiatefx(float s,float *X,float *Y){
    float x=s-1;
    float newCoefficient[1000];

    for(int i=0; i<x; i++){
        X[i]=Y[i]*X[i];
        Y[i]=Y[i]-1;
    }
    //for (int i=0;i<x;i++){
        //X[i]=newCoefficient[i];
    //}
}*/

int main(){
    int term,n;
    float Coefficientarray[100],powerarray[100],Es,NewValue,Ea,Et,OldValue,Change;
    float Xi,Xi1,h,y,z;
    double TrueValue,approximateValue=0,sum=0,sum1=0;

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

    cout<<"Input the Value of Xi = ";
    cin>>Xi;
    cout<<"Input the Value of Xi+1 = ";
    cin>>Xi1;
    h=Xi1-Xi;

    sum = functionValue(term,Xi,Coefficientarray,powerarray);

    /*for(int i=0; i<term; i++){
        z=(Coefficientarray[i])*(pow(Xi1,powerarray[i]));
        sum1=sum1+z;
    }*/
    sum1 = functionValue(term,Xi1,Coefficientarray,powerarray);

    cout<<"\n\n";
    cout<<"f(Xi) = "<<sum<<"\n";
    cout<<"True Value = ";
    cout<<"f(Xi+1) = "<<sum1<<"\n\n";
    for(int i=0; i<term; i++){
        OldValue=approximateValue;
        cout<<"\n\n";
        cout<<i<<" Order,"<<endl;
        NewValue=functionValue(term,Xi,Coefficientarray,powerarray)*pow(h,i)/(Factorial(i));
        approximateValue=approximateValue+NewValue;

        Et=(fabs((sum1-approximateValue)/sum1))*100;
        Ea=(fabs((approximateValue-OldValue)/approximateValue))*100;

        cout<<"Approximate Value : "<<approximateValue<<"\n";
        cout<<"True Error : "<<Et<<"%\n";
        cout<<"Approximate Error : "<<Ea<<"%\n";
        Sleep(1000);
        //Change=Differentiatefx(term,Coefficientarray,powerarray);
        for(int i=0; i<term; i++){
            Coefficientarray[i]=powerarray[i]*Coefficientarray[i];
            powerarray[i]=powerarray[i]-1;
        }
    }
    return 0;
}
