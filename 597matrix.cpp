#include <iostream>
#include <stdlib.h>
using namespace std;

struct position
{
    int x;
    int y;
    int step;
};

int main()
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n;
    cin >> n;
    int square[20][20] = {0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> square[i][j];
        }
    }
    int path[20][20] = {0};
    position pos[110000];
    pos[0].x = 1;
    pos[0].y = 1;
    pos[0].step = 0;
    int front=0,back=1;
    path[1][1] = 1;
    while (1)
    {
        position current=pos[front];
        front++;
        if (current.x == n && current.y == n)
        {
            cout<<current.step<<endl;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j <= square[current.x][current.y]; j++)
            {
                int cx = current.x + j * dx[i];
                int cy = current.y + j * dy[i];
                if (cx > 0 && cx <= n && cy > 0 && cy <= n && path[cx][cy] == 0)
                {
                    pos[back].x = cx;
                    pos[back].y = cy;
                    path[cx][cy] = 1;
                    pos[back].step=current.step+1;
                    back++;
                }
            }
        }
    }
    
    return 0;
}