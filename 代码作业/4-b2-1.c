/*2152402 软件 段婷婷*/
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
		printf("请输入年[1900-2100]、月、日：\n");
		ret = scanf("%d", &year);
		if (ret) ret = scanf("%d", &month);
		if (ret) ret = scanf("%d", &day);
		//ret = scanf("%d%d%d", &year, &month, &day);
		if (!ret)
		{
			rewind(stdin);
			printf("输入错误，请重新输入\n");
			continue;
		}
		if (year < 1900 || year>2100)
		{
			printf("年份不正确，请重新输入\n");
			continue;
		}
		if (month < 1 || month>12)
		{
			printf("月份不正确，请重新输入\n");
			continue;
		}
		int days = 30;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			days = 31;
		if (month == 2)
			days = 28 + ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
		if (day<1 || day>days)
		{
			printf("日不正确，请重新输入\n");
			continue;
		}
		break;
	}
	int week = zeller(year, month, day);
	if (week == 0)
		printf("星期日\n");
	else if (week == 1)
		printf("星期一\n");
	else if (week == 2)
		printf("星期二\n");
	else if (week == 3)
		printf("星期三\n");
	else if (week == 4)
		printf("星期四\n");
	else if (week == 5)
		printf("星期五\n");
	else
		printf("星期六\n");
	return 0;
}