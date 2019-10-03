#include<iostream>
#include<cmath>
#include<cstdio>
#include<windows.h>


using namespace std;

int main(){
      int j,i,n,order;
    float sum=0,mult,xn;
    cout<<"how many data points do you have:";
    cin>>n;
    float x[n],fx[n];
    order=n-1;

    for(int i=0;i<n;i++){
        cout<<"please input x"<<i<<":";cin>>x[i];
        cout<<"please input f(x"<<i<<"):";cin>>fx[i];
    }
     cout<<"\nplease input value of x:";cin>>xn;


     for(j=0;j<n-1;j++){
      for(i=n-1;i>j;i--){
          fx[i]=(fx[i]-fx[i-1])/(x[i]-x[i-j-1]);
      }
    }

  for(i=n-1;i>=0;i--){
      mult =1;
      for(j=0;j<i;j++){
          mult = mult * (xn-x[j]);
      }
      mult = mult * fx[j];
      sum = sum + mult;
  }

    cout<<"\nthe value of f"<<n-1<<"("<<xn<<")"<<":"<<sum;

    return 0;
}
