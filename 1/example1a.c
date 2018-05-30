#include <stdio.h>

double multiple(int n){
	double x = 1;
	int i;
	for (i = 2; i < n; ++i)
	{
		x *= i;
	}
	return x;
}

double multiple2(int n){
	double x = 1;
	int i;
	for (i = 0; i < n; ++i)
	{
		x *= i*2 + 1;
	}
	return x;
}

int main(int argc, char const *argv[])
{
	double e;
	int n=2;
	scanf("%lf", &e);
	double pi1=2.0,pi2=8.0/3.0;
	while(pi2 - pi1 > e){
		n++;
		pi1 = pi2;
		pi2 = pi2 + multiple(n)*2.0/multiple2(n);
	}
	printf("%d %.7lf\n", n, pi2);
	return 0;
}