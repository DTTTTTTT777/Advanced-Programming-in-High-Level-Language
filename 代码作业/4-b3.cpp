/*2152402 ��� ������*/
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
		cout << "��������[1900-2100]����"<<endl;
		cin >> year >> month;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�����������������" << endl;
			continue;
		}
		if (year < 1900 || year > 2100)
		{
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		if (month < 1 || month > 12)
		{
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}
		break;
	}
	bool is_leap = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		days = 31;
	if (month == 2)
		days = 28 + is_leap;
	//����һ�򣬰��겻���İ���һ��

	week = zeller(year, month, 1);
	week_rem = week;

	cout << endl;
	cout << year << "��" << month << "��" << endl;
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
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