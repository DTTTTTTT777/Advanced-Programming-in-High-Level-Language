/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() 
{
	const double Pi = 3.14159;
	double r, h;
	printf("������뾶�͸߶�\n");
	scanf("%lf%lf", &r, &h);

	printf("Բ�ܳ�     : %.2lf\n", 2 * Pi * r);
	printf("Բ���     : %.2lf\n", Pi * r * r);
	printf("Բ������ : %.2lf\n", 4 * Pi * r * r);
	printf("Բ�����   : %.2lf\n", 4.0 / 3 * Pi * r * r * r);
	printf("Բ�����   : %.2lf\n", Pi * r * r * h);

	return 0;
}