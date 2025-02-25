#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int add(double a,double b,double c,double d)
{
    double sum=0;
    double n=0;
    if(a!=0)
    {
        sum+=a;
        n++;
    }
    if(b!=0)
    {
        sum+=b;
        n++;
    }
    if(c!=0)
    {
        sum+=c;
        n++;
    }
    if(d!=0)
    {
        sum+=d;
        n++;
    }
    double t;
    if(n!=0)
    {
        t=ceil(sum/n);
    }
    return t;
}


int main()
{
    int n; int m;
    cin>>n>>m;
    double chart[100][100];
    char color[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j+=1)
        {
            cin>>color[i][3*j];
            cin>>chart[i][3*j];
            cin>>color[i][3*j+1];
            cin>>chart[i][3*j+1];
            cin>>color[i][3*j+2];
            cin>>chart[i][3*j+2];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(chart[i][3*j]==0&&chart[i][3*j+1]==0&&chart[i][3*j+2]==0)
            {
                if(i==0&&j==0)
                {
                    chart[i][3*j]=add(0,chart[i][3*j+3],0,chart[i+1][3*j]);
                    chart[i][3*j+1]=add(0,chart[i][3*j+1+3],0,chart[i+1][3*j+1]);
                    chart[i][3*j+2]=add(0,chart[i][3*j+3+2],0,chart[i+1][3*j+2]);
                }
                else if(i!=0&&j==0&&i!=n-1)
                {
                    chart[i][3*j]=add(0,chart[i][3*j+3],chart[i-1][3*j],chart[i+1][3*j]);
                    chart[i][3*j+1]=add(0,chart[i][3*j+1+3],chart[i-1][3*j+1],chart[i+1][3*j+1]);
                    chart[i][3*j+2]=add(0,chart[i][3*j+3+2],chart[i-1][3*j+2],chart[i+1][3*j+2]);
                }
                else if(i==n-1&&j==0)
                {
                    chart[i][3*j]=add(0,chart[i][3*j+3],chart[i-1][3*j],0);
                    chart[i][3*j+1]=add(0,chart[i][3*j+1+3],chart[i-1][3*j+1],0);
                    chart[i][3*j+2]=add(0,chart[i][3*j+3+2],chart[i-1][3*j+2],0);
                }
                else if(i==0&&j!=0&&j!=m-1)
                {
                    chart[i][3*j]=add(chart[i][3*j-3],chart[i][3*j+3],0,chart[i+1][3*j]);
                    chart[i][3*j+1]=add(chart[i][3*j+1-3],chart[i][3*j+1+3],0,chart[i+1][3*j+1]);
                    chart[i][3*j+2]=add(chart[i][3*j+2-3],chart[i][3*j+3+2],0,chart[i+1][3*j+2]);
                }
                else if(i==n-1&&j!=0&&j!=m-1)
                {
                    chart[i][3*j]=add(chart[i][3*j-3],chart[i][3*j+3],chart[i-1][3*j],0);
                    chart[i][3*j+1]=add(chart[i][3*j+1-3],chart[i][3*j+1+3],chart[i-1][3*j+1],0);
                    chart[i][3*j+2]=add(chart[i][3*j+2-3],chart[i][3*j+3+2],chart[i-1][3*j+2],0);
                }
                else if(i==0&&j==m-1)
                {
                    chart[i][3*j]=add(chart[i][3*j-3],0,0,chart[i+1][3*j]);
                    chart[i][3*j+1]=add(chart[i][3*j+1-3],0,0,chart[i+1][3*j+1]);
                    chart[i][3*j+2]=add(chart[i][3*j+2-3],0,0,chart[i+1][3*j+2]);
                }
                else if(i!=0&&i!=n-1&&j==m-1)
                {
                    chart[i][3*j]=add(chart[i][3*j-3],0,chart[i-1][3*j],chart[i+1][3*j]);
                    chart[i][3*j+1]=add(chart[i][3*j+1-3],0,chart[i-1][3*j+1],chart[i+1][3*j+1]);
                    chart[i][3*j+2]=add(chart[i][3*j+2-3],0,chart[i-1][3*j+2],chart[i+1][3*j+2]);
                }
                else if(i==n-1&&j==m-1)
                {
                    chart[i][3*j]=add(chart[i][3*j-3],0,chart[i-1][3*j],0);
                    chart[i][3*j+1]=add(chart[i][3*j+1-3],0,chart[i-1][3*j+1],0);
                    chart[i][3*j+2]=add(chart[i][3*j+2-3],0,chart[i-1][3*j+2],0);
                }
                else
                {
                    chart[i][3*j]=add(chart[i][3*j-3],chart[i][3*j+3],chart[i-1][3*j],chart[i+1][3*j]);
                    chart[i][3*j+1]=add(chart[i][3*j+1-3],chart[i][3*j+1+3],chart[i-1][3*j+1],chart[i+1][3*j+1]);
                    chart[i][3*j+2]=add(chart[i][3*j+2-3],chart[i][3*j+3+2],chart[i-1][3*j+2],chart[i+1][3*j+2]);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<color[i][3*j]<<" ";
            cout<<fixed<<setprecision(0)<<chart[i][3*j]<<" ";
            cout<<color[i][3*j+1]<<" ";
            cout<<fixed<<setprecision(0)<<chart[i][3*j+1]<<" ";
            cout<<color[i][3*j+2]<<" ";
            cout<<fixed<<setprecision(0)<<chart[i][3*j+2]<<" ";
        }
        cout<<endl;
    }
    return 0;
}