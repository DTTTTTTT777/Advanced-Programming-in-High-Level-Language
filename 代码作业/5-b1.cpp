/*2152402 ��� ������*/
#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;
int main()
{
	int a[25], num = 0, x;
	cout << "��������������������������20��������-1����" << endl;
	for (int i = 1;i <= 20;++i)
	{
		cin >> a[i];
		if (a[i] < 0)
			break;
		++num;
	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	if (!num)
	{
		cout << "����Ч����" << endl;
		return 0;
	}
	cout << "ԭ����Ϊ��" << endl;
	for (int i = 1;i <= num;++i)
		cout << a[i] << " ";
	cout << endl << "������Ҫ�����������" << endl;
	cin >> x;
	a[num + 1] = INT_MAX;
	for (int i = 1;i <= num;++i)
	{
		if (a[i] <= x && a[i + 1] >= x)
		{
			for (int j = num;j >= i + 1;--j)
				a[j + 1] = a[j];
			a[i + 1] = x;
			++num;
			break;
		}
	}
	cout << "����������Ϊ��" << endl;
	for (int i = 1;i <= num;++i)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}