#include <stdio.h>
#include <string.h>
typedef struct _info {
	char name[20];
	int age;
	float height;
}INFO;

#ifndef OPT
void printInfo(INFO d) {
	printf("%s, %d, %.1f\n", d.name, d.age, d.height);
}
#else
void printInfo(INFO *d) {
	printf("%s, %d, %.1f\n", d->name, d->age, d->height);
}
#endif

int main(void) {
	INFO data;
	strcpy(data.name, "kim");
	data.age = 22;
	data.height = 180.4F;

#ifndef OPT
	printInfo(data);
#else
	printInfo(&data);
#endif
}
