/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	const double Pi = 3.14159;
	int a, b, w;

	printf("�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d%d%d", &a, &b, &w);

	float s = 1.0 / 2 * a * b * sin(w * Pi / 180.0);
	printf("���������Ϊ : %.3f\n", s);
	
	return 0;
}