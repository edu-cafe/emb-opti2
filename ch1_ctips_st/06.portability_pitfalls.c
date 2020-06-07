#include <stdio.h>
#include <stdlib.h>

#if 0
// data type size

int main(void)
{
	printf("size_char:%lu, size_short:%lu\n", sizeof(char), sizeof(short));
	printf("size_int:%lu, size_long:%lu\n", sizeof(int), sizeof(long));
	printf("size_long_long:%lu, size_float:%lu\n", sizeof(long long), sizeof(float));
	printf("sizeof_double:%lu, size_long_double:%lu\n", sizeof(double), sizeof(long double));

	return 0;
}
#endif


#if 0
// char -> int casting error

int main(void)
{
	char c;
	int d1, d2, d3;
	
	c = 0xA5;
	d1 = c;
	d2 = (unsigned char)c;
	d3 = (unsigned)c;
	printf("c:%2hhx, d1:%8x\n", c, d1);
	printf("c:%2hhx, d2:%8x\n", c, d2);
	printf("c:%2hhx, d3:%8x\n", c, d3);
	
	return 0;
}
#endif


#if 0
// shift op

int main(void)
{
	int d1=42000;
	unsigned char d2 = 50;
	long long d3=42000;
	
	printf("%d(%x), %d(%x)\n", (-1)>>1, (-1)>>1, (-1)/2, (-1)/2);
	printf("%d(%x), %d(%x)\n", (unsigned)(-1)>>1, (unsigned)(-1)>>1, (-1)/2, (-1)/2);
	printf("====================================\n");
	printf("d1:%d(0x%x) d1<<2:%d(0x%x)\n", d1, d1, d1<<2, d1<<2);
	printf("d1:%d(0x%x) d1<<31:%d(0x%x)\n", d1, d1, d1<<31, d1<<31);
	printf("d1:%d(0x%x) d1<<0:%d(0x%x)\n", d1, d1, d1<<0, d1<<0);
	printf("d1:%d(0x%x) d1<<-2:%d(0x%x)\n", d1, d1, d1<<-2, d1<<-2);
	printf("d1:%d(0x%x) d1<<32:%d(0x%x)\n", d1, d1, d1<<32, d1<<32);
	printf("====================================\n");
	printf("d2:%d(0x%x) d2<<2:%d(0x%x)\n", d2, d2, d2<<2, d2<<2);
	printf("d2:%d(0x%x) d2<<31:%d(0x%x)\n", d2, d2, d2<<7, d2<<7);
	printf("d2:%d(0x%x) d2<<32:%d(0x%x)\n", d2, d2, d2<<8, d2<<8);
	printf("d2:%hhd(0x%hhx) d2<<32:%hhd(0x%hhx)\n", d2, d2, d2<<8, d2<<8);
	printf("====================================\n");
	printf("d3:%lld(0x%llx) d3<<2:%lld(0x%llx)\n", d3, d3, d3<<2, d3<<2);
	printf("d3:%lld(0x%llx) d3<<31:%lld(0x%llx)\n", d3, d3, d3<<32, d3<<32);
	printf("d3:%lld(0x%llx) d3<<32:%lld(0x%llx)\n", d3, d3, d3<<64, d3<<64);
	
	return 0;
}
#endif


#if 0
// upper/lower char conversion

#ifndef TEST
#define	toupper(c)	((c)+('A'-'a'))
#define	tolower(c)	((c)+('a'-'A'))
#else
#define	toupper(c)	(((c)>='a' && (c)<='z')?((c)+('A'-'a')):(c))
#define	tolower(c)	(((c)>='A' && (c)<='Z')?((c)+('a'-'A')):(c))
#endif

int main(int argc, char *argv[])
{
	int c;
	FILE *fp;
	if((fp = fopen(argv[1], "r")) == NULL) {
		perror("file open");
		exit(1);
	}
	printf("file open ok!!\n\n");

	while((c = fgetc(fp)) != EOF) {
		putchar(toupper(c));
	}
	putchar('\n');

	return 0;
}

//#a.out test1.txt		//tolower
//#a.out test2.txt		//toupper
//#a.out test3.txt		//upper_lower_character_mixed --> error  --> -DTEST
#endif

#if 0
// upper/lower char conversion

#ifndef TEST
#define	toupper(c)	(((c)>='a' && (c)<='z')?((c)+('A'-'a')):(c))
#define	tolower(c)	(((c)>='A' && (c)<='Z')?((c)+('a'-'A')):(c))
#else
int toupper(int c) {
	if(c>='a' && c<='z') return c + ('A'-'a');
	return c;
}
#endif

int main(int argc, char *argv[])
{
	char str[] = "Hello, hi~~";
	char *p=str;
	while(*p) {
		putchar(toupper(*p++));
	}
	putchar('\n');

	return 0;
}

#endif


#if 0
// address 0 memory access

int main(void)
{
	char *p=NULL;
	
	printf("%d\n", *p);
		
	return 0;
}
#endif


#if 1
// endian

int main(void)
{
	int num = 0x12345678;
	char *p=(char*)&num;
	int i;
	
	printf("addr_num:%p, value_num:%8x\n\n", &num, num);
	for(i=0; i<4; i++, p++) {
		printf("addr:%p, value:%2hhx\n", p, *p);
	}
		
	return 0;
}
#endif


