#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

class GaussElimination
{
public:
    double A[10][10],x[10],z[10],temp;
    int i,j,k,n,p,s,c=0;

    void Input(){
        cout<<"Equation No: ";
        cin>>n;
        cout<<endl<<"Coefficients of the Equation: "<<endl;
        for(i=0; i<n; i++)
        {
            cout<<endl<<"Equation "<<i+1<< ": "<<endl;

            for(j=0; j<=n; j++)
            {
                cin>>A[i][j];
            }
        }
    }

    void print()
    {
        cout<<endl;
        cout<<endl<<"Resulting Matrix: "<<++c<<endl<<endl;
        for(int l=0; l<n; l++)
        {
            for(int m=0; m<n+1; m++)
            {
                printf("%6.2lf  ",A[l][m]);
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void ForwardElimination()
    {
        for(i=0;i<n;i++)
        {
            temp = A[i][i];
            p = i;

            for(k = i+1; k<n; k++)
            {
                if(fabs(temp) < fabs(A[k][i]))
                {
                    temp = A[k][i] ;
                    p = k;
                }
            }

            for(j = 0; j <= n; j++)
            {
                swap(A[p][j],A[i][j]);
            }
        }
        cout<<"After elimination: "<<endl<<endl;

        for(int l=0; l<n; l++)
        {
            for(int m=0; m<n+1; m++)
            {
                printf("%6.2lf  ",A[l][m]);
            }
            cout<<endl;
        }
        cout<<endl;

    }

    void Gauss_Elimination()
    {
        double temp=0;

        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {

                temp=A[j][i]/A[i][i];
                for(k=i; k<=n; k++)
                {
                    A[j][k] = A[j][k] - A[i][k] * temp;
                }
                print();
            }
        }
        x[n-1] = A[n-1][n] / A[n-1][n-1] ;
        for(i = n - 2 ; i >= 0 ; i--)
        {
            s = 0 ;
            for(j = i + 1 ; j < n ; j++)
            {
                s += (A[i][j] * x[j]) ;
                x[i] = (A[i][n] - s) / A[i][i] ;
            }
        }
        cout<<endl<<"The result is: "<<endl;
        for(i = 0 ; i < n ; i++)
            printf("\nx[%d] = %.4f", i + 1, x[i]);
    }


};

int main()
{
    GaussElimination A;
    A.Input();
    A.ForwardElimination();
    A.Gauss_Elimination();

    return 0;
}
