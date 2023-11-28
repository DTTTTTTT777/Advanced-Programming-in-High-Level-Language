/*2152402 软件 段婷婷*/
#include<iostream>
#include<iomanip>

using namespace std;

int main() 
{
	const double Pi = 3.14159, width = 10;
	double r, h;

	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::left) << setiosflags(ios::fixed);

	cout << setw(width) << "圆周长" << " : ";
	cout << setprecision(2) << 2 * Pi * r << endl;

	cout << setw(width) << "圆面积" << " : ";
	cout << setprecision(2) << Pi * r  * r << endl;

	cout << setw(width) << "圆球表面积" << " : ";
	cout << setprecision(2) << 4 * Pi * r * r << endl;

	cout << setw(width) << "圆球体积" << " : ";
	cout << setprecision(2) << 4.0 / 3 * Pi * r * r * r << endl;

	cout << setw(width) << "圆柱体积" << " : ";
	cout << setprecision(2) << Pi * r * r * h << endl;

	return 0;
}