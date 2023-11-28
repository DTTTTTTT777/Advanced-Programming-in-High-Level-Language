/*2152402 软件 段婷婷*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

bool is_leap(int year)
{
	//四年一闰，百年不闰，四百年一闰
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
int calc(int month, int day, bool leap)
{
	int num[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (day<1 || day>num[month] + (month == 2 && leap))
		return 0;

	int ret = 0;
	for (int i = 1;i < month;++i)
		ret += num[i] + (i == 2 && leap);
	return ret + day;
}
int main()
{
	printf("请输入年，月，日\n");

	int year, month, day;
	int num[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	scanf("%d%d%d", &year, &month, &day);
	int leap = is_leap(year);

	if (month < 1 || month > 12)
		printf("输入错误-月份不正确\n");
	else 
	{
		int ans = calc(month, day, leap);
		if (!ans)
			printf("输入错误-日与月的关系非法\n");
		else
			printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, ans);
	}
	return 0;
}