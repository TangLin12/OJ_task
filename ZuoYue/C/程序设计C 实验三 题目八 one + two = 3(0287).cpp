#include<stdio.h>
#include<string.h>
int cmp(char ar[]);
int main(void)
{
	int count = 0, i = 10, sum = 0, temp = 0;
	char ar[10];
	while (scanf("%s", ar) != EOF)
	{
		if (strcmp(ar, "+") == 0)
		{
			if (count == 2)
				sum = temp;
			if (count == 1)
				sum = temp / 10;
			count = 0;
			i = 10;
			temp = 0;

		}
		else if (strcmp(ar, "=") == 0)
		{
			if (count == 2)
				sum += temp;
			else if (count == 1)
				sum += temp / 10;
			if (sum == 0)
				return 0;
			else
				printf("%d\n", sum);
			sum = 0;
			temp = 0;
			i = 10;
			count = 0;

		}
		else
		{
			count++;
			temp += i*cmp(ar);
			i = i / 10;
		}
	}
}
int cmp(char ar[])
{
	int i = 0;
	char * num[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	while (strcmp(ar, num[i]) != 0)
		i++;
	return i;
}