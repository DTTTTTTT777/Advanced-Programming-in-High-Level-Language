/*2152402 ��� ������*/
//���������˵����ֺ�������Ҫ�ύ��
#include<iostream>
#include<conio.h>
#include<windows.h>
#include "cmd_console_tools.h"
#include "90-b2.h"
using namespace std;

int menu()
{
	cct_cls();
	cct_setconsoleborder(120, 40, 120, 9000);
	cct_setfontsize("��������", 20, 10);
	cout << "---------------------------------" << endl;
	cout << "1.�ڲ����飬������ɳ�ʼ5����" << endl;
	cout << "2.�ڲ����飬�������60%����Ѱ���ƶ�·��" << endl;
	cout << "3.�ڲ����飬������" << endl;
	cout << "4.����n*n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����" << endl;
	cout << "5.����n*n�Ŀ�ܣ��зָ��ߣ��������ʾ5����" << endl;
	cout << "6.n*n�Ŀ�ܣ�60%����֧����꣬���һ���ƶ�" << endl;
	cout << "7.cmdͼ�ν���������" << endl;
	cout << "0.�˳�" << endl;
	cout << "---------------------------------" << endl;
	cout << "[��ѡ��]: ";
	char c = _getch();
	while (c < '0' || c > '9')
		c = _getch();
	return c - '0';
}

int main()
{
	srand(unsigned(time(NULL)));
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1){
		int opt = menu();
		cout << opt << endl;
		Sleep(10);
		if (opt == 0)
			break;
		else if (opt == 1)
			sol_for_opt1();
		else if (opt == 2)
			sol_for_opt2();
		else if (opt == 3)
			basic_solution();
		else if (opt == 4)
			draw_for_opt4();
		else if (opt == 5)
			draw_for_opt5();
		else if (opt == 6)
			draw_for_opt6();
		else if (opt == 7)
			complete_solution();
	}
}