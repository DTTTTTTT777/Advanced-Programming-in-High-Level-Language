/*2152402 软件 段婷婷*/
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int year, month, week, days = 30, cur_day=0, week_rem;

	cout << "请输入年份(2000-2030)和月份(1-12) : ";
	cin >> year >> month;
	while (!cin.good() || year < 2000 || year>2030 || month < 1 || month>12)
	{
		cout << "输入非法，请重新输入" << endl;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;
	}
	bool is_leap = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		days = 31;
	if (month == 2)
		days = 28 + is_leap;
	//四年一闰，百年不闰，四百年一闰

	cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
	cin >> week;
	while (!cin.good() || week < 0 || week>6)
	{
		cout << "输入非法，请重新输入" << endl;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> week;
	}
	week_rem = week;

	cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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
	if ((days - (7 - week_rem)) % 7 == 0)
		cout << endl;
	return 0;
}