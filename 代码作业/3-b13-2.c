/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int main() {
	int year, month, week, days = 30, cur_day = 0, ret, week_rem;

	printf("���������(2000-2030)���·�(1-12) : ");
	ret = scanf("%d", &year);
	if (ret) ret=scanf("%d", &month);
	while (!ret || year < 2000 || year>2030 || month < 1 || month>12)
	{
		//printf("year=%d month=%d ret=%d\n", year, month, ret);
		printf("����Ƿ�������������\n");
		if (!ret)
		{
			rewind(stdin);
			ret = 1;
		}
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d", &year);
		if (ret) ret = scanf("%d", &month);
	}
	bool is_leap = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		days = 31;
	if (month == 2)
		days = 28 + is_leap;
	//����һ�򣬰��겻���İ���һ��

	printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", year, month);
	ret = scanf("%d", &week);
	while (!ret || week < 0 || week>6)
	{
		printf("����Ƿ�������������\n");
		if (!ret)
		{
			rewind(stdin);
			ret = 1;
		}
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", year, month);
		ret = scanf("%d", &week);
	}
	week_rem = week;

	printf("\n%d��%d�µ�����Ϊ:\n", year, month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
	while (cur_day < days)
	{
		for (int i = 0;i < week;++i)
			printf("        ");
		for (int i = week;i <= 6;++i)
			if (cur_day < days)
				printf("%4d    ", (++cur_day));
		week = 0;
		printf("\n");
	}
	if ((days - (7 - week_rem)) % 7 == 0)
		printf("\n");
	return 0;
}