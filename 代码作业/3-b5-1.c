/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

int main()
{
	printf("�������꣬�£���\n");

	int year, month, day;
	int num[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	scanf("%d%d%d", &year, &month, &day);
	//����һ�򣬰��겻���İ���һ��
	int leap = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));

	if (month < 1 || month > 12)
	{
		printf("�������-�·ݲ���ȷ\n");
	}
	else {
		bool is_legal = 1;
		if (day < 1)
			is_legal = 0;
		if (month == 1 && day > 31)
			is_legal = 0;
		if (month == 2 && day > 28 + leap)
			is_legal = 0;
		if (month == 3 && day > 31)
			is_legal = 0;
		if (month == 4 && day > 30)
			is_legal = 0;
		if (month == 5 && day > 31)
			is_legal = 0;
		if (month == 6 && day > 30)
			is_legal = 0;
		if (month == 7 && day > 31)
			is_legal = 0;
		if (month == 8 && day > 31)
			is_legal = 0;
		if (month == 9 && day > 30)
			is_legal = 0;
		if (month == 10 && day > 31)
			is_legal = 0;
		if (month == 11 && day > 30)
			is_legal = 0;
		if (month == 12 && day > 31)
			is_legal = 0;
		if (!is_legal)
		{
			printf("�������-�����µĹ�ϵ�Ƿ�\n");
		}
		else
		{
			int ans = 0;
			if (month != 1)
			{
				ans += 31;
				if (month != 2)
				{
					ans += 28 + leap;
					if (month != 3)
					{
						ans += 31;
						if (month != 4)
						{
							ans += 30;
							if (month != 5)
							{
								ans += 31;
								if (month != 6)
								{
									ans += 30;
									if (month != 7)
									{
										ans += 31;
										if (month != 8)
										{
											ans += 31;
											if (month != 9)
											{
												ans += 30;
												if (month != 10)
												{
													ans += 31;
													if (month != 11)
													{
														ans += 30;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			ans += day;
			printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, ans);
		}
	}
	return 0;
}