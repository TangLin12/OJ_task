#include<stdio.h>  
struct ss
{
	int x, y;
} a[701];
int main()
{
	int i;
	int n, ans, xa, xb, xc, ya, yb, yc;
	scanf("%d", &n);
	for (i = 1;i <= n;++i)
		scanf("%d %d", &a[i].x, &a[i].y);
	for (i = 1;i <= n;++i)
		for (int j = i + 1;j <= n;++j)
		{
			int tem = 2;
			xa = a[i].x; ya = a[i].y;
			xb = a[j].x; yb = a[j].y;
			for (int k = j + 1;k <= n;++k)
			{
				xc = a[k].x; yc = a[k].y;
				if ((yb - ya)*(xc - xa) == (yc - ya)*(xb - xa)) ++tem;
			}
			// if (tem>ans) ans=tem;  
			tem>ans ? ans = tem : 1;
		}
	printf("%d\n", ans);
	return 0;
}