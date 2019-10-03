#include<iostream>
#include<cmath>
#include<cstdio>
#include<windows.h>

using namespace std;

int main(){
    int term,n;
    float X[100],Y[100],E;
    double L[100],Result=0,Value[100];

    cout<<"How Many Value You Need To Input : ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Input the Value of X"<<i<<" = ";
        cin>>X[i];
        cout<<"Input the Value of f(X"<<i<<") = ";
        cin>>Y[i];
    }

    cout<<"\nEnter The Value Which You Want : ";
    cin>>E;

    return 0;
}

