#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long fact1(int n) {
	if((n==1) || (n==0)) return 1;
	else return n * fact1(n-1);
}

unsigned long long fact2(int n) {
	int i=1;
	long long rst=1;
	if(n==0) return 1;
	for(i=1; i<=n; i++) rst *= i;
	return rst;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	unsigned long long rst1=0, rst2=0;
	unsigned long s_tick=0, e_tick=0;
	unsigned long dur1=0, dur2=0;

	s_tick = clock();
	rst1 = fact1(n);
	e_tick = clock();
	dur1 = e_tick - s_tick;

	s_tick = clock();
	rst2 = fact2(n);
	e_tick = clock();
	dur2 = e_tick - s_tick;

	printf("rst1:%llu, rst2:%llu\n", rst1, rst2);
	printf("fact1_dur:%lu clocks, fact2_dur:%lu clocks\n", dur1, dur2);
	return 0;
}
