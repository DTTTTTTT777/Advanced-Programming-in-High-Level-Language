/*2152402 ��� ������*/
#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;
int main()
{
	int a[1001], num = 0, count[101], rank = 0;
	cout << "������ɼ������1000��������-1����" << endl;
	for (int i = 1;i <= 1000;++i)
	{
		cin >> a[i];
		if (a[i] < 0)
			break;
		++num;
	}
	if (!num)
	{
		cout << "����Ч����" << endl;
		return 0;
	}
	cout << "���������Ϊ:" << endl;
	for (int i = 1;i <= num;++i)
	{
		cout << a[i] << " ";
		if (i % 10 == 0)
			cout << endl;
	}
	if (num % 10)
		cout << endl;

	for (int i = 0;i <= 100;++i)
		count[i] = 0;
	for (int i = 1;i <= num;++i)
		++count[a[i]];

	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
	for (int i = 100;i >= 0;--i)
		if (count[i])
		{
			++rank;
			for (int j = 1;j <= count[i];++j)
			{
				cout << i << " " << rank << endl;
			}
			rank += (count[i] - 1);
		}

	return 0;
}