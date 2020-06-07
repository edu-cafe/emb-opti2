#include <stdio.h>

int n1=10, n2=20, n3=30, n4=40, n5=50, n6=60, n7=70;

int func1(int d1, int d2, int d3, int d4)
{
	return d1+d2+d3+d4;
}
int func2(int d1, int d2, int d3, int d4, int d5, int d6, int d7)
{
	return d1+d2+d3+d4+d5+d6+d7;
}

int main(void)
{
	int rst1, rst2;
	rst1 = func1(n1, n2, n3, n4);
	rst2 = func2(n1, n2, n3, n4, n5, n6, n7);
	printf("rst1:%d, rst2:%d\n", rst1, rst2);
	return 0;
}
