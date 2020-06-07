#include <stdio.h>
#include <string.h>

typedef struct _info {
	char d1[1000];
	int d2;
	short d3;
	int d4;
	char d5[1000];
	int d6;
} INFO;

#ifdef ROM
INFO data[1000];
#else
INFO data[1000]={
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
	{"kim", 100, 20, 300, "hello", 400},
};
#endif

void f1(INFO data)
{
	int d1=10;
	printf("f1->&data:%p, &d1:%p\n", &data, &d1);
	printf("%s, %d, %d, %d, %s, %d\n", 
		data.d1, data.d2, data.d3, data.d4, data.d5, data.d6);
}
void f2(INFO *data)
{
	int d1=20;
	printf("f2->&data:%p, &d1:%p\n", &data, &d1);
	printf("%s, %d, %d, %d, %s, %d\n", 
		data->d1, data->d2, data->d3, data->d4, data->d5, data->d6);
}

int main(void)
{
	strcpy(data[0].d1, "kim");
	data[0].d2 = 100;
	data[0].d3 = 20;
	data[0].d4 = 300;
	strcpy(data[0].d5, "hello");
	data[0].d6 = 400;

	f1(data[0]);
	f2(&data[0]);

	return 0;
}
