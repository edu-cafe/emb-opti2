#include <stdio.h>
char f1(char d) {
	return d + 1;
}
short f2(short d) {
	return d + 1;
}
int f3(int d) {
	return d + 1;
}
int main(void) {
	int rst1, rst2, rst3;
	rst1 = f1(10);
	rst2 = f2(10);
	rst3 = f3(10);
	printf("rst1:%d, rst2:%d, rst3:%d\n", rst1, rst2, rst3);
}
