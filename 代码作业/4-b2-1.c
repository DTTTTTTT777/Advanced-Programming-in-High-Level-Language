/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int zeller(int y, int m, int d)
{
	if (m == 1 || m == 2)
	{
		--y;
		m += 12;
	}
	int c = y / 100;
	y = y % 100;
	int ret = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (ret < 0 || ret>6)
		ret = (ret + 7) % 7;
	return ret;
}
int main() {
	int year, month, day, ret;
	while (1)
	{
		printf("��������[1900-2100]���¡��գ�\n");
		ret = scanf("%d", &year);
		if (ret) ret = scanf("%d", &month);
		if (ret) ret = scanf("%d", &day);
		//ret = scanf("%d%d%d", &year, &month, &day);
		if (!ret)
		{
			rewind(stdin);
			printf("�����������������\n");
			continue;
		}
		if (year < 1900 || year>2100)
		{
			printf("��ݲ���ȷ������������\n");
			continue;
		}
		if (month < 1 || month>12)
		{
			printf("�·ݲ���ȷ������������\n");
			continue;
		}
		int days = 30;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			days = 31;
		if (month == 2)
			days = 28 + ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
		if (day<1 || day>days)
		{
			printf("�ղ���ȷ������������\n");
			continue;
		}
		break;
	}
	int week = zeller(year, month, day);
	if (week == 0)
		printf("������\n");
	else if (week == 1)
		printf("����һ\n");
	else if (week == 2)
		printf("���ڶ�\n");
	else if (week == 3)
		printf("������\n");
	else if (week == 4)
		printf("������\n");
	else if (week == 5)
		printf("������\n");
	else
		printf("������\n");
	return 0;
}