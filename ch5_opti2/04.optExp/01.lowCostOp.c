#include <stdio.h>

int d1, d2;

int main(void)
{
	int rst1, rst2, rst3, rst4;
	
	printf("Input two num(num1,num2) => ");
	scanf("%d,%d", &d1, &d2);
	rst1 = d1 % 8;
	rst2 = d2 & 7;
	printf("d1:%d, d2:%d, rst1:%d, rst2:%d\n", d1, d2, rst1, rst2);
	
	rst3 = d1 / 4;
	rst4 = d2 >> 2;
	printf("d1:%d, d2:%d, rst3:%d, rst4:%d\n", d1, d2, rst3, rst4);
	
	return 0;
}
