#include <iostream>
#include <cstring>
#include<stdlib.h>
using namespace std;

struct ppos
{
    int x;
    int y;
    int z;
    int sign;
};

int main()
{
    char str[20];
    cin >> str;
    int len = 0;
    len = strlen(str);
    ppos p[200];
    int t = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len - 1; j++)
        {
            for (int k = j + 1; k < len - 1; k++)
            {
                if (i <= 2 && (j - i) <= 3 && (k - j) <= 3)
                {
                    p[t].x = i;
                    p[t].y = j;
                    p[t].z = k;
                    p[t].sign=1;
                    t++;
                }
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        if(len-p[i].z-1>3)
        {
            p[i].sign=0;
            continue;
        }
        char c1[10]; int t1=0;
        char c2[10]; int t2=0;
        char c3[10]; int t3=0;
        char c4[10]; int t4=0;
        for(int j=0;j<=p[i].x;j++)
        {
            c1[t1]=str[j];
            t1++;
        }
        for(int j=p[i].x+1;j<=p[i].y;j++)
        {
            c2[t2]=str[j];
            t2++;
        }
        for(int j=p[i].y+1;j<=p[i].z;j++)
        {
            c3[t3]=str[j];
            t3++;
        }
        for(int j=p[i].z+1;j<len;j++)
        {
            c4[t4]=str[j];
            t4++;
        }
        if(t1>1&&c1[0]=='0')
        {
            p[i].sign=0;
            continue;
        }
        if(t2>1&&c2[0]=='0')
        {
            p[i].sign=0;
            continue;
        }
        if(t3>1&&c3[0]=='0')
        {
            p[i].sign=0;
            continue;
        }
        if(t4>1&&c4[0]=='0')
        {
            p[i].sign=0;
            continue;
        }
        int a1=0,a2=0,a3=0,a4=0;
        for(int j=0;j<t1;j++)
        {
            a1*=10;
            a1+=(int)(c1[j]-'0');
        }
        if(a1>255)
        {
            p[i].sign=0;
            continue;
        }
        for(int j=0;j<t2;j++)
        {
            a2*=10;
            a2+=(int)(c2[j]-'0');
        }
        if(a2>255)
        {
            p[i].sign=0;
            continue;
        }
        for(int j=0;j<t3;j++)
        {
            a3*=10;
            a3+=(int)(c3[j]-'0');
        }
        if(a3>255)
        {
            p[i].sign=0;
            continue;
        }
        for(int j=0;j<t4;j++)
        {
            a4*=10;
            a4+=(int)(c4[j]-'0');
        }
        if(a4>255)
        {
            p[i].sign=0;
            continue;
        }
    }
    for(int i=0;i<t;i++)
    {
        if(p[i].sign==1)
        {
            for(int j=0;j<len;j++)
            {
                cout<<str[j];
                if(j==p[i].x||j==p[i].y||j==p[i].z)
                {
                    cout<<".";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}