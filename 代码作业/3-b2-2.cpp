/*2152402 ��� ������*/
#include<iostream>

using namespace std;

int main()
{
	int x;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> x;

	cout << "��λ : " << x / 10000 << endl;
	cout << "ǧλ : " << x % 10000 / 1000 << endl;
	cout << "��λ : " << x % 1000 / 100 << endl;
	cout << "ʮλ : " << x % 100 / 10 << endl;
	cout << "��λ : " << x % 10 << endl;

	return 0;
}