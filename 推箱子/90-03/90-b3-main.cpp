/*2152402 ��� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include<io.h>
#include<string.h>
#include"cmd_console_tools.h"
#include"90-b3.h"

using namespace std;

int menu() //��ʾ���˵��������û�ѡ��
{
	cct_cls();
	cct_setconsoleborder(130, 48, 130, 48);
	cout << "------------------------------" << endl;
	cout << "1.��ʾ�ؿ�" << endl;
	cout << "0.�˳�" << endl;
	cout << "------------------------------" << endl;
	cout << "[��ѡ��0-1] ";
	char ch;
	while (1) {
		ch = _getch();
		if (ch == '0' || ch == '1')
			break;
	}
	cout << ch;
	return ch - '0';
}



int main()
{
	if (!open_stage()) {
		cout << "�޷���[.\stage\]Ŀ¼." << endl;
		return 0;
	}
	while (1) {
		if (menu() == 0)
			break;
		int ret = read_stage();
		if (ret != 1) {
			cct_cls();
			cct_gotoxy(0, 1);
			cout << "�޷��ҵ��κιؿ��ļ�";
            wait_for_end();
		}
        cct_gotoxy(0, 45);
        cout << "��С������������End����..";
	}
    cct_gotoxy(0, 40);
    return 0;
}