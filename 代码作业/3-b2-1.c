/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int x;
	printf("������һ��[1..30000]�������:\n");
	scanf("%d", &x);

	printf("��λ : %d\n", x / 10000);
	printf("ǧλ : %d\n", x % 10000 / 1000);
	printf("��λ : %d\n", x % 1000 / 100);
	printf("ʮλ : %d\n", x % 100 / 10);
	printf("��λ : %d\n", x % 10);

	return 0;
}
