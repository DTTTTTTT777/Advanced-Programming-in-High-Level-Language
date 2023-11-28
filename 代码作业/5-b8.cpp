/*2152402 软件 段婷婷*/
#include<iostream>
#include<cmath>
using namespace std;
int judge(double x1, double y1, double x2, double y2)
{
	int outc = x1 * y2 - x2 * y1;
	if (outc > 0)
		return 1;
	else if (outc < 0)
		return -1;
	else
		return 0;
}
double calc(double x1, double y1, double x2, double y2)
{
	double X = sqrt(x1 * x1 + y1 * y1), Y = sqrt(x2 * x2 + y2 * y2);
	double cosxy = (x1 * x2 + y1 * y2) / X / Y, sinxy = sqrt(1 - cosxy * cosxy);
	return X * Y * sinxy / 2.0;
}
int main()
{
	int n, type;
	double x[8], y[8], area = 0;
	while (1)
	{
		cout << "请输入多边形的顶点数量(4-7)" << endl;
		cin >> n;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		if (n >= 4 && n <= 7)
			break;
	}
	cout << "请按顺时针/逆时针方向输入" << n << "个顶点的x,y坐标：" << endl;
	for (int i = 0;i < n;++i)
	{
		while (1)
		{
			cout << "请输入第" << i + 1 << "个顶点的坐标：" << endl;
			cin >> x[i] >> y[i];
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			break;
		}
	}
	type = judge(x[n - 1] - x[1], y[n - 1] - y[1], x[0] - x[1], y[0] - y[1]);
	if (type * judge(x[n - 2] - x[0], y[n - 2] - y[0], x[n - 1] - x[0], y[n - 1] - y[0]) < 0)
	{
		cout << "不是凸" << n << "边形" << endl;
		return 0;
	}
	for (int i = 2;i < n;++i)
	{
		if (judge(x[i - 2] - x[i], y[i - 2] - y[i], x[i - 1] - x[i], y[i - 1] - y[i]) * type < 0)
		{
			cout << "不是凸" << n << "边形" << endl;
			return 0;
		}
		area += calc(x[i - 1] - x[0], y[i - 1] - y[0], x[i] - x[0], y[i] - y[0]);
	}
	cout << "凸" << n << "边形的面积=" << area << endl;
	return 0;
}
/*
* 7a
4a 5
4 5 x
2 4.0
2.22 2
4 0d
d
d 5 0
5 0
7 2
6.0 2.3

7a
4a 5
4 5 x
2 4.0
2.22 2
4 0d
d
d 5 0
5 0
7 2
6.0 4.4
*/