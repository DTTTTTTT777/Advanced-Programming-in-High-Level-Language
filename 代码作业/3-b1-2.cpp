/*2152402 ��� ������*/
#include<iostream>
#include<iomanip>

using namespace std;

int main() 
{
	const double Pi = 3.14159, width = 10;
	double r, h;

	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::left) << setiosflags(ios::fixed);

	cout << setw(width) << "Բ�ܳ�" << " : ";
	cout << setprecision(2) << 2 * Pi * r << endl;

	cout << setw(width) << "Բ���" << " : ";
	cout << setprecision(2) << Pi * r  * r << endl;

	cout << setw(width) << "Բ������" << " : ";
	cout << setprecision(2) << 4 * Pi * r * r << endl;

	cout << setw(width) << "Բ�����" << " : ";
	cout << setprecision(2) << 4.0 / 3 * Pi * r * r * r << endl;

	cout << setw(width) << "Բ�����" << " : ";
	cout << setprecision(2) << Pi * r * r * h << endl;

	return 0;
}