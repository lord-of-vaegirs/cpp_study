#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double n;
    cin>>n;
    double c;
    c=(n-32)*5/9;
    cout<<fixed<<setprecision(2)<<c;
    return 0;
}