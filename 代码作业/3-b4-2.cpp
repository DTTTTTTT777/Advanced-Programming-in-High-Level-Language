/*2152402 ��� ������*/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	const double Pi = 3.14159;
	int a, b, w;

	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a >> b >> w;

	float s = 1.0 / 2 * a * b * sin(w * Pi / 180.0);
	cout << "���������Ϊ : ";
	cout << setiosflags(ios::fixed) << setprecision(3) << s << endl;

	return 0;
}