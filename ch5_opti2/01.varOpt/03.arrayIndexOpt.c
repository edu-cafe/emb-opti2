#include <stdio.h>
void f1(void) { printf("1...\n"); }
void f2(void) { printf("2...\n"); }
void f3(void) { printf("3...\n"); }
#ifndef OPT
int main(void) {
	int menu;
	while(1) {
		printf("Menu Select(1~3, 0:quit) => ");
		scanf("%d", &menu);
		if(menu == 0) break;
		switch(menu) {
			case 1:
				f1();	 break;
			case 2:
				f2();	 break;
			case 3:
				f3();	 break;
		}
	}
}
#else
int main(void) {
	int menu;
	void (*p[3])(void) = {f1, f2, f3};
	while(1) {
		printf("Menu Select(1~3, 0:quit) => ");
		scanf("%d", &menu);
		if(menu == 0) break;
		p[menu-1]();
	}
}
#endif
