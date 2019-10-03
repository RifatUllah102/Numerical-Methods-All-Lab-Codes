#include<iostream>
#include<cmath>
#include<cstdio>
#include<windows.h>

using namespace std;

int main(){
    int term,n;
    float Array[100][100],powerarray[100],Es,NewValue,Ea,Et,OldValue,Change,New[100],New1[100];
    float X1,X2,X3,P,Q,R,D;
    double TrueValue,approximateValue=0,sumX1=0,sumX2=0,sumXi=0;

    cout<<"Give The Equation Number(Only 3 Equ.): ";
    cin>>n;
    term=n+1;
    cout<<"Enter The Equation's : \n";

    for(int i=1; i<=n; i++){
        for(int j=1; j<=term; j++){
            cin>>Array[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=term; j++){
            D=(Array[1][1]*((Array[2][2]*Array[3][3])-(Array[2][3]*Array[3][2])))-(Array[1][2]*((Array[2][1]*Array[3][3])-(Array[3][1]*Array[2][3])))+(Array[1][3]*((Array[2][1]*Array[3][2])-(Array[3][1]*Array[2][2])));
        }
    }
    cout<<"The determinant is,D = "<<D<<endl;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=term; j++){
            P=(Array[1][4]*((Array[2][2]*Array[3][3])-(Array[2][3]*Array[3][2])))-(Array[1][2]*((Array[2][4]*Array[3][3])-(Array[3][4]*Array[2][3])))+(Array[1][3]*((Array[2][4]*Array[3][2])-(Array[3][4]*Array[2][2])));
            Q=(Array[1][1]*((Array[2][4]*Array[3][3])-(Array[2][3]*Array[3][4])))-(Array[1][4]*((Array[2][1]*Array[3][3])-(Array[3][1]*Array[2][3])))+(Array[1][3]*((Array[2][1]*Array[3][4])-(Array[3][1]*Array[2][4])));
            R=(Array[1][1]*((Array[2][2]*Array[3][4])-(Array[2][4]*Array[3][2])))-(Array[1][2]*((Array[2][1]*Array[3][4])-(Array[3][1]*Array[2][4])))+(Array[1][4]*((Array[2][1]*Array[3][2])-(Array[3][1]*Array[2][2])));
        }
    }
    X1=P/D;
    X2=Q/D;
    X3=R/D;

    cout<<"X1 = "<<X1<<endl;
    cout<<"X2 = "<<X2<<endl;
    cout<<"X3 = "<<X3<<endl;

    return 0;
}
