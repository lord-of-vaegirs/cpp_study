#include <iostream>
using namespace std;
int n, mi = 9999;
int di[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void digui(int num[][12], int used[][12], int x, int y, int sum)
{
    if (sum >= mi)
    {
        return;
    }
    if (x == n - 1 && y == n - 1)
    {
        if (sum < mi)
        {
            mi = sum;
        }
        return;
    }
    used[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= num[x][y]; j++)
        {
            int nx = x + di[i][0] * j;
            int ny = y + di[i][1] * j;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && used[nx][ny] == 0)
            {
                digui(num, used, nx, ny, sum + 1);
            }
        }
    }
    used[x][y] = 0;
    return;
}
int main()
{
    cin >> n;
    int num[n][12];
    int used[n][12];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num[i][j];
            used[i][j] = 0;
        }
    }
    digui(num, used, 0, 0, 0);
    cout << mi;
    return 0;
}