#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;

int main()
{
	double a, b, c, m, n, l;
	while (cin >> a >> b >> c >> m >> n >> l) {
		double V = sqrt((4 * a*a*b*b*c*c
			- a*a*(b*b + c*c - m*m)*(b*b + c*c - m*m)
			- b*b*(c*c + a*a - n*n)*(c*c + a*a - n*n)
			- c*c*(a*a + b*b - l*l)*(a*a + b*b - l*l)
			+ (a*a + b*b - l*l)*(b*b + c*c - m*m)*(c*c + a*a - n*n))) / 12;
		printf("%.3lf\n", V);
	}
}