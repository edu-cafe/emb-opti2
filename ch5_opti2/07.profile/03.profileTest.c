#include <stdio.h>
#include <stdlib.h>

int prime(int num);
unsigned long long sump=0, sumnp=0;
int cnt_prime=0, cnt_no_prime=0;

void sum_prime(int n) {	sump += n; cnt_prime++; }
void sum_no_prime(int n) {	sumnp += n; cnt_no_prime++; }

int main(void)
{
	int i;
	
	int colcnt = 0;
	for(i=2; i<=50000; i++) {
		if(prime(i)) {
			colcnt++;
			if(colcnt%10 == 0) {
				printf("%05d\n", i);
				colcnt = 0;
			} else {
				printf("%05d ", i);
			}
			sum_prime(i);
		} else sum_no_prime(i);
	}
	printf("\n------------------------------------------\n");
	printf("sum_prime:%llu(cnt:%d), sum_no_prime:%llu(cnt:%d)\n", 
		sump, cnt_prime, sumnp, cnt_no_prime);
	
	return 0;
}

int prime(int num)
{
	int i;
	for(i=2; i<num; i++) {
		if(num%i == 0) return;
	}
	return 1;
}

