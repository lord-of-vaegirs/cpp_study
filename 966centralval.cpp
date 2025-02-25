#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int num = 0;
int pro = 0;
char str[1100000];

bool is_num(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

void cal(char sig)
{
    if (sig == '+')
    {
        num = (num + pro) % 10000;
    }
    else if (sig == '*')
    {
        int num1 = num;

        int num2 = pro;

        int an = (num1 * num2) % 10000;

        num = an;
    }
}

void cal2(char sig, int num2)
{
    if (sig == '+')
    {
        pro = (pro + num2) % 10000;
    }
    else if (sig == '*')
    {
        pro *= num2;
        pro %= 10000;
    }
}

bool is_io(int t)
{
    scanf("%c", &str[t]);
    if ((!is_num(str[t])) && str[t] != '+' && str[t] != '*')
    {
        return false;
    }
    return true;
}

int main()
{
    int p = 0, q = 0;
    int t = 0;
    int flag2 = 0;

    char sign2 = '+';
    int flag3 = 0;
    while (is_io(t))
    {

        if (str[t] != '+')
        {
            if (!is_num(str[t]))
            {
                if (flag3 == 0)
                {
                    sign2 = '+';
                    flag3 = 1;
                }
                else
                {
                    sign2 = '*';
                }
                int pro2 = 0;
                p = max(q - 4, p);

                for (int i = p; i < q; i++)
                {
                    pro2 *= 10;
                    pro2 += int(str[i] - '0');
                }

                cal2(sign2, pro2);
                sign2 = str[t];
                p = q + 1;
                q = p;
            }
            else
            {
                q++;
            }
        }
        else
        {
            int pro2 = 0;
            p = max(q - 4, p);
            if (flag3 == 0)
            {
                sign2 = '+';
                flag3 = 1;
            }
            for (int i = p; i < q; i++)
            {
                pro2 *= 10;
                pro2 += int(str[i] - '0');
            }

            cal2(sign2, pro2);

            cal('+');

            p = q + 1;
            q = p;
            pro = 0;
            flag3 = 0;
        }
        t++;
    }

    // cout<<str<<endl;

    if (flag3 != 0)
    {
        int pro2 = 0;
        p = max(q - 4, p);
        sign2 = '+';
        flag3 = 1;
        for (int i = p; i < q; i++)
        {
            pro2 *= 10;
            pro2 += int(str[i] - '0');
        }

        cal2('*', pro2);

        cal('+');
    }
    else
    {
        int pro2 = 0;
        p = max(q - 4, p);
        for (int i = p; i < q; i++)
        {
            pro2 *= 10;
            pro2 += int(str[i] - '0');
        }
        cal2('+', pro2);

        cal('+');

    }
    cout<<num<<endl;
    return 0;
}