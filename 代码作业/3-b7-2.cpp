/*2152402 ��� ������*/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	double rmb;
	int tmp;
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;
	cout << "����������ֵ��" << endl;
	cin >> rmb;
	rmb += 0.001;

	tmp = int(rmb);

	t1 = tmp / 50;
	tmp -= t1 * 50;
	
	t2 = tmp / 20;
	tmp -= t2 * 20;

	t3 = tmp / 10;
	tmp -= t3 * 10;

	t4 = tmp / 5;
	tmp -= t4 * 5;

	t5 = tmp;

	tmp = rmb * 100 - int(rmb) * 100;

	t6 = tmp / 50;
	tmp -= t6 * 50;

	t7 = tmp / 10;
	tmp -= t7 * 10;

	t8 = tmp / 5;
	tmp -= t8 * 5;

	t9 = tmp / 2;
	tmp -= t9 * 2;

	t10 = tmp;

	cout << "��" << t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9 + t10 << "�����㣬�������£�" << endl;
	if (t1 != 0)
		cout << "50Ԫ : " << t1 << "��" << endl;
	if (t2 != 0)
		cout << "20Ԫ : " << t2 << "��" << endl;
	if (t3 != 0)
		cout << "10Ԫ : " << t3 << "��" << endl;
	if (t4 != 0)
		cout << "5Ԫ  : " << t4 << "��" << endl;
	if (t5 != 0)
		cout << "1Ԫ  : " << t5 << "��" << endl;
	if (t6 != 0)
		cout << "5��  : " << t6 << "��" << endl;
	if (t7 != 0)
		cout << "1��  : " << t7 << "��" << endl;
	if (t8 != 0)
		cout << "5��  : " << t8 << "��" << endl;
	if (t9 != 0)
		cout << "2��  : " << t9 << "��" << endl;
	if (t10 != 0)
		cout << "1��  : " << t10 << "��" << endl;

	return 0;
}