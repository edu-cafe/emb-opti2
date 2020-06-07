#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#if 0
// free error

int main(void)
{
	int i;
	char *pc = (char*)malloc(20);
	
	printf("malloc area initialize start...\n");
	for(i=0; i<20; i++) {
		pc[i] = 0;
	}
	printf("malloc area initialize end...\n");
	free(pc);
	
#ifndef TEST
	pc = NULL;
#endif
	
	free(pc);
	printf("Main End!!\n");
	
	return 0;
}
#endif


#if 0
// my free function

#define	safeFree(p)		saferFree((void**)&(p))
void saferFree(void **pp)
{
	if(pp != NULL && *pp != NULL) {
		free(*pp);
		*pp = NULL;
	}
}
int main(void)
{
	int *data;
	int cnt=10, i;
	data = (int*)malloc(cnt*sizeof(int));
	for(i=0; i<cnt; i++) {
		data[i] = 10 + i;
	}
	printf("Before Free : %p\n", data);
	for(i=0; i<cnt; i++) {
		printf("data[%d] : %d\n", i, data[i]);
	}
	
	safeFree(data);
	printf("After Free : %p\n", data);
	for(i=0; i<cnt; i++) {
		printf("data[%d] : %d\n", i, data[i]);
	}
	
	return 0;
}
#endif



#if 0
//memory limit error

int main(void)
{
	int i;
	char *pc = (char*)malloc(20);
	
	printf("malloc area initialize start...\n");
#ifndef TEST
	for(i=0; i<20; i++) {
#else
	for(i=0; i<30; i++) {
#endif
		pc[i] = 0;
	}
	printf("malloc area initialize end...\n");
	
	free(pc);
	pc = NULL;
	printf("Main End!!\n");
	
	return 0;
}
#endif


#if 0
//malloc argument error

#include <errno.h>
int main(void)
{
	int size = -10;
	int *p;
	puts("111111\n");
	p = malloc(size);
#ifdef TEST
	if(p==NULL) {
		printf("malloc error!!");
		printf("%s(errno:%d)\n", strerror(errno), errno);
		exit(1);
	}
#endif
	puts("222222\n");
	*p = 10;
	puts("333333\n");
	free(p);
	puts("444444\n");
	return 0;
}
#endif





