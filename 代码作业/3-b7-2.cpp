/*2152402 软件 段婷婷*/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	double rmb;
	int tmp;
	int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0, t10 = 0;
	cout << "请输入找零值：" << endl;
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

	cout << "共" << t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8 + t9 + t10 << "张找零，具体如下：" << endl;
	if (t1 != 0)
		cout << "50元 : " << t1 << "张" << endl;
	if (t2 != 0)
		cout << "20元 : " << t2 << "张" << endl;
	if (t3 != 0)
		cout << "10元 : " << t3 << "张" << endl;
	if (t4 != 0)
		cout << "5元  : " << t4 << "张" << endl;
	if (t5 != 0)
		cout << "1元  : " << t5 << "张" << endl;
	if (t6 != 0)
		cout << "5角  : " << t6 << "张" << endl;
	if (t7 != 0)
		cout << "1角  : " << t7 << "张" << endl;
	if (t8 != 0)
		cout << "5分  : " << t8 << "张" << endl;
	if (t9 != 0)
		cout << "2分  : " << t9 << "张" << endl;
	if (t10 != 0)
		cout << "1分  : " << t10 << "张" << endl;

	return 0;
}