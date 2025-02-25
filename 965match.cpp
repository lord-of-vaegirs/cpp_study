#include<iostream>
#include<stdio.h>
using namespace std;

char str[1100000];

bool is_io(int t)
{
    scanf("%c",&str[t]);
    if(str[t]=='@')
    {
        return false;
    }
    else 
    {
        return true;
    }
}


int main()
{
    
    int t=0;
    int flag=1;
    int st=0;
    int flag2=0;
    int ct_left=0;
    int ct_right=0;
    while(is_io(t))
    {
        if(str[t]=='(')
        {
            ct_left++;
        }
        if(str[t]==')')
        {
            ct_right++;
        }
        if(str[t]==')')
        {
            flag2=0;
            for(int i=st;i<t;i++)
            {
                if(str[i]=='(')
                {
                    st=i+1;
                    flag2=1;
                    break;
                }
            }
            if(flag2==0)
            {
                flag=0;
                
            }
        }
        t++;
    }

    if(flag==1&&ct_left==ct_right)
    {
        //cout<<ct_left<<" "<<ct_right<<endl;
        cout<<"YES"<<endl;
    }
    else
    {
        //cout<<ct_left<<" "<<ct_right<<endl;
        cout<<"NO"<<endl;
    }

    return 0;
}