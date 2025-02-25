#include<iostream>
#include<cstring>
using namespace std;
long long result[10000]={0};
int counti=0;
int len;
int select[20]={0};
char s[20];

void output()
{
    long long mid=0;
    for(int i=0;i<len;i++)
    {
        if(select[i]==1)
        {
            mid*=10;
            mid+=(s[i]-'0');
            //cout<<mid<<endl;
            result[counti]+=mid;
            mid=0;      
        }
        else
        {
            mid*=10;
            mid+=(s[i]-'0');
        }
    }
    result[counti]+=mid;
}

void partition(int k,int m,int i)
{
    if(k==m)
    {
        output();
        counti++;
        return ;
    }
    for(;i<len-1;i++)
    {
        if(select[i]==0)
        {
            select[i]=1;
            partition(k+1,m,i+1);
            select[i]=0;
        }
    }
}

int main()
{
    int m;
    cin>>m; 
    cin>>s;
    len=strlen(s);
    partition(0,m,0);
    long long maxi=0;
    for(int i=0;i<counti;i++)
    {
        if(result[i]>maxi)
        {
            maxi=result[i];
        }
    }
    cout<<maxi<<endl;
    return 0;
}