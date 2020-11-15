#include <stdio.h>
int func(void);
int global_var;
void f1(void) {
	int i;
	for(i=0; i<100; i++) {
		if(func()) global_var++;
	}
}
void f2(void) {
	int i, local_var=global_var;
	for(i=0; i<100; i++) {
		if(func()) local_var++;
	}
	global_var = local_var;
}
int main(void) {
	f1();
	printf("global_var:%d\n", global_var);
	f2();
	printf("global_var:%d\n", global_var);
}

int func(void) {
	return 1;
}
