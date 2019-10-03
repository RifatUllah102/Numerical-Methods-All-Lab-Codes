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

    cout<<"Enter The Value Which You Want : ";
    cin>>E;

    for(int i=0; i<n; i++){
        float Cheak=1;
        for(int j=0; j<n; j++){

                if(j==i){
                    continue;
                }
                else{
                   Value[j]=(E-X[j])/(X[i]-X[j]);

                }
                Cheak=Cheak*Value[j];
                //cout<<"\nValue : "<<Value[j];
        }
        L[i]=Cheak;

        //cout<<"\n\nCheak : "<<Cheak<<"\n";

        Result=Result+(L[i]*Y[i]);

        cout<<"\nL["<<i<<"] : "<<L[i];
    }
    cout<<"\n\nResult : "<<Result<<"\n\n";

return 0;
}
