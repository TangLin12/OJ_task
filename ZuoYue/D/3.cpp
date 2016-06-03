#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char a[1000], b[1000];
int z, c[1000];
int bian(int x, int y)
{
    int i, ji, k;
    if (x == y)
    {
        b[z] = a[x];
        z++;
        return 0;
    }
    k = 0;
    if (a[x] == '('&&a[y] == ')')
    {
        ji = 0;
        for (i = x + 1;i<y;i++)
        {
            if (a[i] == ')')
            {
                k--;
            }
            if (a[i] == '(')
            {
                k++;
            }
            if (k<0)
            {
                ji = 1;
                break;
            }
        }
        if (ji == 0)
        {
            bian(x + 1, y - 1);
            return 0;
        }
    }
    k = 0;
    for (i = y;i >= x;i--)
    {
        if (a[i] == ')')
        {
            k++;
        }
        if (a[i] == '(')
        {
            k--;
        }
        if (k == 0)
        {
            if (a[i] == '+' || a[i] == '-')
            {
                bian(x, i - 1);
                bian(i + 1, y);
                bian(i, i);
                ji = 1;
                return 0;
            }
        }
    }
    for (i = y;i >= x;i--)
    {
        if (a[i] == ')')
        {
            k++;
        }
        if (a[i] == '(')
        {
            k--;
        }
        if (k == 0)
        {
            if (a[i] == '*' || a[i] == '/')
            {
                bian(x, i - 1);
                bian(i + 1, y);
                bian(i, i);
                ji = 1;
                return 0;
            }
        }
    }
    for (i = y;i >= x;i--)
    {
        if (a[i] == ')')
        {
            k++;
        }
        if (a[i] == '(')
        {
            k--;
        }
        if (k == 0)
        {
            if (a[i] == '^')
            {
                bian(x, i - 1);
                bian(i + 1, y);
                bian(i, i);
                ji = 1;
                return 0;
            }
        }
    }
}
void yi(int x)
{
    int i;
    for (i = x;i<z;i++)
    {
        b[i] = b[i + 2];
        c[i] = c[i + 2];
    }
}
void huan()
{
    int i, j, s;
    for (i = 0;i<z;i++)
    {
        if (b[i] == '+')
        {
            c[i - 2] = c[i - 2] + c[i - 1];
            z = z - 2;
            yi(i - 1);
            break;
        }
        else if (b[i] == '-')
        {
            c[i - 2] = c[i - 2] - c[i - 1];
            z = z - 2;
            yi(i - 1);
            break;
        }
        else if (b[i] == '/')
        {
            c[i - 2] = c[i - 2] / c[i - 1];
            z = z - 2;
            yi(i - 1);
            break;
        }
        else if (b[i] == '*')
        {
            c[i - 2] = c[i - 2] * c[i - 1];
            z = z - 2;
            yi(i - 1);
            break;
        }
        else if (b[i] == '^')
        {
            s = c[i - 2];
            for (j = 1;j<c[i - 1];j++)
            {
                s = s*c[i - 2];
            }
            c[i - 2] = s;
            z = z - 2;
            yi(i - 1);
            break;
        }
    }
}
void shu()
{
    int i;
    for (i = 0;i<z;i++)
    {
        if (i != 0)
        {
            printf(" ");
        }
        if (b[i] <= '9'&&b[i] >= '0')
        {
            printf("%d", c[i]);
        }
        else
        {
            printf("%c", b[i]);
        }
    }
    printf("\n");
}
int main()
{
    int l, i;
    scanf("%s", &a);
    l = strlen(a);
    z = 0;
    bian(0, l - 1);
    for (i = 0;i<z;i++)
    {
        if (b[i] <= '9'&&b[i] >= '0')
        {
            c[i] = b[i] - '0';
        }
    }
    shu();
    while (z>1)
    {
        huan();
        shu();
    }
    return 0;
}