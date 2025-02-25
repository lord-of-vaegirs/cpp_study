#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(90<=n&&n<=100)
    {
        cout<<"4.0"<<endl;
    }
    else if(86<=n&&n<=89)
    {
        cout<<"3.7"<<endl;
    
    }
    else if(83<=n&&n<=85)
    {
        cout<<"3.3"<<endl;
    
    }
    else if(80<=n&&n<=82)
    {
        cout<<"3.0"<<endl;
    }
    else if(76<=n&&n<=79)
    {
        cout<<"2.7"<<endl;
    }
    else if(73<=n&&n<=75)
    {
        cout<<"2.3"<<endl;
    }
    else if(70<=n&&n<=72)
    {
        cout<<"2.0"<<endl;
    }
    else if(66<=n&&n<=69)
    {
        cout<<"1.7"<<endl;
    }
    else if(63<=n&&n<=65)
    {
        cout<<"1.3"<<endl;
    }
    else if(60<=n&&n<=62)
    {
        cout<<"1.0"<<endl;
    }
    else if(n<60)
    {
        cout<<"0"<<endl;
    }
    return 0;
}