/*2152402 软件 段婷婷*/
#include <iostream>
#include <iomanip>
#include <cmath> 
using namespace std;
int main()
{
	int a[25], num = 0, x;
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
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
		cout << "无有效输入" << endl;
		return 0;
	}
	cout << "原数组为：" << endl;
	for (int i = 1;i <= num;++i)
		cout << a[i] << " ";
	cout << endl << "请输入要插入的正整数" << endl;
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
	cout << "插入后的数组为：" << endl;
	for (int i = 1;i <= num;++i)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}