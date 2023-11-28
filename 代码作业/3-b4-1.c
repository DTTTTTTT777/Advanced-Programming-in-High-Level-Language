/*2152402 软件 段婷婷*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	const double Pi = 3.14159;
	int a, b, w;

	printf("请输入三角形的两边及其夹角(角度)\n");
	scanf("%d%d%d", &a, &b, &w);

	float s = 1.0 / 2 * a * b * sin(w * Pi / 180.0);
	printf("三角形面积为 : %.3f\n", s);
	
	return 0;
}