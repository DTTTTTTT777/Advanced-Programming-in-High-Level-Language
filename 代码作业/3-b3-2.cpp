/*2152402 ��� ������*/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	double x, tx;
	int y;

	cout << "������[0-100 ��)֮�������:" << endl;
	cin >> x;
	x += 0.001;

	y = int(x / 1000000000);
	cout << "ʮ��λ : " << y << endl;
	cout << "��λ   : " << int(x - y * 1000000000.0) / 100000000 << endl;
	y = int(x / 100000000);
	cout << "ǧ��λ : " << int(x - y * 100000000.0) / 10000000 << endl;
	y = int(x / 10000000);
	cout << "����λ : " << int(x - y * 10000000.0) / 1000000 << endl;
	y = int(x / 1000000);
	cout << "ʮ��λ : " << int(x - y * 1000000.0) / 100000 << endl;
	y = int(x / 100000);
	cout << "��λ   : " << int(x - y * 100000.0) / 10000 << endl;
	y = int(x / 10000);
	cout << "ǧλ   : " << int(x - y * 10000.0) / 1000 << endl;
	y = int(x / 1000);
	cout << "��λ   : " << int(x - y * 1000.0) / 100 << endl;
	y = int(x / 100);
	cout << "ʮλ   : " << int(x - y * 100.0) / 10 << endl;
	tx = x - y * 100.0;
	y = int(tx / 10);
	cout << "Բ     : " << int(tx - y * 10.0) << endl;
	tx -= int(tx);
	tx *= 10;
	cout << "��     : " << int(tx) << endl;
	tx -= int(tx);
	tx *= 10;
	cout << "��     : " << int(tx) << endl;

	return 0;
}