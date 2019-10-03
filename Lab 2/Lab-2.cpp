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

int main(){
    int n;
    float x,Es,NewValue,Ea,Et,OldValue;
    double TrueValue,approximateValue=0;
    cout<<"Input the Value of x (Negative or Positive) = ";
    cin>>x;
    cout<<"Prespecified Error, Es (%) = ";
    cin>>Es;
    cout<<"How Many Term You Need to Add: ";
    cin>>n;

    TrueValue=exp(x);
    cout<<"True Value : "<<TrueValue<<endl<<"\n\n";

    for(int i=0; i<n; i++){
        cout<<i+1<<" Step,"<<endl;
        NewValue=pow(x,i)/(Factorial(i));
        OldValue=approximateValue;
        approximateValue=approximateValue+NewValue;

        Et=(fabs((TrueValue-approximateValue)/TrueValue))*100;
        Ea=(fabs((approximateValue-OldValue)/approximateValue))*100;

        cout<<"Approximate Value : "<<approximateValue<<"\n";
        cout<<"True Error : "<<Et<<"%\n";
        cout<<"Approximate Error : "<<Ea<<"%\n";
        Sleep(1000);

        if(Et==0 && Ea==0){
            break;
        }
        else if(Et<Es && Ea<Es){
            break;
        }
    }
    return 0;
}
