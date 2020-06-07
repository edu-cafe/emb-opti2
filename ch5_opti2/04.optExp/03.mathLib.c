#include <stdio.h>
#include <math.h>
#include <time.h>

double mathFunc1(int type, int d)
{
	double rst;
	if(type == 1) rst = sin(d);
	else rst = cos(d);
	return rst;
}
double mathFunc2(int type, int d)
{
	double rst;
	int t=0;
	
	double sin[] = {0, 0.85090, 1};
	double cos[] = {1, 0.85090, 0};
	if(d != 0) t = d/45;
	rst = (type == 1) ? sin[t] : cos[t];
	return rst;
}

int main(void)
{
	int menu, degree;
	unsigned long s_tick=0, e_tick=0;
	unsigned long dur1=0, dur2=0;
	double rst1=0, rst2=0;

	printf("Select(1.sin, 2:cos) => ");
	scanf("%d", &menu);
	printf("Degree(0|45|90)? ");
	scanf("%d", &degree);

	s_tick = clock();
	rst1 = mathFunc1(menu, degree);
	e_tick = clock();
	dur1 = e_tick - s_tick;

	s_tick = clock();
	rst2 = mathFunc2(menu, degree);
	e_tick = clock();
	dur2 = e_tick - s_tick;
	printf("rst1:%.5f, rst2:%.5f\n", rst1, rst2);
	printf("dur1:%lu, dur2:%lu\n", dur1, dur2);
	return 0;
}
