#include<stdio.h>
#include<string.h>
struct king
{
	char name[60];
	char topic[1000];
	int len;
}peo[1000];
int main()
{
	struct king t;
	memset(peo, '\0', sizeof(peo));
	int n, i, j;
	scanf("%d", &n);
	for (i = 0;i<n;i++)
	{
		scanf("%s %s", peo[i].name, peo[i].topic);
		peo[i].len = strlen(peo[i].topic);
	}
	for (i = 0;i<n - 1;i++)
	{
		for (j = 0;j<n - 1 - i;j++)
		{
			if (peo[j].len<peo[j + 1].len || peo[j].len == peo[j + 1].len&&strcmp(peo[j].topic, peo[j + 1].topic)<0)
			{
				t = peo[j];
				peo[j] = peo[j + 1];
				peo[j + 1] = t;
			}
			if (peo[j].len == peo[j + 1].len&&strcmp(peo[j].topic, peo[j + 1].topic) == 0)
			{
				if (strcmp(peo[j].name, peo[j + 1].name)>0)
				{
					t = peo[j];
					peo[j] = peo[j + 1];
					peo[j + 1] = t;
				}
			}
		}
	}
	for (i = 0;i<n;i++)
		printf("%s\n", peo[i].name);
	return 0;
}