/*2152402 软件 段婷婷*/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	const double Pi = 3.14159;
	int a, b, w;

	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a >> b >> w;

	float s = 1.0 / 2 * a * b * sin(w * Pi / 180.0);
	cout << "三角形面积为 : ";
	cout << setiosflags(ios::fixed) << setprecision(3) << s << endl;

	return 0;
}