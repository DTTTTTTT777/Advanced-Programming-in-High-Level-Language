/*2152402 ��� ������*/
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() 
{
	while (1) 
	{
		cout << "������ x ��ֵ[-10 ~ +65]" << endl;
		int x;
		cin >> x;
		if (x < -10 || x > 65)
		{
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		int n = 1;
		double caln = 1, calx=x;
		double ans = 1;
		while (fabs(1.0 * calx / caln) >= 1e-6)
		{
			ans += 1.0 * calx / caln;
			caln *= (++n);
			calx *= x;
		}
		cout << "e^" << x << "=";
		cout << setprecision(10) << ans << endl;
		break;
	}
	return 0;
}