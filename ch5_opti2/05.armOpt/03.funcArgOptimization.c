#include <stdio.h>

int func1(int d1, int d2, int d3)
{
	return d1+d2+d3;
}
int func2(int d1, int d2, int d3, int d4, int d5, int d6)
{
	return d1+d2+d3+d4+d5+d6;
}
	
int main(void) 
{
	int rst1, rst2;
	
	rst1 = func1(1, 2, 3);
	rst2 = func2(1, 2, 3, 4, 5, 6);
	printf("rst1:%d, rst2:%d\n", rst1, rst2);
	return 0;
}
