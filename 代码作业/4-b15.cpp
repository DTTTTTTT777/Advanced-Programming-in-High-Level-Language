/*2152402 软件 段婷婷*/
#include <iostream>
#define inf 2147483647
using namespace std;
int min(int x, int y, int z = INT_MAX, int t = INT_MAX)
{
	if (x <= y && x <= z && x <= t)
		return x;
	if (y <= x && y <= z && y <= t)
		return y;
	if (z <= x && z <= y && z <= t)
		return z;
	return t;
}
int main()
{
	int num, x1 = 1, x2 = 1, x3 = 1, x4 = 1;
	while (1)
	{
		x1 = 1, x2 = 1, x3 = 1, x4 = 1;
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		if (num < 2 || num>4)
		{
			cout << "个数输入错误" << endl;
			return 0;
		}
		if (num == 2)
			cin >> x1 >> x2;
		else if (num == 3)
			cin >> x1 >> x2 >> x3;
		else if (num == 4)
			cin >> x1 >> x2 >> x3 >> x4;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		if (x1 <= 0 || x2 <= 0 || x3 <= 0 || x4 <= 0)
		{
			continue;
		}
		break;
	}
	cout << "min=";
	if (num == 2)
		cout << min(x1, x2);
	else if (num == 3)
		cout << min(x1, x2, x3);
	else if (num == 4)
		cout << min(x1, x2, x3, x4);
	cout << endl;
	return 0;
}