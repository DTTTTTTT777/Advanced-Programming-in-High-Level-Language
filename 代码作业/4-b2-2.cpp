/*2152402 ��� ������*/
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
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> year >> month >> day;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "�����������������" << endl;
			continue;
		}
		if (year < 1900 || year>2100)
		{
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		if (month < 1 || month>12)
		{
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}
		int days = 30;
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			days = 31;
		if (month == 2)
			days = 28 + ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
		if (day<1 || day>days)
		{
			cout << "�ղ���ȷ������������" << endl;
			continue;
		}
		break;
	}
	int week = zeller(year, month, day);
	if (week == 0)
		cout << "������" << endl;
	else if (week == 1)
		cout << "����һ" << endl;
	else if (week == 2)
		cout << "���ڶ�" << endl;
	else if (week == 3)
		cout << "������" << endl;
	else if (week == 4)
		cout << "������" << endl;
	else if (week == 5)
		cout << "������" << endl;
	else
		cout << "������" << endl;
	return 0;
}