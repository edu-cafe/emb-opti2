#include <stdio.h>

int prod1(int n)
{
	int i, prod;
	for(i=1, prod=1; i<=n; i++)
		prod *= i;
		
	return prod;
}
int prod2(int n)
{
	int i, prod;
	for(i=n, prod=1; i; i--)
		prod *= i;
		
	return prod;
}
	
int main(void) 
{
	printf("prod1:%d\n", prod1(5));
	printf("prod2:%d\n", prod2(5));
	return 0;
}
