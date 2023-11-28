/*2152402 软件 段婷婷*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() 
{
	const double Pi = 3.14159;
	double r, h;
	printf("请输入半径和高度\n");
	scanf("%lf%lf", &r, &h);

	printf("圆周长     : %.2lf\n", 2 * Pi * r);
	printf("圆面积     : %.2lf\n", Pi * r * r);
	printf("圆球表面积 : %.2lf\n", 4 * Pi * r * r);
	printf("圆球体积   : %.2lf\n", 4.0 / 3 * Pi * r * r * r);
	printf("圆柱体积   : %.2lf\n", Pi * r * r * h);

	return 0;
}