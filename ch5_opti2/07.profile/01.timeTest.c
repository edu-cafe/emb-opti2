#include <stdio.h>
#include <math.h>

#define	NO	10

void calcSin(int *degree, double *rst_sin)
{
	int i;
	
	for(i=0; i<NO; i++) {
		rst_sin[i] = sin(degree[i]);
	}
}

void calcCos(int *degree, double *rst_cos)
{
	int i;
	
	for(i=0; i<NO; i++) {
		rst_cos[i] = cos(degree[i]);
	}
}

void calcTan(int *degree, double *rst_tan)
{
	int i;
	
	for(i=0; i<NO; i++) {
		rst_tan[i] = tan(degree[i]);
	}
}

void printRst(int *degree, double *rst)
{
	int i;
	
	printf("\nResult...\n");
	for(i=0; i<NO; i++) {
		printf("rst_%d : %3.f\n", degree[i], rst[i]);
	}
}

void printAll(int *degree, double *rst1, double *rst2, double *rst3)
{
#if TCASE==1
	int i;
	
	printf("\nResult1...\n");
	for(i=0; i<NO; i++) {
		//printf("Sin %d : %3.f\n", degree[i], sin(degree[i]));
		printf("rst_%d : %3.f\n", degree[i], rst1[i]);
	}
	printf("\nResult2...\n");
	for(i=0; i<NO; i++) {
		printf("rst_%d : %3.f\n", degree[i], rst2[i]);
	}
	printf("\nResult3...\n");
	for(i=0; i<NO; i++) {
		printf("rst_%d : %3.f\n", degree[i], rst3[i]);
	}
#elif TCASE==2
	printRst(degree, rst1);
	printRst(degree, rst2);
	printRst(degree, rst3);
#endif
}

int main(void)
{
	int degree[NO]={0,15,30,45,60,75,90,180,270,360};
	double rst_sin[NO], rst_cos[NO], rst_tan[NO];
	int i;
	
	for(i=1; i<=200; i++) {
		calcSin(degree, rst_sin);
		calcCos(degree, rst_cos);
		calcTan(degree, rst_tan);
		printAll(degree, rst_sin, rst_cos, rst_tan);
	}

	
	return 0;
}
