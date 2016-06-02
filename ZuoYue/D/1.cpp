#include"stdio.h"
#include"string.h"
int main()
{
	int n, i, len, j, p, count = 0;
	char x[50];
	char temp1[50], temp2[50], t, temp3[50];
	char fin[50][50];
	memset(fin, '\0', sizeof(fin));
	scanf("%d", &n);
	scanf("%s", x);
	len = strlen(x);
	for (i = 0;i<len - 1;i++)
	{
		for (j = 0;j<len - 1 - i;j++)
		{
			if (x[j]>x[j + 1])
			{
				t = x[j];
				x[j] = x[j + 1];
				x[j + 1] = t;
			}
		}
	}
	for (i = 0;i<n;i++)
	{
		scanf("%s", temp1);
		strcpy(temp2, temp1);
		for (p = 0;p<len - 1;p++)
		{
			for (j = 0;j<len - 1 - p;j++)
			{
				if (temp2[j]>temp2[j + 1])
				{
					t = temp2[j];
					temp2[j] = temp2[j + 1];
					temp2[j + 1] = t;
				}
			}
		}
		if (strcmp(temp2, x) == 0)
		{
			strcpy(fin[count], temp1);
			count++;
		}
		memset(temp1, '\0', sizeof(temp1));
		memset(temp2, '\0', sizeof(temp2));
	}
	for (i = 0;i<count - 1;i++)
	{
		for (j = 0;j<count - 1 - i;j++)
		{
			if (strcmp(fin[j], fin[j + 1])>0)
			{
				strcpy(temp3, fin[j]);
				strcpy(fin[j], fin[j + 1]);
				strcpy(fin[j + 1], temp3);
			}
		}
	}
	for (i = 0;i<count;i++)
	{
		printf("%s\n", fin[i]);
	}
	printf("%d\n", count);
	return 0;
}