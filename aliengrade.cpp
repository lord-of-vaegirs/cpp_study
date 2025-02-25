#include<iostream>
#include<cstring>
using namespace std;

struct num
{
    char c[30];
    int l;
    int p[30];
    long long s;
};


int mysort(num n1,num n2,char a)
{
    int t1=0,flag1=1;
    for(int i=0;i<n1.l;i++)
    {
        if(n1.c[i]!=a)
        {
            flag1=0;
            t1=i;
            break;
        }
    }
    int t2=0,flag2=1;
    for(int j=0;j<n2.l;j++)
    {
        if(n2.c[j]!=a)
        {
            flag2=0;
            t2=j;
            break;
        }
    }
    if(flag1==1)
    {
        return 0;
    }
    else if(flag2==1)
    {
        return 1;
    }
    if((n1.l-t1)!=(n2.l-t2))
    {
        if(n1.l-t1>n2.l-t2)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    else
    {
        for(int i=t1,j=t2;i<n1.l;i++,j++)
        {
            if(n1.p[i]>n2.p[j])
            {
                return 1;
            }
            else if(n1.p[i]<n2.p[j])
            {
                return 0;
            }
        }
        return 0;
    }
}


long long cheng(int len,int t)
{
    if(t==0)
    {
        return 1;
    }
    else
    {
        long long k=1;
        for(int i=1;i<=t;i++)
        {
            k*=len;
        }
        return k;
    }
}



long long func(num nm,int len)
{
    long long s=0;
    for(int i=nm.l-1;i>=0;i--)
    {
        s+=(nm.p[nm.l-1-i]*cheng(len,i));
    }
    return s;
}


int main()
{
    int n;
    char a[30];
    cin>>n>>a;
    int len=strlen(a);
    num nm[110];
    for(int i=0;i<n;i++)
    {
        cin>>nm[i].c;
        nm[i].l=strlen(nm[i].c);
        for(int j=0;j<nm[i].l;j++)
        {
            for(int k=0;k<len;k++)
            {
                if(nm[i].c[j]==a[k])
                {
                    nm[i].p[j]=k;
                    break;
                }
            }
        }
    }
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(mysort(nm[j],nm[j-1],a[0]))
            {
                num temp=nm[j];
                nm[j]=nm[j-1];
                nm[j-1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<nm[i].c<<" ";
    }
    cout<<endl;
    nm[n-1].s=func(nm[n-1],len);
    cout<<nm[n-1].s<<endl;
    return 0;
}


// lensort(nm,n);
// for(int i=0;i<len;i++)
// {
//     linesort(nm,n,i);
// }


// void  lensort(num nm[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=n-1;j>i;j--)
//         {
//             if(nm[j].l>nm[j-1].l)
//             {
//                 num temp=nm[j];
//                 nm[j]=nm[j-1];
//                 nm[j-1]=temp;
//             }
//         }
//     }
// }


// void linesort(num nm[],int n,int len)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=n-1;j>i;j--)
//         {
//             if(len>nm[j].l-1)
//             {
//                 break;
//             }
//             else if(len<=nm[j].l-1&&nm[j].p[len]>nm[j-1].p[len]&&nm[j].l==nm[j-1].l)
//             {
//                 //cout<<"hello"<<endl;
//                 num temp=nm[j];
//                 nm[j]=nm[j-1];
//                 nm[j-1]=temp;
//             }
//         }
//     }
// }
