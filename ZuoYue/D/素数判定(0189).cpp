#include<stdio.h>
int is_prime(int n)
{
	int i;
	for (i = 2;i<n;i++)
		if (n%i == 0)
			return 0;
	return 1;
}
int main(void)
{
	int a, b, count, t;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		if (a > b)
		{
			t = a;a = b;b = t;
		}

		for (count = 0;a < b;a++)
			if (is_prime(a))
				count++;
		printf("%d\n", count);

	}
	return 0;
}