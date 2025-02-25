#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


int n;
struct point
{
  int x;
  int y;  
};

struct fd
{
    int s;
    point p;
};
int a[1100][1100];
fd b[11000];
fd shu[1100000];
int t=0;

int comp(const void*a,const void*b)
{
    int c=((fd *)a)->s;
    int d=((fd *)b)->s;
    if(c>d)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void search(int left,int right,int pin)
{
    if(left>right)
    {
        return ;
    }
    else if(left==right)
    {
        if(b[pin].s==shu[left].s)
        {
            b[pin].p.x=shu[left].p.x;
            b[pin].p.y=shu[left].p.y;
            return ;
        }
        return ;
    }
    int mid=(left+right)/2;
    if(b[pin].s==shu[mid].s)
    {
        b[pin].p.x=shu[mid].p.x;
        b[pin].p.y=shu[mid].p.y;
        return ;
    }
    else if(b[pin].s>shu[mid].s)
    {
        search(mid+1,right,pin);
    }
    else
    {
        search(left,mid-1,pin);
    }
}


int main()
{
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            shu[t].s=a[i][j];
            shu[t].p.x=i;
            shu[t].p.y=j;
            t++;
        }
    }
    qsort(shu,t,sizeof(fd),comp);
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&b[i].s);
        b[i].p.x=-1;
        b[i].p.y=-1;
        search(0,t-1,i);
    }
    for(int i=0;i<k;i++)
    {
        if(b[i].p.x!=-1&&b[i].p.y!=-1)
        {
            printf("%d %d\n",b[i].p.x,b[i].p.y);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}