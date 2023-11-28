/*2152402 软件 段婷婷*/
#include<iostream>

using namespace std;

int main()
{
	cout << "请输入年，月，日" << endl;

	int year, month, day;

	cin >> year >> month >> day;
	//四年一闰，百年不闰，四百年一闰
	bool leap = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));

	if (month < 1 || month > 12)
	{
		cout << "输入错误-月份不正确" << endl;
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
			cout << "输入错误-日与月的关系非法" << endl;
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
			cout << year << "-" << month << "-" << day << "是" << year << "年的第" << ans << "天" << endl;
		}
	}
	return 0;
}