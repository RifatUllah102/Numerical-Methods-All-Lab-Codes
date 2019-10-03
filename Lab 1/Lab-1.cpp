#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    int term;
    float Coefficientarray[100],powerarray[100];
    float x,y,sum=0;

    cout<<"How Many Term in this Function : ";
    cin>>term;
    cout<<"Input f(x) = \n";
    for(int i=0; i<term; i++){
        cout<<"Coefficient : ";
        cin>>Coefficientarray[i];
        cout<<"Power : ";
        cin>>powerarray[i];
    }

    cout<<"Input the Value of X = ";
    cin>>x;
    for(int i=0; i<term; i++){
        y=(Coefficientarray[i])*(pow(x,powerarray[i]));
        sum=sum+y;
    }
    cout<<"f(x)="<<sum;
    return 0;
}
