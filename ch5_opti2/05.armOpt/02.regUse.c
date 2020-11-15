#include <stdio.h>

void f1(void)
{
	int n1, n2, n3, n4, n5, n6;
	int rst;

	printf("Input Nuber(n1,n2) => ");
	scanf("%d,%d", &n1, &n2);
	n3 = n1 + n2;
	n4 = n1 - n2;
	n5 = n1 * n2;
	n6 = n1 / n2;
	printf("n3:%d, n4:%d, n5:%d, n6:%d\n", n3, n4, n5, n6);

	n3 = n2 + n1;
	n4 = n2 - n1;
	n5 = n2 * n1;
	n6 = n2 / n1;
	printf("n3:%d, n4:%d, n5:%d, n6:%d\n", n3, n4, n5, n6);

	n3 = n1 + --n2;
	n4 = n1 - --n2;
	n5 = n1 * --n2;
	n6 = n1 / --n2;
	printf("n3:%d, n4:%d, n5:%d, n6:%d\n", n3, n4, n5, n6);
}
void f2(void)
{
	int n1, n2;
	int n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14;
	int rst;

	printf("Input Nuber(n1,n2) => ");
	scanf("%d,%d", &n1, &n2);
	n3 = n1 + n2;
	n4 = n1 - n2;
	n5 = n1 * n2;
	n6 = n1 / n2;

	n7 = n2 + n1;
	n8 = n2 - n1;
	n9 = n2 * n1;
	n10 = n2 / n1;

	n11 = n1 + --n2;
	n12 = n1 - --n2;
	n13 = n1 * --n2;
	n14 = n1 / --n2;
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", 
		n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14);
}
	
int main(void) 
{
	f1();
	f2();
	return 0;
}
