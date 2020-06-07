#include <stdio.h>

typedef struct _info {
	char d1[1000];
	int d2;
	short d3;
	int d4;
	char d5[1000];
	int d6;
} INFO;

void f3()
{
	int v1=1, v2=2;
	printf("f3->&v1:%p, &v2:%p\n", &v1, &v2);
}

void f1(INFO data)
{
	int d1=10;
	printf("f1->&data:%p, &d1:%p\n", &data, &d1);
	f3();
	printf("%s, %d, %d, %d, %s, %d\n", 
		data.d1, data.d2, data.d3, data.d4, data.d5, data.d6);
}
void f2(INFO *data)
{
	int d1=10;
	printf("f2->&data:%p, &d1:%p\n", &data, &d1);
	f3();
	printf("%s, %d, %d, %d, %s, %d\n", 
		data->d1, data->d2, data->d3, data->d4, data->d5, data->d6);
}

int main(void)
{
	int n1=10;
	INFO data = {"kim", 100, 20, 300, "hello", 400};	
	int n2=20;

#ifndef PTR
	printf("main->&n1:%p, &data:%p, &n2:%p\n", &n1, &data, &n2);
	f1(data);
#else
	printf("main->&n1:%p, &data:%p, &n2:%p\n", &n1, &data, &n2);
	f2(&data);
#endif

	return 0;
}
