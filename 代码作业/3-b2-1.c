/*2152402 软件 段婷婷*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int x;
	printf("请输入一个[1..30000]间的整数:\n");
	scanf("%d", &x);

	printf("万位 : %d\n", x / 10000);
	printf("千位 : %d\n", x % 10000 / 1000);
	printf("百位 : %d\n", x % 1000 / 100);
	printf("十位 : %d\n", x % 100 / 10);
	printf("个位 : %d\n", x % 10);

	return 0;
}
