/*2152402 软件 段婷婷*/
#include<iostream>

using namespace std;

int main()
{
	int x;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> x;

	cout << "万位 : " << x / 10000 << endl;
	cout << "千位 : " << x % 10000 / 1000 << endl;
	cout << "百位 : " << x % 1000 / 100 << endl;
	cout << "十位 : " << x % 100 / 10 << endl;
	cout << "个位 : " << x % 10 << endl;

	return 0;
}