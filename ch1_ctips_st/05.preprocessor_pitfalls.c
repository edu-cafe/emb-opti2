#include <stdio.h>
#include <stdlib.h>

#if 1
// macro define : space problem

#ifndef TEST
int f (int x)
{
	return x-1;
}
#else
#define	f (x)	((x)-1)
//#define	f(x)	((x)-1)
#endif

int main(void)
{
	printf("%d\n", f (5));
	printf("%d\n", f (5-1));

	return 0;
}
#endif


#if 0
// macro != function

#ifndef TEST
#define	abs(x)	x>=0?x:-x
#else
#define	abs(x)	(((x)>=0)?(x):(-(x)))
#endif

int main(void)
{
	printf("%d\n", abs(5));
	printf("%d\n", abs(-5));
	printf("%d\n", abs(5-1));
	printf("%d\n", abs(5-7));
	printf("%d\n", abs(-7+2));
	printf("%d\n", abs(7)+1);
	
	return 0;
}
#endif


#if 0
// macro != function

#ifndef SOO
#define	max(a,b)	(((a)>(b))?(a):(b))
#else
int max(int a, int b) {
	if(a > b) return a;
	else return b;
}
#endif

int main(void)
{
	printf("%d\n", max(5, 3));
	printf("%d\n", max(-5, 3));
	printf("%d\n", max(5-1, -7+1));
	printf("%d\n", max(2+3+1, 10-3));
	printf("%d\n", max(7, 3)+1);
	
	printf("===============================\n");
	int data[10] = {3, 9, 4, 10, 7, 1, 2, 8, 6, 5};
	int i, big=0;
#ifndef TEST
	for(big=data[0], i=1; i<10; i++) {
		big = max(big, data[i]);
		printf("for_%d(big:%d)\n", i, big);
	}
#else
	big=data[0];  i=1;
	while(i<10) {		
		big = max(big, data[i++]);
		printf("while_%d(big:%d)\n", i, big);
	}
#endif
	printf("big : %d\n", big);
	
	return 0;
}
#endif


#if 0
// macro != statement

#ifndef SOO
#define	assert(e)	\
	if(!(e)) assert_error(__FILE__, __LINE__)
#else
#define	assert(e)	\
	((int)((e) || assert_error(__FILE__, __LINE__)))
#endif
		
int assert_error(char *file, int line) {
	printf("Error : %s line %d !!\n", file, line);
	exit(1);
}

int main(void)
{
	int d1=10, d2=-20;
	
	printf("Main Start...\n");

#ifndef TEST	
	assert(d1<d2);
#else
	if(d1>0 && d2>0) assert(d1>d2);
	else assert(d1<d2);
#endif
	
	printf("Main Done!!\n");
	
	return 0;
}
#endif


#if 0
// macro != type_define

#include <string.h>

#ifndef TEST
typedef struct _info * pINFO;
#else
#define	pINFO	struct _info *
#endif

struct _info {
	char name[20];
	int age;
};

int main(void)
{
	pINFO d1;
	pINFO d2, d3;
	
	d1 = (pINFO)malloc(sizeof(struct _info));
	strcpy(d1->name, "kim");
	d1->age = 10;	
	printf("d1--> name:%s, age:%d\n", d1->name, d1->age);
	
	d2 = (pINFO)malloc(sizeof(struct _info));
	strcpy(d2->name, "park");
	d2->age = 20;	
	printf("d2--> name:%s, age:%d\n", d2->name, d2->age);
	
	d3 = (pINFO)malloc(sizeof(struct _info));
	strcpy(d3->name, "lee");
	d3->age = 30;	
	printf("d3--> name:%s, age:%d\n", d3->name, d3->age);
	
	free(d1);
	free(d2);
	free(d3);
	
	return 0;
}
#endif


#if 0
//debugging : macro using

#include <stdarg.h>

#ifdef DEBUG
#define	MY_DEBUG(arg)	my_debug arg
#define	DMSG_INT(arg)	fprintf(stderr, #arg ":%d\n", arg)
#define	DMSG_STR(arg)	fprintf(stderr, #arg ":%s\n", arg)
#define	DMSG_CHAR(arg)	fprintf(stderr, #arg ":%c\n", arg)
#else
#define	MY_DEBUG(arg)
#define	DMSG_INT(arg)
#define	DMSG_STR(arg)
#define	DMSG_CHAR(arg)
#endif

void my_debug(char *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	vfprintf(stderr, fmt, argp);
	va_end(argp); 
}
int main(void)
{
	char name[] = "kim";
	int age=17;
	char gender = 'F';
	
	printf("Main Start...\n");
	MY_DEBUG(("name:%s, age:%d, gender:%c\n", name, age, gender));
	DMSG_STR(name);
	DMSG_INT(age);
	DMSG_CHAR(gender);
	printf("Main End...\n");
	return 0;
}
#endif




