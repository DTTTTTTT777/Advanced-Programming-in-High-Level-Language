/*2152402 软件 段婷婷*/
#include<iostream>
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
	int year, month, day;
	while (1)
	{
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> year >> month >> day;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		if (year < 1900 || year>2100)
		{
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		if (month < 1 || month>12)
		{
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		int days = 30;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			days = 31;
		if (month == 2)
			days = 28 + ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
		if (day<1 || day>days)
		{
			cout << "日不正确，请重新输入" << endl;
			continue;
		}
		break;
	}
	int week = zeller(year, month, day);
	if (week == 0)
		cout << "星期日" << endl;
	else if (week == 1)
		cout << "星期一" << endl;
	else if (week == 2)
		cout << "星期二" << endl;
	else if (week == 3)
		cout << "星期三" << endl;
	else if (week == 4)
		cout << "星期四" << endl;
	else if (week == 5)
		cout << "星期五" << endl;
	else
		cout << "星期六" << endl;
	return 0;
}