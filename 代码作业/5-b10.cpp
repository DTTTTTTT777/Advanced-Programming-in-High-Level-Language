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
int is_leap(int year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
int main()
{
	system("mode con cols=120 lines=46");
	cout << "请输入年份[1900-2100]" << endl;
	int year, day[3], cur_max_days[3], max_days[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	cin >> year;
	max_days[2] += is_leap(year);

	cout << year << "年的日历:" << endl << endl;

	for (int k = 0;k < 4;++k)
	{
		int begin_month = k * 3 + 1;
		for (int i = begin_month;i < begin_month + 3;++i)
		{
			cout << setw(11) << " " << setw(2) << setiosflags(ios::right) << i << "月";
			if (i < begin_month + 2)
				cout << setw(17) << " ";
		}
		cout << endl;
		cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat";
		cout << endl;
		day[0] = day[1] = day[2] = 1;

		bool is_end[3] = { 0,0,0 };
		while(1)
		{
			for (int month = begin_month;month < begin_month + 3;++month)
			{
				int num = month - begin_month;
				for (int week = 0;week < 7;++week)
				{
					if (zeller(year, month, day[num]) != week || day[num] > max_days[month])
						cout << setw(4) << " ";
					else
						cout << setw(4) << resetiosflags(ios::right) << setiosflags(ios::left) << day[num]++;
				}
				if (num < 2)
					cout << setw(4) << " ";
				if (day[num] > max_days[month])
					is_end[num] = 1;
			}
			cout << endl;
			if (is_end[0] && is_end[1] && is_end[2])
				break;
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}