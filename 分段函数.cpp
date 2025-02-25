#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    double a;
    cin>>a;
    if(a<0)
    {
        a=-a;
    }
    else if(0<=a&&a<=1)
    {
        a=sqrt(a);
    }
    else if(a>1)
    {
        a=pow(a,2);
    }
    cout<<fixed<<setprecision(2)<<a<<endl;
    return 0;
}