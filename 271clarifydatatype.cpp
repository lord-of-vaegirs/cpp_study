#include<iostream>
#include<stdio.h>
using namespace std;

char str[1100];

bool is_io(int index)
{
    scanf("%c",&str[index]);
    if(str[index]=='\0'||str[index]=='\n')
    {
        return false;
    }
    else
    {
        return true;
    }
}

void _integer(int len)
{
    int num=0;
    if(str[0]=='-')
    {
        for(int i=1;i<len;i++)
        {
            num*=10;
            num+=int(str[i]-'0');
        }
        num--;
        cout<<-num<<endl;
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            num*=10;
            num+=int(str[i]-'0');
        }
        num++;
        cout<<num<<endl;
    }
}

void _float(int len)
{
    for(int i=0;i<len;i++)
    {
        if(str[i]=='.')
        {
            if(i==0)
            {
                cout<<0;
            }
            break;
        }
        else
        {
            cout<<str[i];
        }
    }
}

void _string(int len)
{
    for(int i=0;i<len;i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i]=char(str[i]-32);
        }
    }
    for(int i=0;i<len;i++)
    {
        cout<<str[i];
    }
}

int main()
{
    
    int t=0;
    int type=1;
    while(is_io(t))
    {
        if(str[t]=='.')
        {
            type=2;
        }
        else if(str[t]=='_'||str[t]==' '||(str[t]>='a'&&str[t]<='z')||(str[t]>='A'&&str[t]<='Z'))
        {
            type=3;
        }
        t++;
    }
    if(type==1)
    {
        _integer(t);
    }
    else if(type==2)
    {
        _float(t);
    }
    else if(type==3)
    {
        _string(t);
    }
    return 0;
}