#include <stdio.h>
#include <string.h>

typedef struct _info {
	char name[20];
	int age;
	float height;
}INFO;

typedef struct _classInfo {
	INFO *st;
	int classNo;
}CLASS_INFO;

#ifndef OPT
void setInfo(CLASS_INFO *d) {
	char n[20] = "kim";
	int a = 21;
	float h = 171.1F;
	for(int i=1; i<=20; i++) {
		strcpy(d->st->name, n);
		d->st->age = a;
		d->st->height = h;
	}
}
#else
void setInfo(CLASS_INFO *d) {
	INFO *t = d->st;
	char n[20] = "kim";
	int a = 21;
	float h = 171.1F;
	for(int i=1; i<=20; i++) {
		strcpy(t->name, n);
		t->age = a;
		t->height = h;
	}
}
#endif

int main(void) {
	INFO p_data;
	CLASS_INFO data = {&p_data, 1};
	setInfo(&data);
	printf("%s, %d, %.1f\n", data.st->name, data.st->age, data.st->height);
}

//$ gcc -std=c99 -g -O1 
