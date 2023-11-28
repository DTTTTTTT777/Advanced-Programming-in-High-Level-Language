/*2152402 软件 段婷婷*/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	double x, tx;
	int y;

	cout << "请输入[0-100 亿)之间的数字:" << endl;
	cin >> x;
	x += 0.001;

	y = int(x / 1000000000);
	cout << "十亿位 : " << y << endl;
	cout << "亿位   : " << int(x - y * 1000000000.0) / 100000000 << endl;
	y = int(x / 100000000);
	cout << "千万位 : " << int(x - y * 100000000.0) / 10000000 << endl;
	y = int(x / 10000000);
	cout << "百万位 : " << int(x - y * 10000000.0) / 1000000 << endl;
	y = int(x / 1000000);
	cout << "十万位 : " << int(x - y * 1000000.0) / 100000 << endl;
	y = int(x / 100000);
	cout << "万位   : " << int(x - y * 100000.0) / 10000 << endl;
	y = int(x / 10000);
	cout << "千位   : " << int(x - y * 10000.0) / 1000 << endl;
	y = int(x / 1000);
	cout << "百位   : " << int(x - y * 1000.0) / 100 << endl;
	y = int(x / 100);
	cout << "十位   : " << int(x - y * 100.0) / 10 << endl;
	tx = x - y * 100.0;
	y = int(tx / 10);
	cout << "圆     : " << int(tx - y * 10.0) << endl;
	tx -= int(tx);
	tx *= 10;
	cout << "角     : " << int(tx) << endl;
	tx -= int(tx);
	tx *= 10;
	cout << "分     : " << int(tx) << endl;

	return 0;
}