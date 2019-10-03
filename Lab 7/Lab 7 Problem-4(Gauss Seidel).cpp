#include<iostream>
#include<cmath>
#include<cstdio>
#include<windows.h>

using namespace std;


int main(){
    int n,term,a;
    float Array[100][100],NewValue,Ea1,Ea2,Ea3,OldValue1,OldValue2,OldValue3,X1,X2,X3;
    cout<<"Give The Equation Number's: ";
    cin>>n;
    term=n+1;
    cout<<"Enter The Equation's : \n";

    for(int i=1; i<=n; i++){
        for(int j=1; j<=term; j++){
            cin>>Array[i][j];
        }
    }
    cout<<"Enter The Initial Guess : \n";
    cout<<"X1 : ";
    cin>>X1;
    cout<<"X2 : ";
    cin>>X2;
    cout<<"X3 : ";
    cin>>X3;
    cout<<"How Many Step You Need to Solve : ";
    cin>>a;


    for(int k=0; k<a; k++){
        cout<<"\n"<<k+1<<" Step,\n";
        for(int i=1; i<=n; i++){
            for(int j=1; j<=term; j++){

                X1=(Array[1][4]-(Array[1][2]*X2)-(Array[1][3]*X3))/(Array[1][1]);
                X2=(Array[2][4]-(Array[2][1]*X1)-(Array[2][3]*X3))/(Array[2][2]);
                X3=(Array[3][4]-(Array[3][1]*X1)-(Array[3][2]*X2))/(Array[3][3]);
            }
        }

        OldValue1=X1;
        OldValue2=X2;
        OldValue3=X3;
        cout<<"X1 = "<<X1<<"\n";
        cout<<"X2 = "<<X2<<"\n";
        cout<<"X3 = "<<X3<<"\n";

        Ea1=(fabs((X1-OldValue1)/X1))*100;
        Ea2=(fabs((X2-OldValue2)/X2))*100;
        Ea3=(fabs((X3-OldValue3)/X3))*100;

        cout<<"Ea for X1 : "<<Ea1<<"%\n";
        cout<<"Ea for X2 : "<<Ea2<<"%\n";
        cout<<"Ea for X3 : "<<Ea3<<"%\n";
    }

    return 0;
}
