/*2152402 ��� ������*/
#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int year, month, week, days = 30, cur_day=0, week_rem;

	cout << "���������(2000-2030)���·�(1-12) : ";
	cin >> year >> month;
	while (!cin.good() || year < 2000 || year>2030 || month < 1 || month>12)
	{
		cout << "����Ƿ�������������" << endl;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year >> month;
	}
	bool is_leap = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		days = 31;
	if (month == 2)
		days = 28 + is_leap;
	//����һ�򣬰��겻���İ���һ��

	cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : ";
	cin >> week;
	while (!cin.good() || week < 0 || week>6)
	{
		cout << "����Ƿ�������������" << endl;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> week;
	}
	week_rem = week;

	cout << endl;
	cout << year << "��" << month << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
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