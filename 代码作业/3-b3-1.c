/*2152402 软件 段婷婷*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double x, tx;
	int y;

	printf("请输入[0-100 亿)之间的数字:\n");
	scanf("%lf", &x);
	x += 0.001;

	y = (int)(x / 1000000000);
	printf("十亿位 : %d\n",y);
	printf("亿位   : %d\n", (int)(x - y * 1000000000.0) / 100000000);
	y = (int)(x / 100000000);
	printf("千万位 : %d\n", (int)(x - y * 100000000.0) / 10000000);
	y = (int)(x / 10000000);
	printf("百万位 : %d\n", (int)(x - y * 10000000.0) / 1000000);
	y = (int)(x / 1000000);
	printf("十万位 : %d\n", (int)(x - y * 1000000.0) / 100000);
	y = (int)(x / 100000);
	printf("万位   : %d\n", (int)(x - y * 100000.0) / 10000);
	y = (int)(x / 10000);
	printf("千位   : %d\n", (int)(x - y * 10000.0) / 1000);
	y = (int)(x / 1000);
	printf("百位   : %d\n", (int)(x - y * 1000.0) / 100);
	y = (int)(x / 100);
	printf("十位   : %d\n", (int)(x - y * 100.0) / 10);
	tx = x - y * 100.0;
	y = (int)(tx / 10);
	printf("圆     : %d\n", (int)(tx - y * 10.0));
	tx -= (int)(tx);
	tx *= 10;
	printf("角     : %d\n", (int)(tx));
	tx -= (int)(tx);
	tx *= 10;
	printf("分     : %d\n", (int)(tx));

	return 0;
}