/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	double x, tx;
	int y;

	printf("������[0-100 ��)֮�������:\n");
	scanf("%lf", &x);
	x += 0.001;

	y = (int)(x / 1000000000);
	printf("ʮ��λ : %d\n",y);
	printf("��λ   : %d\n", (int)(x - y * 1000000000.0) / 100000000);
	y = (int)(x / 100000000);
	printf("ǧ��λ : %d\n", (int)(x - y * 100000000.0) / 10000000);
	y = (int)(x / 10000000);
	printf("����λ : %d\n", (int)(x - y * 10000000.0) / 1000000);
	y = (int)(x / 1000000);
	printf("ʮ��λ : %d\n", (int)(x - y * 1000000.0) / 100000);
	y = (int)(x / 100000);
	printf("��λ   : %d\n", (int)(x - y * 100000.0) / 10000);
	y = (int)(x / 10000);
	printf("ǧλ   : %d\n", (int)(x - y * 10000.0) / 1000);
	y = (int)(x / 1000);
	printf("��λ   : %d\n", (int)(x - y * 1000.0) / 100);
	y = (int)(x / 100);
	printf("ʮλ   : %d\n", (int)(x - y * 100.0) / 10);
	tx = x - y * 100.0;
	y = (int)(tx / 10);
	printf("Բ     : %d\n", (int)(tx - y * 10.0));
	tx -= (int)(tx);
	tx *= 10;
	printf("��     : %d\n", (int)(tx));
	tx -= (int)(tx);
	tx *= 10;
	printf("��     : %d\n", (int)(tx));

	return 0;
}