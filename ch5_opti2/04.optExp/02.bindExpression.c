#include <stdio.h>

float n1, n2, n3;

int main(void)
{
	float rst1, rst2;

	printf("Input Number(n1,n2,n3) => ");
	scanf("%f,%f,%f", &n1, &n2, &n3);
	
	rst1 = n1/n3 + n2/n3;
	rst2 = (n1+n2)/n3;
	
	printf("rst1:%.1f, rst2:%.1f\n", rst1, rst2);
	
	return 0;
}
