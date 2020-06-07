#include <stdio.h>

typedef struct _info1 {
	char d1;
	int d2;
	short d3;
	int d4;
	char d5;
	int d6;
} INFO1;

typedef struct _info2 {
	char d1;
	char d5;
	short d3;
	int d2;
	int d4;
	int d6;
} INFO2;

int main(void)
{
	INFO1 data1[1000];	
	INFO2 data2[1000];	

	printf("size_INFO1:%d, size_data1:%u\n", 
		sizeof(INFO1), sizeof(data1));
	printf("size_INFO2:%d, size_data2:%u\n", 
		sizeof(INFO2), sizeof(data2));

	return 0;
}
