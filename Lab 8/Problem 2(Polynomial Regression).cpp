#include<iostream>
#include<cmath>
#include<cstdio>
#include<windows.h>

using namespace std;

int main(){
    int term,n;
    float Array[100][100],powerarray[100],Es,NewValue,Ea,Et,OldValue,Change,X[100],Y[100];
    float X0,Xi=0,P,Q,Z,D,Sy=0;
    double a0=0,a1=0,a2=0,TrueValue,MeanX=0,MeanY=0,SumXiYi=0,SumYi=0,SumXi=0,SqureXi=0,SumsqureXi=0,Sr=0,R=0,St=0,Syx=0,r=0;
    double SumCubeXi=0,SumfourXi=0,SumsqureXiYi=0;



    cout<<"How Many Value You Need To Input : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Input the Value of X"<<i+1<<" = ";
        cin>>X[i];
        cout<<"Input the Value of Y"<<i+1<<" = ";
        cin>>Y[i];
    }
    for(int i=0;i<n;i++){
        SumXi=SumXi+X[i];
        SumYi=SumYi+Y[i];
        SumXiYi=SumXiYi+(X[i]*Y[i]);
        SumsqureXi=SumsqureXi+(pow(X[i],2));
        SumCubeXi=SumCubeXi+(pow(X[i],3));
        SumfourXi=SumfourXi+(pow(X[i],4));
        SumsqureXiYi=SumsqureXiYi+((pow(X[i],2))*Y[i]);
    }
    MeanX=SumXi/n;
    MeanY=SumYi/n;
    SqureXi=pow(SumXi,2);

    cout<<"Summation of Xi = "<<SumXi<<"\n";
    cout<<"Summation of Yi = "<<SumYi<<"\n\n";
    cout<<"Summation of XiYi = "<<SumXiYi<<"\n\n";
    cout<<"Square of Xi = "<<SqureXi<<"\n\n";
    cout<<"Summation-Squre of Xi = "<<SumsqureXi<<"\n\n";
    for(int i=1; i<=3; i++){
        for(int j=1; j<=4; j++){
            Array[1][1]=n;         Array[1][2]=SumXi;     Array[1][3]=SumsqureXi;Array[1][4]=SumYi;
            Array[2][1]=SumXi;     Array[2][2]=SumsqureXi;Array[2][3]=SumCubeXi; Array[2][4]=SumXiYi;
            Array[3][1]=SumsqureXi;Array[3][2]=SumCubeXi; Array[3][3]=SumfourXi; Array[3][3]=SumsqureXiYi;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=term; j++){
            D=(Array[1][1]*((Array[2][2]*Array[3][3])-(Array[2][3]*Array[3][2])))-(Array[1][2]*((Array[2][1]*Array[3][3])-(Array[3][1]*Array[2][3])))+(Array[1][3]*((Array[2][1]*Array[3][2])-(Array[3][1]*Array[2][2])));
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=term; j++){
            P=(Array[1][4]*((Array[2][2]*Array[3][3])-(Array[2][3]*Array[3][2])))-(Array[1][2]*((Array[2][4]*Array[3][3])-(Array[3][4]*Array[2][3])))+(Array[1][3]*((Array[2][4]*Array[3][2])-(Array[3][4]*Array[2][2])));
            Q=(Array[1][1]*((Array[2][4]*Array[3][3])-(Array[2][3]*Array[3][4])))-(Array[1][4]*((Array[2][1]*Array[3][3])-(Array[3][1]*Array[2][3])))+(Array[1][3]*((Array[2][1]*Array[3][4])-(Array[3][1]*Array[2][4])));
            Z=(Array[1][1]*((Array[2][2]*Array[3][4])-(Array[2][4]*Array[3][2])))-(Array[1][2]*((Array[2][1]*Array[3][4])-(Array[3][1]*Array[2][4])))+(Array[1][4]*((Array[2][1]*Array[3][2])-(Array[3][1]*Array[2][2])));
        }
    }
    a0=P/D;
    a1=Q/D;
    a2=Z/D;

    cout<<"a0 = "<<a0<<endl;
    cout<<"a1 = "<<a1<<endl;
    cout<<"a2 = "<<a2<<endl;

    for(int i=0;i<n;i++){
        Sr=Sr+pow((Y[i]-a0-(a1*X[i])-(a2*(pow(Xi,2)))),2);
        St=St+pow((Y[i]-MeanY),2);
    }
    R=Sr/(n-3);
    Syx=pow(R,0.5);
    r=pow(((St-Sr)/St),0.5);
    Sy=pow((St/(n-1)),0.5);
    cout<<"Standard Error Estimate = "<<Syx<<"\n";
    cout<<"Correlation of Coefficient = "<<r<<"\n\n";
    if(Syx<Sy){
        cout<<"There Is Improvement.\n";
    }
    else if(r==1){
        cout<<"Perfect Fit.\n";
    }
    else{
        cout<<"No Improvement.\n";
    }

return 0;
}

