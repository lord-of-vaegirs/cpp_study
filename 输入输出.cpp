#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a;int b;
    char dou=',';
    double c;double d;
    char e;
    char f;
    cin>>a>>dou>>b>>c>>d>>e>>dou>>f;
    cout<<a<<","<<b<<endl;
    cout<<fixed<<setprecision(1)<<c<<" ";
    cout<<fixed<<setprecision(1)<<d<<endl;
    cout<<" "<<e<<","<<" "<<f<<endl;
    return 0;
}