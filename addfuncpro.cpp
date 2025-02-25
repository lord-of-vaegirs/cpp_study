#include <iostream>
#include <cstring>
using namespace std;

int addn(int x, int y, int a[])
{
    int s = 0;
    for (int i = x; i <= y; i++)
    {
        s = (s * 10 + a[i]);
    }
    return s;
}

void fucubiac(int start,int end,int a[],int &m,int af[],int &k,int maxi[],int &p,int &ma)
{
    if(m>0)
    {
        for(int i=start;i<=end;i++)
        {
            af[k]=i;
            k++;
            m--;
            fucubiac(i+1,end,a,m,af,k,maxi,p,ma);
        }
    }
    else
    {
        int s=0,be=0;
        for(int i=0;i<k;i++)
        {
            s+=addn(be,af[i],a);
            be=af[i]+1;
            cout<<s<<" ";
        }
        s+=addn(be,end,a);
        maxi[p]=s;
        cout<<maxi[p]<<endl;
        p++;
        start=p;
        m=ma;
        return;
    }

}

void sortm(int a[],int len)
{
    for(int i=0;i<len;i++)
    {
        for(int j=len-1;j>i;j--)
        {
            if(a[j]>a[j-1])
            {
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
}


// 0->48
int main()
{
    int m;
    cin >> m;
    char n[20];
    cin >> n;
    int maxi[10000]= {0};
    int len = strlen(n);
    int a[100];
    int af[100]={0};
    for (int i = 0; i < len; i++)
    {
        a[i] = (int)(n[i] - 48);
        // cout<<a[i]<<" ";
    }
    // cout<<len<<endl;
    int s=0,k=0,p=0,ma=m;
    fucubiac(0,len-1,a,m,af,k,maxi,p,ma);
    sortm(maxi,p);
    cout << maxi[0] << endl;
    return 0;
}