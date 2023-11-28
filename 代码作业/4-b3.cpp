/*2152402 软件 段婷婷*/
#include<iostream>
#include<iomanip>
using namespace std;
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
	int year, month, week, days = 30, cur_day = 0, week_rem;

	while (1)
	{
		cout << "请输入年[1900-2100]、月"<<endl;
		cin >> year >> month;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		if (year < 1900 || year > 2100)
		{
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		if (month < 1 || month > 12)
		{
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		break;
	}
	bool is_leap = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		days = 31;
	if (month == 2)
		days = 28 + is_leap;
	//四年一闰，百年不闰，四百年一闰

	week = zeller(year, month, 1);
	week_rem = week;

	cout << endl;
	cout << year << "年" << month << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	while (cur_day < days)
	{
		for (int i = 0;i < week;++i)
			cout << "        ";
		for (int i = week;i <= 6;++i)
			if (cur_day < days)
				cout << setw(4) << (++cur_day) << "    ";
		week = 0;
		cout << endl;
	}
	if ((days - (7 - week_rem )) % 7 == 0)
		cout << endl;
	cout << endl;
	return 0;
}