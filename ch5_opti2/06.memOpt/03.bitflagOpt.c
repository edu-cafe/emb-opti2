#include <stdio.h>

typedef struct _flag1 {
	int s1;
	int s2;
	int s3;
	int s4;
	int s5;
	int s6;
	int s7;
	int s8;
	int s9;
	int s10;
} INFO1;

typedef struct _flag2 {
	unsigned int s1:1, s2:1, s3:1, s4:1, s5:2, s6:1, s7:1, s8:1, s9:1, s10:2;
} INFO2;

void print_data(INFO1 *data1, INFO2 *data2)
{
	int i;
	for(i=0; i<50; i++) {
		printf("%d(%d) ", data1[i].s1, data2[i].s1);
		printf("%d(%d) ", data1[i].s2, data2[i].s2);
		printf("%d(%d) ", data1[i].s3, data2[i].s3);
		printf("%d(%d) ", data1[i].s4, data2[i].s4);
		printf("%d(%d) ", data1[i].s5, data2[i].s5);
		printf("%d(%d) ", data1[i].s6, data2[i].s6);
		printf("%d(%d) ", data1[i].s7, data2[i].s7);
		printf("%d(%d) ", data1[i].s8, data2[i].s8);
		printf("%d(%d) ", data1[i].s9, data2[i].s9);
		printf("%d(%d) ", data1[i].s10, data2[i].s10);
		putchar('\n');
	}
}

int main(void)
{
	INFO1 data1[1000]={0,};
	INFO2 data2[1000]={0,};
	int i;

	printf("size_data1:%u, size_data2:%u\n", sizeof(data1), sizeof(data2));
	print_data(data1, data2);
	printf("-----------------------------------------------------\n");
	for(i=0; i<1000; i++) {
		data1[i].s1 = 1;
		data2[i].s1 = 1;
		data1[i].s2 = 1;
		data2[i].s2 = 1;
		data1[i].s3 = 1;
		data2[i].s3 = 1;
		data1[i].s4 = 1;
		data2[i].s4 = 1;
		data1[i].s5 = 2;
		data2[i].s5 = 2;
	}
	print_data(data1, data2);


	return 0;
}
