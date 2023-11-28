/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

bool is_leap(int year)
{
	//����һ�򣬰��겻���İ���һ��
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
	printf("�������꣬�£���\n");

	int year, month, day;
	int num[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	scanf("%d%d%d", &year, &month, &day);
	int leap = is_leap(year);

	if (month < 1 || month > 12)
		printf("�������-�·ݲ���ȷ\n");
	else 
	{
		int ans = calc(month, day, leap);
		if (!ans)
			printf("�������-�����µĹ�ϵ�Ƿ�\n");
		else
			printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, ans);
	}
	return 0;
}