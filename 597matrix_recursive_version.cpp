#include<iostream>
using namespace std;
int square[20][20];
int path[20][20]={0};
int n;
int mini=10000;
int counti=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


void move(int x,int y)
{
    if(counti>=mini)
    {
        return;
    }
    if(x==n&&y==n)
    {
        if(counti<mini)
        {
            mini=counti;
        }
        return ;
    }
    if(square[x][y]==0)
    {
        return ;
    }
    path[x][y]=1;
    for(int i=0;i<4;i++)
    {
        for(int j=square[x][y];j>=1;j--)
        {
            int cx=x+j*dx[i];
            int cy=y+j*dy[i];
            if(cx>0&&cx<=n&&cy>0&&cy<=n&&path[cx][cy]!=1)
            {
                counti++;
                move(cx,cy);
                counti--;
            }
        }
    }
    path[x][y]=0;
    return ;
}



int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>square[i][j];
        }
    }
    move(1,1);
    cout<<mini<<endl;
    return 0;
}