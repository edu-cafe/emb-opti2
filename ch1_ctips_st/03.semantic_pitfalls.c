#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#if 0
// pinter != array

int main(void)
{
	char *str1 = NULL;
	char *str2 = "hello..";
	char *str3 = "hi~~";	

#ifndef TEST	
	str1 = malloc(strlen(str2) + strlen(str3) + 1);	
	assert(str1);
	strcpy(str1, str2);
	strcat(str1, str3);
	//memset(str1, 0xAC, strlen(str2) + strlen(str3) + 1);
	//strncpy(str1, str2, strlen(str2));		//null error
#else
	strcpy(str1, str2);
	strcat(str1, str3);
#endif
	
	printf("str1:%s, str2:%s, str3:%s\n", str1, str2, str3);
	free(str1);

	return 0;
}
#endif


#if 0
// Á¦À¯¹ý(synecdoche) pitfalls

int main(void)
{
	char *s1, *s2;
	
	s1 = "hi~~~";
	s2 = s1;
	printf("s1:%s, s2:%s\n", s1, s2);
	//s2[0] = 'A';		//???
	
	s1 = malloc(10);
	assert(s1);
	strcpy(s1, "hello~~");	
	s2 = s1;
	
	printf("s1:%s, s2:%s\n", s1, s2);
	free(s1);

	printf("s2:%s\n", s2);
	
	return 0;
}
#endif


#if 0
// null pointer error

int main(void)
{
	char *str1="hello";
	char *p=0;
	
	//printf("%s\n", p);
	
	if(p == (char*)0) printf("Null Pointer!!\n");
	if(strcmp(str1, (char*)p) == 0) printf("Same String\n");
	else printf("Different String\n");

	return 0;
}
#endif


#if 0
// integer overflow

int main(void)
{
#ifndef TEST
	char d1=0;
	char d2=0;
	char d3=0;
#else
	unsigned char d1=0;
	unsigned char d2=0;
	unsigned char d3=0;
#endif
	
	printf("d1:%d, d2:%d, d3:%d\n", d1, d2, d3);
	d1=57;  d2=33;
	d3 = d1 + d2;
	printf("d1:%d, d2:%d, d3:%d\n", d1, d2, d3);
	puts("----------------------------------------");
	d1=127;  d2=128;
	d3 = d1 + d2;
	printf("d1:%d, d2:%d, d3:%d\n", d1, d2, d3);
	puts("----------------------------------------");
	d1=100;  d2=125;
	d3 = d1 + d2;
	printf("d1:%d, d2:%d, d3:%d\n", d1, d2, d3);
	puts("----------------------------------------");
	d1=200;  d2=220;
	d3 = d1 + d2;
	printf("d1:%d, d2:%d, d3:%d\n", d1, d2, d3);

	return 0;
}
#endif


#if 0
// integer overflow

#include <limits.h>
//CHAR_MIN, CHAR_MAX, UCHAR_MAX, INT_MAX, INT_MIN, UINT_MAX
int main(void)
{
	char d1=0;
	char d2=0;
	char d3=0;
	
	printf("d1:%d, d2:%d, d3:%d\n", d1, d2, d3);
	d1=57;  d2=33;
	assert((unsigned)d1<=CHAR_MAX);
	assert((unsigned)d2<=CHAR_MAX);
	d3 = d1 + d2;
	assert((unsigned)d3<=CHAR_MAX);
	printf("d1:%d, d2:%d, d3:%d\n", d1, d2, d3);
	puts("----------------------------------------");
	
#if 0
	d1=127;  d2=128;
	assert((unsigned)d1<=CHAR_MAX);
	assert((unsigned)d2<=CHAR_MAX);
	d3 = d1 + d2;
	assert((unsigned)d3<=CHAR_MAX);
	printf("d1:%d, d2:%d, d3:%d\n", d1, d2, d3);
	puts("----------------------------------------");
#endif

#if 0
	d1=100;  d2=125;
	assert((unsigned)d1<=CHAR_MAX);
	assert((unsigned)d2<=CHAR_MAX);
	d3 = d1 + d2;
	assert((unsigned)d3<=CHAR_MAX);
	printf("d1:%d, d2:%d, d3:%d\n", d1, d2, d3);
	puts("----------------------------------------");
#endif

#if 0
	d1=200;  d2=220;
	if((unsigned)d1>CHAR_MAX || (unsigned)d2>CHAR_MAX) assert(0);
	d3 = d1 + d2;
	assert((unsigned)d3<=CHAR_MAX);
	printf("d1:%d, d2:%d, d3:%d\n", d1, d2, d3);
#endif

	return 0;
}
#endif


#if 0
// aliasing pitfalls

int main(void)
{
	char *s1=NULL, *s2=NULL;
	
	s1 = malloc(10);
	assert(s1);
	strcpy(s1, "hello~~");
	s2 = s1;	
	
	printf("addr_s1:%p, addr_s2:%p\n", s1, s2);
	printf("s1:%s, s2:%s\n", s1, s2);
	free(s1);
	s1 = NULL;

	printf("addr_s1:%p, addr_s2:%p\n", s1, s2);
	strcpy(s2, "kim!!");
	printf("s2:%s\n", s2);
	
	return 0;
}
#endif


#if 0
// restrict keyword
// gcc -std=c99
// library ex : pthread_mutex_init

void dumpArray(double * restrict arr, int size) {
	int i;
	for(i=0; i<size; i++) {
		printf("%7.1f", arr[i]);
		if(((i+1)%5)==0) putchar('\n');
	}
	putchar('\n');
}
void addArray(double *restrict a1, double *restrict a2, int size) {
	int i;
	for(i=0; i<size; i++) {
		a1[i] += a2[i];
	}
}
int main(void)
{
	double v1[] = {10.1, 10.2, 10.3, 10.4, 10.5}; 
	double v2[] = {10.1, 10.2, 10.3, 10.4, 10.5};
	
	dumpArray(v1, sizeof(v1)/sizeof(double));
	puts("==============================================");
	addArray(v1, v2, sizeof(v1)/sizeof(double));
	dumpArray(v1, sizeof(v1)/sizeof(double));
	
	return 0;
}
#endif

#if 1
// restrict keyword
// gcc -std=c99

void updateArray(int size, int *a, int *b, int *restrict c)
{
	int i;
	for(i=0; i<size; i++) {
		a[i] += c[i];
		b[i] += c[i];
	}	
}
void dumpArray(int *restrict arr, int size) {
	int i;
	for(i=0; i<size; i++) {
		printf("%5d", arr[i]);
		if(((i+1)%5)==0) putchar('\n');
	}
	putchar('\n');
}
int main(void)
{
	int d1[] = {10, 20, 30, 40, 50};
	int d2[] = {100, 200, 300, 400, 500};
	int d3[] = {5, 5, 5, 5, 5};
	
	dumpArray(d1, sizeof(d1)/sizeof(int));
	puts("------------------------------------------");
	dumpArray(d2, sizeof(d2)/sizeof(int));
	puts("==========================================");
	updateArray(sizeof(d1)/sizeof(int), d1, d2, d3);
	dumpArray(d1, sizeof(d1)/sizeof(int));
	puts("------------------------------------------");
	dumpArray(d2, sizeof(d2)/sizeof(int));
	return 0;
}
#endif

	
	